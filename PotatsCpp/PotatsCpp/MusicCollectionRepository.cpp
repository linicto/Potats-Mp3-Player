#include "pch.h"
#include "MusicCollectionRepository.h"

#include <algorithm>

MusicCollectionRepository::MusicCollectionRepository()
    :albumCollection_()
{}

void MusicCollectionRepository::AddEntry(std::filesystem::path mp3FilePath)
{
    auto musicFile = MusicFile(mp3FilePath);

    auto album = GetAlbumByTitle(musicFile.AlbumTitle);

    if (!album.has_value())
    {
        InitializeNewAlbum(mp3FilePath);
    }
    else
    {
        album.value().get().SongList.push_back(musicFile);
        albumCollection_.insert_or_assign(album.value().get().Title, album.value());
    }
}

std::optional<std::reference_wrapper<Album>> MusicCollectionRepository::GetAlbumByTitle(std::string title)
{
    std::optional<std::reference_wrapper<Album>> album;

    if (albumCollection_.contains(title))
    {
        return std::optional{ std::reference_wrapper<Album>{albumCollection_.at(title) } };
    }

    return std::nullopt;
}

MusicFile MusicCollectionRepository::ConvertToMusicFile(std::filesystem::path musicPath)
{
    return MusicFile(musicPath);
}

const std::map<std::string, Album>& MusicCollectionRepository::GetReadonlyAlbumCollection() const
{
    return albumCollection_;
}

void MusicCollectionRepository::InitializeNewAlbum(std::filesystem::path mp3FilePath)
{
    auto album = Album(mp3FilePath);
    auto musicFile = MusicFile(mp3FilePath);

    album.SongList.push_back(musicFile);

    albumCollection_.insert_or_assign(album.Title, album);
}
