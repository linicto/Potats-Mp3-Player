#pragma once

#include <filesystem>
#include <list>
#include <string>

#include "SourceFileRepository.h"

class MusicFileExtractor
{
private:
    SourceFileRepository sourceFileRepository_;
    std::string mp3Extension_;
    std::list<std::string> acceptedFileExtensions_;

public:
    std::list<std::filesystem::path> getAllMusicFiles();

private:
    std::list<std::filesystem::path> buildAListOfPotentialFoldersWithMusic();
    std::list<std::filesystem::path> extractMusicFiles();
    std::list<std::filesystem::path> getAllSubDirectories(std::filesystem::path directory);
    std::list<std::filesystem::path> getAllSupportedFiles(std::filesystem::path directory);
};

