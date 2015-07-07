import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtBluetooth 5.0
import com.victor.cpp 1.0

ApplicationWindow {
    id: app
    title: qsTr("Hello World")
    width: 640
    height: 480
    visible: true
    FileDialog {
        id: fileDialog
        onAccepted: {
            ui.model.clear();
            logicObj.loadFile(fileUrl);

        }

    }
    FileDialog {
        id: saveDialog
        selectExisting: false
        onAccepted: {
            logicObj.saveFile(fileUrl)
        }
    }


    Logic {
        id: logicObj
        window: app

    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: {
                    fileDialog.open()
                }

            }
            MenuItem {
                text: qsTr("&Save")
                onTriggered: {
                    saveDialog.open()
                }
            }
            MenuSeparator {

            }

            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    Component {
        id: personaDelegate
        //Item {
            Row {
                Column {
                    Text {
                        text: id
                    }
                }

                Column {
                    Text {
                        text: nombre
                    }
                }
                Column {
                    Text {
                        text: direccion
                    }
                }
                Column {
                    Text {
                        text: telefono
                    }
                }
                Column {
                    Text {
                        text: email
                    }
                }
            }
        //}
    }



    MainForm {
        id: ui
        anchors.fill: parent
        button1.onClicked:  {
            logicObj.printSomething()
            ui.state = "CrearPersona"
        }
        button2.onClicked: messageDialog.show(qsTr("Button 2 pressed"))
        button3.onClicked: {
            model.append({idPersona: 0, nombre: "pepito", direccion: "9 de junio 1389"})
        }
        listView.delegate: PersonaView {
            id: personaViewDelegate
            removeArea.onClicked: {
                ui.model.remove(index)
            }
            onRemove: {
                logicObj.eliminarPersona(idPersona)
            }
        }
        model.onRowsRemoved: {

        }

        crearPersonaForm {
            okButton.onClicked: {
                var a = {
                    nombre: crearPersonaForm.nombre,
                    direccion: crearPersonaForm.direccion,
                    telefono: crearPersonaForm.telefono,
                    email: crearPersonaForm.email
                }
                logicObj.crearPersona(a);
                ui.state = "ListarPersonas"
            }
            cancelButton.onClicked: {
                ui.state = "ListarPersonas"
            }
        }
    }

    MessageDialog {
        id: messageDialog
        title: qsTr("May I have your attention, please?")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }



    function addPersona(id, nom, dir, tel, mail) {
        ui.model.append({idPersona: id, nombre: nom, direccion: dir, telefono: tel, email: mail});
        ui.model.remove()
        return "OK";
    }

}
