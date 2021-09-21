#pragma once

#include <chrono>
#include <filesystem>
#include <list>
#include <string>

#include "TagFilePlaceholder.h"

struct MusicFile
{
    std::filesystem::path Path;
    std::string AlbumTitle;
    std::string SongTitle;
    std::list<std::string> SongArtist;
    std::chrono::years Year;
    int Disk;
    int Track;
    std::chrono::seconds Duration;

    MusicFile(std::filesystem::path Path);

    MusicFile(TagFilePlaceholder tagFile); //TODO find how to get file title etc... from std::filesystem
};

