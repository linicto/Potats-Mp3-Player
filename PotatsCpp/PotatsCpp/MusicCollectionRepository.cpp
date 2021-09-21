#include "pch.h"
#include "MusicCollectionRepository.h"

#include <algorithm>

MusicCollectionRepository::MusicCollectionRepository()
    :albumCollection_()
{}

/*void MusicCollectionRepository::CreateNewRepository()
{
    albumCollection_ = std::set<Album>();
    //Important! another way to do this would be to empty the set with the following
    //albumCollection_.clear();
}*/

void MusicCollectionRepository::AddEntry(std::filesystem::path entry)
{
    //TODO find a way to replace the TagFilePlaceholder and to read the actual file.
    auto tagFile = TagFilePlaceholder();

    auto musicFile = MusicFile(tagFile);

    auto album = GetAlbumByTitle(tagFile.Title);

    if (!album.has_value())
    {
        album.value() = InitializeNewAlbum(TagFilePlaceholder());
    }

    album->SongList.push_back(musicFile);
}

std::optional<Album> MusicCollectionRepository::GetAlbumByTitle(std::string title)
{
    std::optional<Album> album;

    auto has_same_title = [title](Album album) {return album.Title == title; };

    auto foundValue = std::find_if(begin(albumCollection_), end(albumCollection_), has_same_title);

    if (foundValue != std::end(albumCollection_))
    {
        return std::optional{ *foundValue };
    }

    return std::nullopt;
}

MusicFile MusicCollectionRepository::ConvertToMusicFile(std::filesystem::path musicPath)
{
    return MusicFile(TagFilePlaceholder());
}

const std::set<Album>& MusicCollectionRepository::GetReadonlyAlbumCollection() const
{
    return albumCollection_;
}

Album MusicCollectionRepository::InitializeNewAlbum(TagFilePlaceholder tagFile)
{
    auto album = Album(tagFile);
    albumCollection_.insert(album);
    return album;
}
