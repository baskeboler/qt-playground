#ifndef CREARPERSONADIALOG_H
#define CREARPERSONADIALOG_H

#include <QDialog>
#include "persona.h"

namespace Ui {
class CrearPersonaDialog;
}

class CrearPersonaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CrearPersonaDialog(QWidget *parent = 0);
    ~CrearPersonaDialog();
signals:
    void personaCreated(Persona *p);

protected:
    void changeEvent(QEvent *e);

private slots:
    void accept();

private:
    Ui::CrearPersonaDialog *ui;
};

#endif // CREARPERSONADIALOG_H
