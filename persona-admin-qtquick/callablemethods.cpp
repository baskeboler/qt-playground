#include "callablemethods.h"
#include <QDebug>
#include "personacontroller.h"
#include "persona.h"
#include <QList>
#include <QUrl>
#include <QVariant>
#include <functional>
#include <QMetaObject>
#include <QJSValue>

CallableMethods::CallableMethods(QObject *parent) : QObject(parent)
{
    connect(PersonaController::getInstance(), &PersonaController::personaAdded, this, &CallableMethods::personaAdded);

}

int CallableMethods::numberOfPeople() const
{
    qDebug() << "inside numberOfPeople()" << endl;
    PersonaController *c = PersonaController::getInstance();
    auto f = [] (Persona *p) -> bool { return p != nullptr;};
    return c->filter(f).size();

}

QObject *CallableMethods::window() const
{
    return m_window;
}

void CallableMethods::printSomething()
{
    qDebug() << "inside printSomething()!" <<endl;
}

void CallableMethods::loadFile(QVariant file)
{
    qDebug() << "inside load";
    PersonaController::getInstance()->load(file.toUrl().toLocalFile());
}

void CallableMethods::saveFile(QVariant file)
{
    qDebug() << "Inside Save!";
    PersonaController::getInstance()->save(file.toUrl().toLocalFile());
}

void CallableMethods::personaAdded(Persona *p)
{
    QVariant retVal;
    QMetaObject::invokeMethod(window(), "addPersona",
                              Qt::AutoConnection,
                              Q_RETURN_ARG(QVariant, retVal),
                              Q_ARG(QVariant, (int)p->id()),
                              Q_ARG(QVariant, p->nombre()),
                              Q_ARG(QVariant, p->direccion()),
                              Q_ARG(QVariant, p->telefono()),
                              Q_ARG(QVariant, p->email()));

}

void CallableMethods::setWindow(QObject *window)
{
    qDebug() << "Setting window!";
    if (m_window == window)
        return;

    m_window = window;
    emit windowChanged(window);
}

void CallableMethods::crearPersona(QVariant p)
{
    qDebug() << "Crear Persona: " << p;
   // p.
    QJSValue val = p.value<QJSValue>();
    QString nombre = val.property("nombre").toString();
    QString direccion = val.property("direccion").toString();
    QString telefono = val.property("telefono").toString();
    QString email = val.property("email").toString();
    PersonaController::getInstance()->add(new Persona(nombre, direccion, telefono, email));
    qDebug() << "Creando Persona(" << nombre << ", " << direccion << ")";
}

void CallableMethods::eliminarPersona(QVariant idPersona)
{
    qDebug() << "Eliminando persona id " << idPersona.toInt();
    PersonaController::getInstance()->remove(idPersona.toInt());
}

