import QtQuick 2.4

Item {
    width: 1200
    height: 900
    z: 0

    Text {
        x: 60
        anchors.fill: parent
        horizontalAlignment: Text.AlignHCenter
        color: "#f4cb2a"
        text: qsTr("Settings")
        font.pointSize: 60
        z: 2
        styleColor: "#e4b62d"
    }

    Text {
        anchors.fill: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignBottom
        color: "#f4cb2a"
        text: qsTr("Song Bar")
        font.pointSize: 60
        z: 2
        styleColor: "#e4b62d"
    }

    Rectangle {
        x: 100
        y: 150
        height: 600
        color: "#00ffffff"
        width: 1000
        ListView {
            //TODO: this doesn't show more than 4 albums
            anchors.fill: parent
            spacing: 25
            model: potatsCpp.albumTitles
            orientation: ListView.Horizontal
            delegate: AlbumButton {
                required property string modelData
                height: 222
                width: 230
                Text {
                    color: "#16150f"
                    anchors.fill: parent
                    text: parent.modelData
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignBottom
                    font.bold: true
                    font.pointSize: 12
                    font.family: "Arial"
                }
            }
        }
    }

    Background {
        z: -1
    }
}
