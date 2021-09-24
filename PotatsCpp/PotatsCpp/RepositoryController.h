#pragma once

#include "SourceFileRepository.h"
#include "MusicCollectionRepository.h"

struct RepositoryController//this was originally a class, but since I had no use for a class in this rewrite, I used a struct
{
public:
    SourceFileRepository sourceFileRepository_;
    MusicCollectionRepository musicCollectionRepository_;//these two attributes originally had a getter, but since it's a fast rewrite, I decided to skip the getter and use them directly.

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

