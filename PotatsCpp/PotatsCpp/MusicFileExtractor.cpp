#include "pch.h"
#include "MusicFileExtractor.h"

#include "RepositoryController.h"

#include <boost/log/trivial.hpp>

/// <summary>
/// Function to get all sub directories of a directory to scan.
/// Warning! I'm not checking I really get a directory to scan!
/// Warning! This function is recursive it might not like Windows Junctions :P
/// </summary>
/// <param name="directoryToScan">directory within which we'll find all directories</param>
/// <returns>the set of all sub directories</returns>
std::set<std::filesystem::path> getAllSubDirectories(std::filesystem::path directoryToScan)
{
    BOOST_LOG_TRIVIAL(trace) << "getAllSubDirectories : " << directoryToScan;

    std::set<std::filesystem::path> foundDirectories;

    for (const auto& entry : std::filesystem::directory_iterator(directoryToScan))
    {
        if (entry.is_directory()) {
            foundDirectories.insert(entry);

            auto foundSubDirectories = getAllSubDirectories(entry);
            foundDirectories.insert(foundSubDirectories.begin(), foundSubDirectories.end());
        }
    }

    return foundDirectories;
}

/// <summary>
/// Warning! Also a recursive function!
/// </summary>
/// <param name="directoryToScan"></param>
/// <returns></returns>
std::set<std::filesystem::path> getAllSupportedFiles(std::filesystem::path directoryToScan)
{
    std::set<std::filesystem::path> foundFiles;

    for (const auto& entry : std::filesystem::directory_iterator(directoryToScan))
    {
        const auto filenameString = entry.path().filename().string();

        const auto mp3Position = filenameString.find(".mp3");

        if (entry.is_regular_file() && mp3Position != std::string::npos) {
            foundFiles.insert(entry);
        }
        else if(entry.is_directory()) {
            auto foundFiles = getAllSupportedFiles(entry);
            foundFiles.insert(foundFiles.begin(), foundFiles.end());
        }
    }

    return foundFiles;
}

MusicFileExtractor::MusicFileExtractor()
    :sourceFileRepository_(RepositoryController::getInstance().sourceFileRepository_),
    mp3Extension_(".mp3")
{
    acceptedFileExtensions_.push_back(mp3Extension_);
}

std::set<std::filesystem::path> MusicFileExtractor::getAllMusicFiles()
{
    auto subDirectories = buildAListOfPotentialDirectoriesWithMusic();
    auto extractedMusicFiles = extractMusicFiles(subDirectories);
    return extractedMusicFiles;
}

std::set<std::filesystem::path> MusicFileExtractor::buildAListOfPotentialDirectoriesWithMusic()
{
    std::set<std::filesystem::path> directoriesThatMayContainMusic;

    for (auto directory : sourceFileRepository_.sourceDirectories_)
    {
        directoriesThatMayContainMusic.insert(directory);

        auto subDirectories = getAllSubDirectories(directory);

        directoriesThatMayContainMusic.insert(subDirectories.begin(), subDirectories.end());
    }

    return directoriesThatMayContainMusic;
}

std::set<std::filesystem::path> MusicFileExtractor::extractMusicFiles(std::set<std::filesystem::path> directories)
{
    std::set<std::filesystem::path> musicFilesPaths;

    for (const auto& directory : directories)
    {
        auto musicFilesPathsInDirectory = getAllSupportedFiles(directory);
        musicFilesPaths.insert(musicFilesPathsInDirectory.begin(), musicFilesPathsInDirectory.end());
    }

    return musicFilesPaths;
}
