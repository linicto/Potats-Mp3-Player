#include "pch.h"
#include "SourceFileRepository.h"

#include <fstream>
#include <iterator>
#include <ranges>
#include <string_view>

SourceFileRepository::SourceFileRepository(std::filesystem::path filePath)
    :filePath_(filePath)
{
    InitializeRepository();
}

void SourceFileRepository::InitializeRepository()
{
    if (!std::filesystem::exists(filePath_))
    {
        std::filesystem::create_directory(filePath_.parent_path());
        std::ofstream output(filePath_);
        output.close();
    }

    DeserializeSourceDirectories();
}

void SourceFileRepository::SerializeSourceDirectories()
{
    std::filesystem::create_directory(filePath_.parent_path());
    std::ofstream output(filePath_);

    auto writer = [&output](std::filesystem::path path) {output << path << '\n'; };

    std::for_each(sourceDirectories_.begin(), sourceDirectories_.end(), writer);

    output.close();
}

void SourceFileRepository::DeserializeSourceDirectories()
{
    std::ifstream input(filePath_);
    std::string inputData(std::istreambuf_iterator<char>{input}, {});

    std::string_view allData(inputData);

    std::string_view delim{"\n"};

    auto processing = [this](const auto & view)
    {
        auto pathAsString = std::string_view(&*view.begin(), std::ranges::distance(view));

        std::filesystem::path path{pathAsString};

        if (!path.empty())
        {
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
