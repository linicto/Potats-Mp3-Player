#pragma once

#include <filesystem>
#include <list>
#include <string>

#include "MusicFile.h"

struct TagFilePlaceholder
{
    std::string AlbumTitle{ "Album Title Placeholder" };
    std::string Title{ "Song Title Placeholder" };
    std::list<std::string> Artists{ "Artist Placeholder1", "Artist Placeholder2" };
    std::list<std::string> Genres{ "Genre Placeholder1", "Genre Placeholder2" };
    std::list<std::byte> Cover{ 0 };
    std::filesystem::path Name{ "E:\\temp\\" };
    std::chrono::time_point<std::chrono::system_clock> Year{ std::chrono::system_clock::now() };
    int Disk{ 1 };
    int Track{ 2 };
    std::chrono::duration<std::chrono::system_clock> Duration{std::chrono::seconds(3)};
};

