// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include "MusicLoader.h"

#include <list>
#include <string>
#include <filesystem>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

void init_logging() {
    boost::log::register_simple_formatter_factory<boost::log::trivial::severity_level, char>("Severity");//Severity needs to be registered manually here if we want to see it in the log file.

    boost::log::add_file_log(
        boost::log::keywords::file_name = "PotatsCpp.dll.txt",
        boost::log::keywords::format = "[%LineID%] [%TimeStamp%] [%ProcessID%] [%ThreadID%] [%Severity%] %Message%"
    );

    boost::log::core::get()->set_filter(
        boost::log::trivial::severity >= boost::log::trivial::trace
    );

    boost::log::add_common_attributes();//adds TimeStamp, ThreadID to the attributes that will be printed in the file.txt
}

bool logging_initiated = false;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    if (logging_initiated == false)
    {
        init_logging();
        logging_initiated = true;
        BOOST_LOG_TRIVIAL(trace) << "logging initialized";
        BOOST_LOG_TRIVIAL(trace) << "current path : " << std::filesystem::current_path();
    }

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        BOOST_LOG_TRIVIAL(trace) << "dll main - process attach";
        break;
    case DLL_THREAD_ATTACH:
        BOOST_LOG_TRIVIAL(trace) << "dll main - thread attach";
        break;
    case DLL_THREAD_DETACH:
        BOOST_LOG_TRIVIAL(trace) << "dll main - thread dettach";
        break;
    case DLL_PROCESS_DETACH:
        BOOST_LOG_TRIVIAL(trace) << "dll main - process dettach";
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

    BOOST_LOG_TRIVIAL(trace) << "extern C GetListOfAlbums called";

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
