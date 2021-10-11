#include "pch.h"
#include "MusicLoader.h"

#include "MusicFileExtractor.h"
#include "RepositoryController.h"

#include <boost/log/trivial.hpp>

MusicLoader::MusicLoader()
    :musicCollectionRepository_(RepositoryController::getInstance().musicCollectionRepository_)
{
}

void MusicLoader::BuildMusicCollection()
{
    BOOST_LOG_TRIVIAL(trace) << "MusicLoader::BuildMusicCollection()";

    MusicFileExtractor musicFileExtractor;
    auto allMusicFiles = musicFileExtractor.getAllMusicFiles();

    for (const auto& entry : allMusicFiles)
    {
        BOOST_LOG_TRIVIAL(trace) << "MusicLoader::BuildMusicCollection() - adding entry : " << entry << " to musicCollectionRepository";
        musicCollectionRepository_.AddEntry(entry);
    }
}
