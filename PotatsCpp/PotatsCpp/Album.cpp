#include "pch.h"
#include "Album.h"

Album::Album(std::filesystem::path mp3FileEntry)
    :Title{ mp3FileEntry.parent_path().filename().string()}
{
    auto tagFile = TagFilePlaceholder();
    Artits = tagFile.Artists;
    Genre = tagFile.Genres;
    Cover = tagFile.Cover;
}

std::list<std::byte> CreateThumbnail(std::list<std::byte> PassedImage, int LargestSize)
{
    //TODO find a way to implement Create Thumbnail
    //TODO find a way to implement ResizeImage
    std::list<std::byte> placeholder{ static_cast<std::byte>(0), static_cast<std::byte>(2) };
    return placeholder;
}