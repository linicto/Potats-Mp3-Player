#include "pch.h"
#include "MusicFile.h"

using namespace std;

MusicFile::MusicFile(filesystem::path Path)
{
    this->Path = Path;
}

MusicFile::MusicFile(TagFilePlaceholder tagFile)
{
    Path = tagFile.Name;
    AlbumTitle = tagFile.AlbumTitle;
    SongTitle = tagFile.Title;
    SongArtist = tagFile.Artists;
    Year = tagFile.Year;
    Disk = tagFile.Disk;
    Track = tagFile.Track;
    Duration = tagFile.Duration;
}