#pragma once

#include "MusicCollectionRepository.h"

struct MusicLoader
{
    MusicCollectionRepository musicCollectionRepository_;

    MusicLoader();
    void BuildMusicCollection();
};

