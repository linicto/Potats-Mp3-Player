#include "pch.h"
#include "MusicFile.h"

using namespace std;

MusicFile::MusicFile(filesystem::path path)
    :Path{path},
    SongTitle{path.filename().string()},
    AlbumTitle{path.parent_path().filename().string()}
{
    //TODO find how to get song information from mp3 metadata from ... filesystem maybe?
    auto tagFile = TagFilePlaceholder();
    SongArtist = tagFile.Artists;
    Year = tagFile.Year;
    Disk = tagFile.Disk;
    Track = tagFile.Track;
    Duration = tagFile.Duration;
}
