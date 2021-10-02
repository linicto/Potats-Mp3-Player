import QtQuick 2.4

ApplicationFlowForm {
    id: applicationFlow
    state: "titlePage"

    property int animationDuration: 1000

    SequentialAnimation {
        id: animateBetweemTitleAndLoading
        running: true
        loops: Animation.Infinite

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
    }
}
