# Potats-Mp3-Player/can-we-load-a-cpp-library
I am rediscovering the new stuff in C++ and thought a rewrite of Potats in C++ could be a good starting point for that.

In this branch we have :
- PotatsCpp : A C++ solution that can be opened with Visual Studio 2022. It generates a dll called PotatsCpp.dll
- PotatsQt : A Qt Quick project that can be opened with Qt Community 5.0.2. It can only be run from the Qt Editor at the moment. It displays the original pages I've seen of the original Potats application during summer 2021.

This is a work-in-progress and my main goal is to use it to understand more about C++, dynamic loading of dlls and Qt.

So far I've learned the following
1. You can only load a C++ dll in a C++ exe if both have been built using the same compiler. This is because of name mangling in C++.
2. Qt Quick uses QML to define the UI. Behind the scene QML uses Javascript.
3. Qt projects using qmake or cmake can be configured to register C++ types that will be usable in QML. However, I had too many issues with cmake and the first good tutorial I found was in qmake so I ended up using qmake. 

Things I might explore in the future
1. Can I make the import of C++ type work in QML with cmake? It should work since I read this https://www.qt.io/blog/introduction-to-the-qml-cmake-api. I also found that examples come with an installation of Qt and some of them like this one $<qt-install-root>\Examples\Qt-6.2.0\quick\models\stringlistmodel have both the CMakeLists.txt and .pro file of qmake.
2. Adding more observability. I need to find a good way to observe what is happening in the cpp part of the application. Otherwise I can't maintain it easily and it affects my flow.  
