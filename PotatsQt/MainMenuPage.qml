import QtQuick 2.4

MainMenuPageForm {
    id: mainMenu

    Component{
        id: albumButton
        AlbumButton { }
    }

    /*function addAlbum() {
        var album = albumButton.createObject(mainMenu, {"width": 50, "height": 80, "x": 50, "y": 50})
        var album2 = albumButton.createObject(mainMenu, {"width": 50, "height": 80, "x": 100, "y": 50})
        var album3 = albumButton.createObject(mainMenu, {"width": 50, "height": 80, "x": 150, "y": 50})
    }*/

    Loader {
        sourceComponent: albumButton
    }

    Loader {
        sourceComponent: albumButton
        x: 50
    }
}
