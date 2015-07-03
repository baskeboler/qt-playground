#ifndef PERSONA_H
#define PERSONA_H

#include "personas_global.h"
#include <QObject>
#include <QString>

class PERSONASSHARED_EXPORT Persona: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nombre READ nombre WRITE setNombre NOTIFY nombreChanged)
    Q_PROPERTY(QString direccion READ direccion WRITE setDireccion NOTIFY direccionChanged)
    Q_PROPERTY(QString telefono READ telefono WRITE setTelefono NOTIFY telefonoChanged)
    Q_PROPERTY(long id READ id WRITE setId NOTIFY idChanged)

public:
    Persona(QObject *parent=0);
    Persona(const Persona& p);
    Persona(long id, QString &nombre, QString &direccion, QString &telefono);
    virtual ~Persona();
    QString direccion() const;
    QString telefono() const;
    long id() const;
    QString nombre() const;
    QString toString() const;

    static long getNextId();

public slots:
    void setNombre(QString nombre);
    void setDireccion(QString direccion);
    void setTelefono(QString telefono);
    void setId(long id);

signals:
    void direccionChanged(QString direccion);

    void telefonoChanged(QString telefono);

    void idChanged(long id);

    void nombreChanged(QString nombre);

private:
    long m_id;
    QString m_nombre;
    QString m_direccion;
    QString m_telefono;

    static long g_nextId;
};

#endif // PERSONA_H
