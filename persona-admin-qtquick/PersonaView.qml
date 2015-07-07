import QtQuick 2.0

Rectangle {
    id: rectangle1
    width: 100
    height: 100
    color: "black"
    radius: 25
    signal remove(var idPersona)

    property alias removeArea: mouseArea2
    property alias mouseArea: mouseArea1
    //property alias nombre: nombre
   // property alias direccion: direccion

    property alias nombreTxt: text1
    property alias direccionTxt: text2
    property alias telefonoTxt: text3
    property alias emailTxt: text4
    gradient: Gradient {
        GradientStop {
            position: 0.00;
            color: "#000000";
        }
        GradientStop {
            position: 0.27;
            color: "#ffffff";
        }
        GradientStop {
            position: 1.00;
            color: "#ffffff";
        }
    }
    border.width: 3

    Column {
        id: column1
        anchors.topMargin: 10
        anchors.fill: parent
        spacing: 2

        Text {
            id: text1
            text: nombre
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 12
        }

        Text {
            id: text2
            text: direccion
            font.pixelSize: 12
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: text3
            text: telefono
            font.pixelSize: 12
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: text4
            text: email
            font.pixelSize: 12
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: text5
            text: qsTr("Text")
            visible: false
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 12
            enabled: false
            MouseArea {
                id: mouseArea2
                anchors.fill: parent
                onClicked: remove(idPersona)
            }
        }
    }

    MouseArea {
        id: mouseArea1
        anchors.fill: parent
        hoverEnabled: true
        onHoveredChanged: parent.state="hover"
        onExited: parent.state=""
    }
    states: [
        State {
            name: "hover"

            PropertyChanges {
                target: rectangle1
                width: 120
                height: 120
                radius: 25
                border.color: "#f10505"
            }

            PropertyChanges {
                target: text1
                font.bold: true
            }

            PropertyChanges {
                target: text5
                color: "#f21212"
                text: qsTr("Eliminar")
                visible: true
                enabled: true
                textFormat: Text.AutoText
                font.pixelSize: 18
                font.bold: true
                anchors.bottomMargin: 5
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                opacity: 1
            }

            PropertyChanges {
                target: mouseArea2
                opacity: 1
            }

            PropertyChanges {
                target: mouseArea1
                z: -1
            }

            PropertyChanges {
                target: column1
                transformOrigin: Item.Center
                spacing: 3
            }
        }
    ]
    transitions:Transition {

        animations: PropertyAnimation {
            target: rectangle1
            properties: "border.color,height,width"
            duration: 200
        }
    }
}

