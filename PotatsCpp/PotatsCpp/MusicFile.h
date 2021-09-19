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
    std::chrono::time_point<std::chrono::system_clock> Year;
    int Disk;
    int Track;
    std::chrono::duration<std::chrono::system_clock> Duration;

    MusicFile(std::filesystem::path Path);

    MusicFile(TagFilePlaceholder musicFile) //TODO find how to get file title etc... from std::filesystem
};

