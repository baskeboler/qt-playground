#include "crearpersonadialog.h"
#include "ui_crearpersonadialog.h"
#include "personacontroller.h"
#include <QDebug>

CrearPersonaDialog::CrearPersonaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CrearPersonaDialog)
{
    ui->setupUi(this);
    //connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(on_buttonBox_accepted()));
}

CrearPersonaDialog::~CrearPersonaDialog()
{
    delete ui;
}

void CrearPersonaDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void CrearPersonaDialog::accept()
{
    Persona *p = new Persona();
    p->setNombre(ui->nombreEdit->text());
    p->setDireccion(ui->direccionEdit->text());
    p->setTelefono(ui->telefonoEdit->text());
    PersonaController::getInstance()->add(p);
    emit personaCreated(p);
    qDebug() << p->toString() << " creado!" << endl;
    hide();
}
