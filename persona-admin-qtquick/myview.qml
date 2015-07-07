import QtQuick 2.0

ListView {
    id: vista
    width: 400
    height: 400
    model: myModel
    delegate: Rectangle {
        width: parent.width
        height: 25
        color: Qt.white
        border.color: "black"
        Text {
            horizontalAlignment: Text.AlignHCenter
            text: nombre

        }

    }
}

