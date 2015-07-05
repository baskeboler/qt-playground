#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <functional>
#include <QStringList>
#include <QDebug>
#include <QFileDialog>

#include "personacontroller.h"
#include "crearpersonadialog.h"

void initPersonas();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),cdadPersonas(0)
{
    ui->setupUi(this);
    //ui->mainToolBar->addAction()
    PersonaController * controller = PersonaController::getInstance();

    crearDialog = new CrearPersonaDialog(this);
    editarDialog = new EditPersonaDialog(this);
    crearDialog->setWindowTitle("Crear Persona");
    setupSignalsAndSlots();
    auto f = [] (Persona*) -> bool {return true;}; // all
    QList<Persona *> all = controller->filter(f);
    int cantidadFilas = all.size();

    QTableWidget *table = ui->tableWidget;
    table->setRowCount(cantidadFilas);
    table->setColumnCount(5);

    QStringList header;
    header << "Id" << "Nombre" << "Direccion" << "Telefono" << "Email";
    table->setHorizontalHeaderLabels(header);
    table->adjustSize();
    initPersonas();
//    for (int i = 0; i < all.size(); i++) {
//        Persona *p = all.at(i);
//        int j = 0;
//        QTableWidgetItem *item = new QTableWidgetItem(QString().setNum(p->id()));
//        table->setItem(i, j++, item);
//        item = new QTableWidgetItem(p->nombre());
//        table->setItem(i, j++, item);

//        item = new QTableWidgetItem(p->direccion());
//        table->setItem(i, j++, item);

//        item = new QTableWidgetItem(p->telefono());
//        table->setItem(i, j++, item);
//    }
//    connect(crearDialog, SIGNAL(personaCreated(Persona*)), this, SLOT(agregarPersonaATable(Persona*)));

}

void initPersonas() {
    PersonaController * controller = PersonaController::getInstance();
    //controller->load("/home/victor/base.xml");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    case QEvent::Resize:
        ui->tableWidget->adjustSize();
        qDebug() << "Resize event!" << endl;
        break;
    default:
        break;
    }
}

void MainWindow::setupSignalsAndSlots()
{
    connect(ui->tableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(selectionChanged()));
    connect(this, SIGNAL(personaSelected(bool)), ui->editarButton, SLOT(setEnabled(bool)));
    connect(this, SIGNAL(personaSelected(bool)), ui->eliminarButton, SLOT(setEnabled(bool)));
    connect(ui->guardarButton, SIGNAL(clicked(bool)), this, SLOT(guardar()));
    connect(ui->crearButton, SIGNAL(clicked()), this, SLOT(on_crearButton_clicked()));
    connect(ui->eliminarButton, SIGNAL(clicked(bool)), this, SLOT(eliminarSeleccionado()));
    connect(ui->editarButton, SIGNAL(clicked(bool)), this, SLOT(editarSeleccionado()));
    connect(ui->actionAbrir, SIGNAL(triggered(bool)), this, SLOT(cargar()));
    connect(PersonaController::getInstance(), SIGNAL(personaAdded(Persona*)), this, SLOT(agregarPersonaATable(Persona*)));
    connect(PersonaController::getInstance(), SIGNAL(personaDeleted(long)), this, SLOT(borrarPersonaDeTable(long)));
    connect(this->editarDialog, SIGNAL(accepted()), this, SLOT(actualizarSeleccionado()));
}

void MainWindow::selectionChanged()
{
    QList<QTableWidgetItem *> localSelectedItems = ui->tableWidget->selectedItems();
    if (localSelectedItems.size() == 0) {
        selectedPersona = nullptr;
        emit personaSelected(false);
    }
    else {
        long id = localSelectedItems.first()->text().toLong();
        selectedPersona = PersonaController::getInstance()->find(id);
        emit personaSelected(true);
        qDebug() << selectedPersona->toString() << " selected!" << endl;
    }
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    qDebug() << "ResizeEvent()!!" << endl;
    //ui->tableWidget->setFixedWidth(size().width());
    //ui->tableWidget->visualRect()
    //adjustSize();
    int w = size().width() - ui->tableWidget->x()*2,
        h = size().height() - ui->tableWidget->y()
            - ui->statusBar->geometry().height()*2;
    ui->tableWidget->setFixedHeight(h);
    ui->tableWidget->setFixedWidth(w);
    //ui->verticalLayout->to
    qDebug() << ui->tableWidget->size();

}

QSize MainWindow::sizeHint() const
{
    QSize size;
    size.setHeight(400);
    size.setWidth(640);
    return size;
}

void MainWindow::on_crearButton_clicked()
{
    crearDialog->setModal(true);
    crearDialog->show();
}

void MainWindow::agregarPersonaATable(Persona *p)
{
    QTableWidget *table = ui->tableWidget;

    table->insertRow(0);
    QTableWidgetItem *item = new QTableWidgetItem(QString().setNum(p->id()));
    table->setItem(0, 0, item);

    item = new QTableWidgetItem(p->nombre());
    table->setItem(0, 1, item);

    item = new QTableWidgetItem((p->direccion()));
    table->setItem(0, 2, item);
    item = new QTableWidgetItem(p->telefono());
    table->setItem(0, 3, item);

    item = new QTableWidgetItem(p->email());
    table->setItem(0, 4, item);


    ui->lcdNumber->display((int)++cdadPersonas);
}



void MainWindow::guardar()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Guardar como ..."));
    PersonaController::getInstance()->save(filePath);
}

void MainWindow::cargar()
{
    QString filePath = QFileDialog::getOpenFileName();
    PersonaController::getInstance()->removeAll();
    ui->tableWidget->clearContents();
    PersonaController::getInstance()->load(filePath);
}

void MainWindow::borrarPersonaDeTable(long id)
{
    for (int i=0; i < ui->tableWidget->rowCount(); i++) {
        if (ui->tableWidget->item(i, 0)->text().toLong() == id) {
            ui->tableWidget->removeRow(i);
            ui->lcdNumber->display((int)--cdadPersonas);
            return;
        }
    }
}

void MainWindow::eliminarSeleccionado()
{
    if (selectedPersona != nullptr) {
        PersonaController::getInstance()->remove(selectedPersona->id());
        selectedPersona = nullptr;
        selectionChanged();
    }
}

void MainWindow::editarSeleccionado()
{
    if (selectedPersona != nullptr) {
        editarDialog->setPersona(selectedPersona);
        editarDialog->setModal(true);
        editarDialog->show();
    }
}

void MainWindow::updateRow(int i, Persona *p)
{
    QTableWidget *t = ui->tableWidget;
    t->item(i, 1)->setText(p->nombre());
    t->item(i, 2)->setText(p->direccion());
    t->item(i, 3)->setText(p->telefono());
    t->item(i, 4)->setText(p->email());
}

void MainWindow::actualizarSeleccionado()
{
    Persona *p = selectedPersona;
    QTableWidget * t = ui->tableWidget;
    for (int i = 0; i < t->rowCount(); i++) {
        if (t->item(i, 0)->text().toLong() == p->id()) {
            updateRow( i, p);
        }
    }
}
