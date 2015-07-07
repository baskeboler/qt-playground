import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    id: root
    width: 640
    height: 480

    property alias button3: button3
    property alias button2: button2
    property alias button1: button1
    property alias model:model
    property alias crearPersonaForm: createPersonaForm1

    property alias listView: listView1
    ListModel {
        id: model

    }

    RowLayout {
        id: mainButtons
        x: 0
        y: 20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10

        Button {
            id: button1
            text: qsTr("Crear")
        }

        Button {
            id: button2
            text: qsTr("Press Me 2")
        }

        Button {
            id: button3
            text: qsTr("Press Me 3")


        }
    }



    CreatePersonaForm {
        id: createPersonaForm1
        anchors.fill: parent
        opacity: 0
    }

    GridView {
        id: listView1
        x: 183
        width: 462

        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        anchors.horizontalCenterOffset: 10
        anchors.horizontalCenter: parent.horizontalCenter
        delegate: personaViewDelegate

        model: model


    }

    states: [
        State {
            name: "CrearPersona"

            PropertyChanges {
                target: createPersonaForm1
                opacity: 1
            }

            PropertyChanges {
                target: mainButtons
                visible: false
            }

            PropertyChanges {
                target: listView1
                visible: false
            }
        },
        State {
            name: "ListarPersonas"

            PropertyChanges {
                target: createPersonaForm1
                visible: false
            }

            PropertyChanges {
                target: listView1
                visible: true

            }

            PropertyChanges {
                target: mainButtons
                visible: true
            }

        }
    ]

    state: "ListarPersonas"

}
