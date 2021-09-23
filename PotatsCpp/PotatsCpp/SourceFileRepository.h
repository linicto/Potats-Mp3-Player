#pragma once
#include "IRepositoryController.h"

#include <filesystem>
#include <set>
#include <string>

class SourceFileRepository : public IRepositoryController
{
private:
    std::set<std::filesystem::path> sourceDirectories_;
    std::filesystem::path filePath_;

public:
    SourceFileRepository(std::filesystem::path filePath);
    void AddEntry(std::filesystem::path filePath);
    void SaveFile();

private:
    void InitializeRepository();
    void SerializeSourceDirectories();
    void DeserializeSourceDirectories();
};

