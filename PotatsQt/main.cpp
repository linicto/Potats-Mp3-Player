#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <list>
#include <string>
#include <windows.h>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

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

    for(auto const& albumTitle : listOfAlbums){
        qDebug() << "size of album title : " << albumTitle.size() << '\n';
    }
    //end loading

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
