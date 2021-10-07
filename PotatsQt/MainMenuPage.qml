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

    Loader {
        sourceComponent: albumButton
    }

    Loader {
        sourceComponent: albumButton
        x: 50
    }
}
