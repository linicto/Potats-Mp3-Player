#pragma once

#include <list>
#include <string>

#include "MusicFile.h"
#include "TagFilePlaceholder.h"

struct Album
{
    std::list<MusicFile> SongList;
    std::string Title;
    std::list<std::string> Artits;
    std::list<std::string> Genre;
    std::list<std::byte> Cover;

    Album(TagFilePlaceholder tagFile);
};

//In C#, this function was a static method within a class.
//Truly this, is more of an helper function. In C++ we can declare functions outside of a class.
//This function makes more sense outside the struct Album than inside it.
std::list<std::byte> CreateThumbnail(std::list<std::byte> PassedImage, int LargestSize);

//Important! This is required for the Album struct to be used in a std::set.
inline bool operator<(const Album& lhs, const Album& rhs)
{
    return lhs.Title < rhs.Title;
}
