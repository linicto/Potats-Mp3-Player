// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include "MusicLoader.h"

#include <list>
#include <string>
#include <filesystem>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C"             //No name mangling
__declspec(dllexport)  //Tells the compiler to export the function
int                    //Function return type
__cdecl                //Specifies calling convention, cdelc is default,
                       //so this can be omitted
IncrementNumberOf1(int number) {
    return number + 1;
}

extern "C"
__declspec(dllexport)
std::list<std::string>
__cdecl
GetListOfAlbums() {
    MusicLoader musicLoader;
    musicLoader.BuildMusicCollection();
    auto map = musicLoader.musicCollectionRepository_.GetReadonlyAlbumCollection();
    std::list<std::string> listOfAlbums;

    for (auto [key, value] : map)
    {
        listOfAlbums.push_back(value.Title);
    }

    return listOfAlbums;
}

extern "C"
__declspec(dllexport)
std::string
__cdecl
GetCurrentPath() {
    return std::filesystem::current_path().string();
}
