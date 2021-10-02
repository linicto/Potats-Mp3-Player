import QtQuick 2.0

Image {
    id: root
    source: "../MusicPlayer/MusicPlayer/Assets/Add.png"
    signal clicked

    MouseArea{
        anchors.fill: parent
        onClicked:  root.clicked()
    }
}
