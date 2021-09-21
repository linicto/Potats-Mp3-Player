#pragma once
#include "IRepositoryController.h"

#include <filesystem>
#include <list>

class SourceFileRepository : public IRepositoryController
{
private:
    std::list<std::filesystem::path> sourceDirectories_;
    std::filesystem::path filePath_;

public:
    SourceFileRepository(std::filesystem::path filePath);
    void AddEntry(std::filesystem::path filePath);

private:
    void InitializeRepository();
    std::list<std::filesystem::path> DeserializeSourceDirectories();
};

