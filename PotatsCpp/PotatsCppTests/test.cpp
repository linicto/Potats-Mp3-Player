#include "pch.h"

#include <filesystem>
#include <fstream>

#include "../../PotatsCpp/PotatsCpp/MusicLoader.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Tests_MusicLoader, GivenAMusicLoader_WithSourceFileDirectoryAndSourceFileTxtNotCreated_WhenBuildMusicCollection_ThenDirectoryAndFileAreCreatedAndFileIsEmptyAndMusicCollectionIsEmpty)
{
    //arrange
    std::ofstream emptySourceFileTxt(".\\sourceFileRepository\\sourceFile.txt");
    emptySourceFileTxt.close();

    MusicLoader musicLoader;
    //act
    musicLoader.BuildMusicCollection();
    //assert
    EXPECT_EQ(musicLoader.musicCollectionRepository_.GetReadonlyAlbumCollection().size(), 0);
    EXPECT_TRUE(std::filesystem::exists(".\\sourceFileRepository\\"));
    EXPECT_TRUE(std::filesystem::exists(".\\sourceFileRepository\\sourceFile.txt"));
}

TEST(Tests_MusicLoader, GivenAMusicLoader_WithAPathInSourceFileRepositoryTxtWhichContainsSourcePathsAndPathsAreNotEmpty_ThenMusicCollectionIsNotEmpty)
{
    //arrange
    std::ofstream insertTestSourcePathsInSourceFileTxt(".\\sourceFileRepository\\sourceFile.txt");
    insertTestSourcePathsInSourceFileTxt << "..\\..\\PotatsCppTests\\TestFolderWithFilesEndingWithMp3\\";
    insertTestSourcePathsInSourceFileTxt.close();

    MusicLoader musicLoader;
    //act
    musicLoader.BuildMusicCollection();
    //assert
    EXPECT_EQ(musicLoader.musicCollectionRepository_.GetReadonlyAlbumCollection().size(), 3);
    EXPECT_TRUE(std::filesystem::exists(".\\sourceFileRepository\\"));
    EXPECT_TRUE(std::filesystem::exists(".\\sourceFileRepository\\sourceFile.txt"));
}
