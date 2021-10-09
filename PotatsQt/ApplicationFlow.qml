import QtQuick 2.4

ApplicationFlowForm {
    id: applicationFlow
    state: "titlePage"

    property int animationDuration: 100

    SequentialAnimation {
        id: animateBetweemTitleAndLoading
        running: true
        loops: 1//Animation.Infinite

        PropertyAction {
            targets: applicationFlow
            properties: "state"
            value: "titlePage"
        }

        PauseAnimation {
            duration: applicationFlow.animationDuration
        }

        PropertyAction {
            targets: applicationFlow
            properties: "state"
            value: "loadingPage"
        }

        PauseAnimation {
            duration: applicationFlow.animationDuration
        }

        PropertyAction {
            targets: applicationFlow
            properties: "state"
            value: "selectingMusicSourcePage"
        }

        PauseAnimation {
            duration: applicationFlow.animationDuration
        }

        PropertyAction {
            targets: applicationFlow
            properties: "state"
            value: "mainMenuPage"
        }

        PauseAnimation {
            duration: applicationFlow.animationDuration
        }
    }
}
