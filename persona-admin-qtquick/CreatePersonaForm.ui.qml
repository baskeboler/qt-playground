import QtQuick 2.4
import QtQuick.Controls 1.2

Item {
    id: item1
    width: 400
    height: 400
    //property  name: value
    property alias okButton: button1
    property alias cancelButton: button2
    property alias nombre: nombreEdit.text
    property alias direccion: direccionEdit.text
    property alias telefono: telefonoEdit.text
    property alias email:emailEdit.text

    Grid {
    }

    Column {
        id: column1
        anchors.fill: parent

        GroupBox {
            id: groupBox1
            width: 360
            height: 177
            anchors.horizontalCenter: parent.horizontalCenter
            title: qsTr("Crear Persona")

            TextField {
                id: nombreEdit
                y: 4
                height: 23
                anchors.left: parent.left
                anchors.leftMargin: 100
                anchors.right: parent.right
                anchors.rightMargin: 20
                placeholderText: qsTr("Text Field")
            }

            Label {
                id: label1
                x: 18
                y: 7
                text: qsTr("Nombre")
            }
            TextField {
                id: emailEdit
                y: 108
                height: 23
                anchors.right: parent.right
                anchors.rightMargin: 20
                anchors.left: parent.left
                anchors.leftMargin: 100
                placeholderText: qsTr("Text Field")
            }

            Label {
                id: label4
                x: 18
                y: 111
                text: qsTr("Email")
            }

            TextField {
                id: telefonoEdit
                y: 74
                height: 23
                anchors.right: parent.right
                anchors.rightMargin: 20
                anchors.left: parent.left
                anchors.leftMargin: 100
                placeholderText: qsTr("Text Field")
            }

            Label {
                id: label3
                x: 18
                y: 77
                text: qsTr("Telefono")
            }

            TextField {
                id: direccionEdit
                y: 38
                height: 23
                anchors.right: parent.right
                anchors.rightMargin: 20
                anchors.left: parent.left
                anchors.leftMargin: 100
                placeholderText: qsTr("Text Field")
            }

            Label {
                id: label2
                x: 18
                y: 41
                text: qsTr("Direccion")
            }








        }

        Flow {
            id: flow1
            width: 360
            height: 34
            layoutDirection: Qt.RightToLeft
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 5


            Button {
                id: button2
                text: qsTr("Cancelar")
                //onClicked: cancel()
            }
            Button {
                id: button1
                text: qsTr("Aceptar")
                isDefault: true
                //onClicked: ok("mario")
            }
        }
    }
}

