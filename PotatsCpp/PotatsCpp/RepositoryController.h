#pragma once

#include "SourceFileRepository.h"
#include "MusicCollectionRepository.h"

struct RepositoryController
{
public:
    SourceFileRepository sourceFileRepository_;
    MusicCollectionRepository musicCollectionRepository_;

public:
    static RepositoryController& getInstance();

private:
    RepositoryController();

public:
    //we need to delete the two next methods to be sure this singleton is not copied.
    //also these deleted methods should be public for better compiler errors - Scott Meyers Effective Modern C++.
    RepositoryController(const RepositoryController &) = delete;
    void operator=(const RepositoryController &) = delete;

};

