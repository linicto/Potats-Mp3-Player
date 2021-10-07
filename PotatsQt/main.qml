import QtQuick
import QtQuick.Window
import QtQuick.Controls
import cplusplus.potatscpp

Window {
    width: 1200
    height: 900
    visible: true
    title: qsTr("Potat's Music Player C++")

    ApplicationFlow{

    }

    PotatsCppDll{
        id: potatsCpp
    }

    TextField {
        text: potatsCpp.albumTitles
        placeholderText: qsTr("albumTitles")
    }

    BackEnd {
        id: backend
    }

    TextField {
        text: backend.userName
        placeholderText: qsTr("User name")
        anchors.centerIn: parent

        onEditingFinished: backend.userName = text
    }
}
