#ifndef CALLABLEMETHODS_H
#define CALLABLEMETHODS_H
#include <QObject>
#include <QVariant>
#include "persona.h"

class CallableMethods : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject* window READ window WRITE setWindow NOTIFY windowChanged)
    QObject* m_window;

public:
    explicit CallableMethods(QObject *parent = 0);
    Q_INVOKABLE int numberOfPeople() const;
    QObject* window() const;

signals:
    void windowChanged(QObject* window);

public slots:
    void printSomething();
    void loadFile(QVariant file);
    void saveFile(QVariant file);
    void personaAdded(Persona *p);
    void setWindow(QObject* window);
    void crearPersona(QVariant p);
    void eliminarPersona(QVariant idPersona);
};

#endif // CALLABLEMETHODS_H
