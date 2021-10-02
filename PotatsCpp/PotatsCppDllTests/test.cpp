#include "pch.h"

#include <fstream>
#include <list>
#include <string>
#include <windows.h>

TEST(Tests_PotatsCpp, GivenAPotatsCpp_WhenLoadingTheDll_ThenExternFunctionsCanBeCalled) {
    HINSTANCE handleToDll = LoadLibrary(TEXT("PotatsCpp.dll"));

    EXPECT_TRUE(handleToDll != nullptr);

    //by default it will load a void (*)(), we don't want that so we cast using (int (*)(int)) to get a function to which an int can be passed and which returns an int
    auto loadedFunction1 = (int (*)(int))GetProcAddress(handleToDll, "IncrementNumberOf1");
    EXPECT_TRUE(loadedFunction1 != nullptr);

    auto loadedFunction2 = (std::list<std::string>(*)())GetProcAddress(handleToDll, "GetListOfAlbums");
    EXPECT_TRUE(loadedFunction2 != nullptr);

    std::ofstream insertTestSourcePathsInSourceFileTxt(".\\sourceFileRepository\\sourceFile.txt");
    insertTestSourcePathsInSourceFileTxt << "..\\..\\PotatsCppTests\\TestFolderWithFilesEndingWithMp3\\";
    insertTestSourcePathsInSourceFileTxt.close();

    auto listOfAlbums = loadedFunction2();

    EXPECT_EQ(listOfAlbums.size(), 1);

    for (auto const& albumTitle : listOfAlbums) {
        EXPECT_GT(albumTitle.size(), 0);
        EXPECT_LT(albumTitle.size(), 256);
    }
}