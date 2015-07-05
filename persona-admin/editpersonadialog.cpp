#include "editpersonadialog.h"
#include "ui_editpersonadialog.h"
#include <QDebug>
void EditPersonaDialog::setFields(Persona *persona)
{
    if (persona != nullptr) {
        ui->nombreEdit->setText(persona->nombre());
        ui->direccionEdit->setText(persona->direccion());
        ui->telefonoEdit->setText(persona->telefono());
        ui->emailEdit->setText(persona->email());
    }
}

EditPersonaDialog::EditPersonaDialog(QWidget *parent, Persona *persona) :
    QDialog(parent),
    ui(new Ui::EditPersonaDialog),
    m_persona(persona)
{
    ui->setupUi(this);
    setFields(persona);
    connect(this, SIGNAL(personaChanged(Persona*)), this, SLOT(setFields(Persona*)));
}

EditPersonaDialog::~EditPersonaDialog()
{
    delete ui;
}

Persona *EditPersonaDialog::persona() const
{
    return m_persona;
}

void EditPersonaDialog::setPersona(Persona *persona)
{
    if (m_persona == persona)
        return;

    m_persona = persona;
    emit personaChanged(persona);
}

void EditPersonaDialog::changeEvent(QEvent *e)
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

void EditPersonaDialog::accept()
{
    qDebug() << "Accept!" <<endl;
    QString nombre = ui->nombreEdit->text(),
            telefono = ui->telefonoEdit->text(),
            direccion = ui->direccionEdit->text(),
            email = ui->emailEdit->text();
    Persona *p = persona();
    p->setNombre(nombre);
    p->setDireccion(direccion);
    p->setTelefono(telefono);
    p->setEmail(email);
    QDialog::accept();
}
