#include "pch.h"
#include "MusicFile.h"

using namespace std;

MusicFile::MusicFile(filesystem::path Path)
{
    this->Path = Path;
}

MusicFile::MusicFile(TagFilePlaceholder musicFile)
{
    Path = musicFile.Name;
    AlbumTitle = musicFile.AlbumTitle;
    SongTitle = musicFile.Title;
    SongArtist = musicFile.Artists;
    Year = musicFile.Year;
    Disk = musicFile.Disk;
    Track = musicFile.Track;
    Duration = musicFile.Duration;
}