#pragma once

#include <string>

//No concept of interfaces in C++, so we use an abstract class instead.
class IRepositoryController
{
public:
    virtual void CreateNewRepository() = 0;
    virtual void AddEntry(std::string entry) = 0;
    virtual void RemoveEntry(std::string entry) = 0;
    virtual void RemoveAllEntries() = 0;
};