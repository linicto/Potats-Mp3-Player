#include "pch.h"
#include "RepositoryController.h"

#include <filesystem>
#include <boost/log/trivial.hpp>

RepositoryController::RepositoryController()
    :sourceFileRepository_(std::filesystem::path{ ".\\sourceFileRepository\\sourceFile.txt" }),
    musicCollectionRepository_()//this was taken from the original C# potats, not sure what was the intent, but since it was a fast rewrite to C++, I didn't spend much time understanding.
{
    BOOST_LOG_TRIVIAL(trace) << "RepositoryController Created";
}

RepositoryController& RepositoryController::getInstance()
{
    static RepositoryController instance;

    auto setPrinter = [](std::set<std::filesystem::path> setToPrint) {
        for (auto entry : setToPrint)
        {
            BOOST_LOG_TRIVIAL(trace) << entry;
        }
    };

    BOOST_LOG_TRIVIAL(trace) << "RepositoryController instance returned. SourceDirectories size : " << instance.sourceFileRepository_.sourceDirectories_.size();

    setPrinter(instance.sourceFileRepository_.sourceDirectories_);

    return instance;
}
