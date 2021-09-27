#include "pch.h"
#include "RepositoryController.h"

#include <filesystem>

RepositoryController::RepositoryController()
    :sourceFileRepository_(std::filesystem::path{ ".\\sourceFileRepository\\sourceFile.txt" }),
    musicCollectionRepository_()//this was taken from the original C# potats, not sure what was the intent, but since it was a fast rewrite to C++, I didn't spend much time understanding.
{
}

RepositoryController& RepositoryController::getInstance()
{
    static RepositoryController instance;
    return instance;
}
