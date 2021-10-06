import QtQuick 2.0
import cplusplus.backendlib 1.0

Image {
    id: root
    source: "../MusicPlayer/MusicPlayer/Assets/WelcomePotat.png"
    signal clicked

    MouseArea{
        anchors.fill: parent
        onClicked:  root.clicked()
    }

    BackEnd { }
}
