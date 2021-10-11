#include "pch.h"
#include "SourceFileRepository.h"

#include <fstream>
#include <iterator>
#include <ranges>
#include <string_view>

#include <boost/log/trivial.hpp>

SourceFileRepository::SourceFileRepository(std::filesystem::path filePath)
    :filePath_(filePath)
{
    BOOST_LOG_TRIVIAL(trace) << "SourceFileRepository constructor : " << filePath;
    InitializeRepository();
}

void SourceFileRepository::InitializeRepository()
{
    if (!std::filesystem::exists(filePath_))
    {
        BOOST_LOG_TRIVIAL(trace) << "SourceFileRepository::InitializeRepository - creating source file since it does not exist.";
        std::filesystem::create_directory(filePath_.parent_path());
        std::ofstream output(filePath_);
        output.close();
    }

    DeserializeSourceDirectories();
}

void SourceFileRepository::SerializeSourceDirectories()
{
    BOOST_LOG_TRIVIAL(trace) << "SourceFileRepository::SerializeSourceDirectories";

    std::filesystem::create_directory(filePath_.parent_path());
    std::ofstream output(filePath_);

    auto writer = [&output](std::filesystem::path path) {output << path << '\n'; };

    std::for_each(sourceDirectories_.begin(), sourceDirectories_.end(), writer);

    output.close();
}

void SourceFileRepository::DeserializeSourceDirectories()
{
    BOOST_LOG_TRIVIAL(trace) << "SourceFileRepository::DeserializeSourceDirectories - filePath_ : " << filePath_;

    std::ifstream input(filePath_);
    std::string inputData(std::istreambuf_iterator<char>{input}, {});

    std::string_view allData(inputData);
    BOOST_LOG_TRIVIAL(trace) << "SourceFileRepository::DeserializeSourceDirectories - file content : " << allData;

    std::string_view delim{"\n"};

    auto processing = [this](const auto & view)
    {
        auto pathAsString = std::string_view(&*view.begin(), std::ranges::distance(view));

        std::filesystem::path path{pathAsString};

        if (!path.empty())
        {
            BOOST_LOG_TRIVIAL(trace) << "SourceFileRepository::DeserializeSourceDirectories - Adding path : " << path;
            sourceDirectories_.insert(path);
        }
    };

    sourceDirectories_.clear();

    std::ranges::for_each(allData | std::views::split(delim), processing);
}

void SourceFileRepository::AddEntry(std::filesystem::path filePath)
{
    if (!sourceDirectories_.contains(filePath))
    {
        sourceDirectories_.insert(filePath);
    }
}

void SourceFileRepository::SaveFile()
{
    SerializeSourceDirectories();
}
