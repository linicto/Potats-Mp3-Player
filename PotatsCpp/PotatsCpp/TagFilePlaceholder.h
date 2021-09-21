#pragma once

#include <filesystem>
#include <list>
#include <string>

struct TagFilePlaceholder
{
    std::string AlbumTitle{ "Album Title Placeholder" };
    std::string Title{ "Song Title Placeholder" };
    std::list<std::string> Artists{ "Artist Placeholder1", "Artist Placeholder2" };
    std::list<std::string> Genres{ "Genre Placeholder1", "Genre Placeholder2" };
    std::list<std::byte> Cover{ 0 };
    std::filesystem::path Name{ "E:\\temp\\" };
    std::chrono::years Year{ 2020 };
    int Disk{ 1 };
    int Track{ 2 };
    std::chrono::seconds Duration{ 3 };
};

