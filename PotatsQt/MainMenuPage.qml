import QtQuick 2.4
import QtQuick.Controls
import cplusplus.potatscpp

MainMenuPageForm {
    id: mainMenu

    Component{
        id: albumButton
        AlbumButton { }
    }

    PotatsCppDll{
        id: potatsCpp
    }

    TextField {
        text: potatsCpp.albumTitles
        placeholderText: qsTr("albumTitles")
    }

    ListView{
        anchors.fill: parent
        model: potatsCpp.albumTitles
        delegate: Rectangle {
            required property string modelData
            height: 25
            width: 100
            Text {
                text: parent.modelData
            }
        }
    }

    Loader {
        sourceComponent: albumButton
    }

    Loader {
        sourceComponent: albumButton
        x: 50
    }
}
