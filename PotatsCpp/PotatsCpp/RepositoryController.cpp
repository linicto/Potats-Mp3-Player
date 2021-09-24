#include "pch.h"
#include "RepositoryController.h"

#include <filesystem>

RepositoryController::RepositoryController()
    :sourceFileRepository_(std::filesystem::path{ "E:\\" }),
    musicCollectionRepository_()
{
}

RepositoryController& RepositoryController::getInstance()
{
    static RepositoryController instance;
    return instance;
}
