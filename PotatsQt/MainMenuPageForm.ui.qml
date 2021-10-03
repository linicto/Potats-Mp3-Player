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

    Background {
        z: -1
    }
}
