#pragma once

#include <filesystem>
#include <list>
#include <set>
#include <string>

#include "SourceFileRepository.h"

class MusicFileExtractor
{
private:
    SourceFileRepository sourceFileRepository_;
    std::string mp3Extension_;
    std::list<std::string> acceptedFileExtensions_;

public:
    MusicFileExtractor();
    std::set<std::filesystem::path> getAllMusicFiles();

private:
    std::set<std::filesystem::path> buildAListOfPotentialDirectoriesWithMusic();
    std::set<std::filesystem::path> extractMusicFiles(std::set<std::filesystem::path> directories);
};

