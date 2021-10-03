import QtQuick 2.4

Item {
    id: root
    width: 1200
    height: 900
    z: 0

    TitlePage {
        id: titlePage
    }

    LoadingPage {
        id: loadingPage
    }

    SelectMusicSourcePage {
        id: selectMusicSourcePage
    }

    states: [
        State {
            name: "titlePage"
            PropertyChanges {
                target: titlePage
                visible: true
            }
            PropertyChanges {
                target: loadingPage
                visible: false
            }
            PropertyChanges {
                target: selectMusicSourcePage
                visible: false
            }
        },
        State {
            name: "loadingPage"
            PropertyChanges {
                target: loadingPage
                visible: true
            }
            PropertyChanges {
                target: titlePage
                visible: false
            }
            PropertyChanges {
                target: selectMusicSourcePage
                visible: false
            }
        },
        State {
            name: "selectingMusicSourcePage"
            PropertyChanges {
                target: titlePage
                visible: false
            }
            PropertyChanges {
                target: loadingPage
                visible: false
            }
            PropertyChanges {
                target: selectMusicSourcePage
                visible: true
            }
        }
    ]
}
