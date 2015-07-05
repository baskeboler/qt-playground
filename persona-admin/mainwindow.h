#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "persona.h"
#include "crearpersonadialog.h"
#include "editpersonadialog.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
    void setupSignalsAndSlots();
signals:
    void personaSelected(bool isSelected);
private:
    Ui::MainWindow *ui;
    Persona *selectedPersona;
    CrearPersonaDialog * crearDialog;
    EditPersonaDialog * editarDialog;
    long cdadPersonas;
private slots:
    void selectionChanged();
    // QWidget interface
    void on_crearButton_clicked();
    void agregarPersonaATable(Persona *p);
    void guardar();
    void cargar();
    void borrarPersonaDeTable(long id);
    void eliminarSeleccionado();
    void editarSeleccionado();
    void actualizarSeleccionado();
protected:
    virtual void resizeEvent(QResizeEvent *);

    // QWidget interface
public:
    virtual QSize sizeHint() const;
    void updateRow( int i, Persona *p);
};

#endif // MAINWINDOW_H
