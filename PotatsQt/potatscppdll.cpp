#include "potatscppdll.h"

#include <list>
#include <string>
#include <windows.h>

PotatsCppDll::PotatsCppDll(QObject *parent) : QObject(parent)
{
    //loading the PotatsCpp library
    HINSTANCE potatsCppHandle = LoadLibrary(TEXT("PotatsCpp.dll"));
    if(potatsCppHandle == nullptr)
    {
        qDebug() << GetLastError();
    }

    //by default it will load a void (*)(), we don't want that so we cast using (int (*)(int)) to get a function to which an int can be passed and which returns an int
    std::string testStringToSee{"super nice string"};

    auto loadedFunction = (int (*)(int))GetProcAddress(potatsCppHandle, "IncrementNumberOf1");

    int a = 4;
    int b = loadedFunction(a);
    qDebug() << b;

    auto loadedFunction2 = (std::list<std::string> (*)())GetProcAddress(potatsCppHandle, "GetListOfAlbums");

    auto listOfAlbums = loadedFunction2();

    qDebug() << "size of list of alubms : " << listOfAlbums.size() << '\n';

    for(auto const& albumTitle : listOfAlbums){
        qDebug() << "size of album title : " << &albumTitle[0] << '\n';//&albumTitle[0] means that we refer to the string like if it is a char array to avoid the ambiguous issue of using string with qDebug
    }

    auto getCurrentPath = (std::string (*)())GetProcAddress(potatsCppHandle, "GetCurrentPath");
    auto path = getCurrentPath();
    qDebug() << QString::fromStdString(path);

    //end loading

    //inserting fake albums manually as we can't load them yet correctly with potats cpp dll
    albumTitles_.push_back("hello album 1");
    albumTitles_.push_back("hello album 2");
    albumTitles_.push_back("hello album 3");
}

QList<QString> PotatsCppDll::albumTitles(){
    return albumTitles_;
}
