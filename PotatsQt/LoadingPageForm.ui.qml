import QtQuick 2.4

Item {
    width: 1200
    height: 900
    z: 0

    Text {
        x: 400
        y: 5
        color: "#f4cb2a"
        text: qsTr("Loading")
        font.pointSize: 90
        z: 2
        styleColor: "#e4b62d"
    }

    Background {
        z: -1
    }

    PotatsMascot {
        x: 400
        y: 300
        scale: 1.60
        z: 1
    }
}
