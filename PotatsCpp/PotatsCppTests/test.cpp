#include "pch.h"

#include <filesystem>

#include "../../PotatsCpp/PotatsCpp/MusicLoader.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Tests_MusicLoader, GivenAMusicLoader_WhenBuildMusicCollection_ThenMusicCollectionObtained)
{
    //arrange
    MusicLoader musicLoader;
    //act
    musicLoader.BuildMusicCollection();
    //assert
    EXPECT_EQ(musicLoader.musicCollectionRepository_.GetReadonlyAlbumCollection().size(), 0);
    EXPECT_TRUE(std::filesystem::exists(".\\sourceFileRepository\\"));
    EXPECT_TRUE(std::filesystem::exists(".\\sourceFileRepository\\sourceFile.txt"));
}
