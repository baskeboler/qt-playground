#ifndef EDITPERSONADIALOG_H
#define EDITPERSONADIALOG_H

#include <QDialog>
#include "persona.h"

namespace Ui {
class EditPersonaDialog;
}

class EditPersonaDialog : public QDialog
{
    Q_OBJECT
    Q_PROPERTY(Persona* persona READ persona WRITE setPersona NOTIFY personaChanged)
public:
    explicit EditPersonaDialog(QWidget *parent = 0, Persona *persona = nullptr);
    ~EditPersonaDialog();

    Persona* persona() const;

public slots:
    void setPersona(Persona* persona);
    void setFields(Persona *persona);

signals:
    void personaChanged(Persona* persona);

protected:
    void changeEvent(QEvent *e);

private slots:
    void accept();

private:
    Ui::EditPersonaDialog *ui;
    Persona* m_persona;

};

#endif // EDITPERSONADIALOG_H
