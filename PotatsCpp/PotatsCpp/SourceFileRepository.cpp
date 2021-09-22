#include "pch.h"
#include "SourceFileRepository.h"

#include <fstream>
#include <iterator>

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

    sourceDirectories_ = DeserializeSourceDirectories();
}

std::set<std::filesystem::path> SourceFileRepository::DeserializeSourceDirectories()
{
    std::ifstream input(filePath_);
    std::string inputData(std::istreambuf_iterator<char>{input}, {});

    std::set<std::filesystem::path> paths;

    std::filesystem::path path(inputData);

    if (!path.empty())
    {
        paths.insert(path);
    }

    return paths;
}

void SourceFileRepository::AddEntry(std::filesystem::path filePath)
{
    if (!sourceDirectories_.contains(filePath))
    {
        sourceDirectories_.insert(filePath);
    }
}
