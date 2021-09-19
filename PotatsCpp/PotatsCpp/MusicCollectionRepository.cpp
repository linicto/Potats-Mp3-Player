#include "pch.h"
#include "MusicCollectionRepository.h"

MusicCollectionRepository::MusicCollectionRepository()
    :albumCollection_()
{}

void MusicCollectionRepository::CreateNewRepository()
{
    albumCollection_ = std::set<Album>();
    //another way to do this would be to empty the set with the following
    //albumCollection_.clear();
}

void MusicCollectionRepository::AddEntry(std::filesystem::path entry)
{
    //TODO find a way to replace the TagFilePlaceholder and to read the actual file.
    auto tagFile = TagFilePlaceholder();

    auto musicFile = MusicFile(tagFile);

    auto album = GetAlbumByTitle(tagFile.Title);

    if (album.has_value)
    {
        album->SongList.push_back(musicFile);
    }
    else
    {
        //continue here by calling Initialize new album and implementing it.
        //also need to implement GetAlbumByTitle up here
    }
}