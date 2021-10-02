import QtQuick 2.4

Item {
    width: 1200
    height: 900
    z: 0

    Text {
        x: 60
        y: 5
        color: "#f4cb2a"
        text: qsTr("Where is your music located?")
        font.pointSize: 60
        z: 2
        styleColor: "#e4b62d"
    }

    AddMusicSourceButton {
        scale: 0.10
        x: 65
        y: 150
        z: 1
    }

    Background {
        z: -1
    }
}
