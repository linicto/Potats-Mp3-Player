#pragma once

#include <filesystem>

//Important! No concept of interfaces in C++, so we use an abstract class instead.
class IRepositoryController
{
public:
    virtual void AddEntry(std::filesystem::path entry) = 0;
    //Important! not translated since they were only called by tests in the original C# implementation.
    //virtual void RemoveAllEntries() = 0;
    //virtual void CreateNewRepository() = 0;
    //virtual void RemoveEntry(std::string entry) = 0;
};