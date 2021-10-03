#include "pch.h"

#include <filesystem>
#include <fstream>

#include "../../PotatsCpp/PotatsCpp/MusicLoader.h"
#include "../../PotatsCpp/PotatsCpp/RepositoryController.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Tests_MusicLoader, GivenAMusicLoader_WithSourceFileDirectoryAndSourceFileTxtNotCreated_WhenBuildMusicCollection_ThenDirectoryAndFileAreCreatedAndFileIsEmptyAndMusicCollectionIsEmpty)
{
    //arrange
    std::ofstream emptySourceFileTxt(".\\sourceFileRepository\\sourceFile.txt");
    emptySourceFileTxt.close();

    //This is to be sure the repository is reset. Since it is a singleton built when the first test will run, it may have already loaded in memory a sourceFile that is not empty.
    RepositoryController& repositoryController = RepositoryController::getInstance();
    repositoryController.sourceFileRepository_ = SourceFileRepository(std::filesystem::path{ ".\\sourceFileRepository\\sourceFile.txt" });

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

    //This is to be sure the repository is reset. Since it is a singleton built when the first test will run, it may have already loaded in memory an empty sourceFile.
    RepositoryController& repositoryController = RepositoryController::getInstance();
    repositoryController.sourceFileRepository_ = SourceFileRepository( std::filesystem::path{ ".\\sourceFileRepository\\sourceFile.txt" } );

    MusicLoader musicLoader;
    //act
    musicLoader.BuildMusicCollection();
    auto albumCollection = musicLoader.musicCollectionRepository_.GetReadonlyAlbumCollection();
    //assert
    EXPECT_EQ(albumCollection.size(), 1);

    for (const auto& [albumTitle, albumContent] : albumCollection)
    {
        EXPECT_EQ(albumContent.SongList.size(), 3);
    }

    EXPECT_TRUE(std::filesystem::exists(".\\sourceFileRepository\\"));
    EXPECT_TRUE(std::filesystem::exists(".\\sourceFileRepository\\sourceFile.txt"));
}
