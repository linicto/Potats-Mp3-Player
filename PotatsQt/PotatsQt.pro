QT += quick

CONFIG += c++20

SOURCES += \
        backend.cpp \
        main.cpp \
        potatscppdll.cpp

RESOURCES += qml.qrc

QML_IMPORT_PATH =

QML_DESIGNER_IMPORT_PATH =

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    backend.h \
    potatscppdll.h

CONFIG += qmltypes
QML_IMPORT_NAME = cplusplus.potatscpp
QML_IMPORT_MAJOR_VERSION = 1
