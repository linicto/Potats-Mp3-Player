#include "pch.h"
#include "MusicLoader.h"

#include "MusicFileExtractor.h"
#include "RepositoryController.h"

MusicLoader::MusicLoader()
    :musicCollectionRepository_(RepositoryController::getInstance().musicCollectionRepository_)
{
}

void MusicLoader::BuildMusicCollection()
{
    MusicFileExtractor musicFileExtractor;
    auto allMusicFiles = musicFileExtractor.getAllMusicFiles();

    for (const auto& entry : allMusicFiles)
    {
        musicCollectionRepository_.AddEntry(entry);
    }
}
