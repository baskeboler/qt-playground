#include "persona.h"
#include <QStringBuilder>

long Persona::g_nextId = 0;

Persona::Persona(const Persona &p):
    QObject(),
    m_id(p.id()),
    m_nombre(p.nombre()),
    m_direccion(p.direccion()),
    m_telefono(p.telefono()),
    m_email(p.email())
{

}

Persona::Persona(long id, QString &nombre, QString &direccion, QString &telefono, QString &email)
    :
      QObject(),
      m_id(id),
      m_nombre(nombre),
      m_direccion(direccion),
      m_telefono(telefono),
      m_email(email)
{

}

Persona::~Persona()
{

}

Persona::Persona(QObject *parent): QObject(parent), m_id(-1)
{
}

QString Persona::direccion() const
{
    return m_direccion;
}

QString Persona::telefono() const
{
    return m_telefono;
}

long Persona::id() const
{
    return m_id;
}

QString Persona::nombre() const
{
    return m_nombre;
}

QString Persona::toString() const
{
    return QString("Persona(") % QString::number(id())
            % ", " % nombre()
            % ", " % direccion()
            % ", " % telefono()
            % ", " % email()
            % ")";
}

long Persona::getNextId()
{
    return g_nextId++;
}

QString Persona::email() const
{
    return m_email;
}

void Persona::setNombre(QString nombre)
{
    m_nombre = nombre;
}

void Persona::setDireccion(QString direccion)
{
    if (m_direccion == direccion)
        return;

    m_direccion = direccion;
    emit direccionChanged(direccion);
}

void Persona::setTelefono(QString telefono)
{
    if (m_telefono == telefono)
        return;

    m_telefono = telefono;
    emit telefonoChanged(telefono);
}

void Persona::setId(long id)
{
    if (m_id == id)
        return;

    m_id = id;
    emit idChanged(id);
}

void Persona::setEmail(QString email)
{
    if (m_email == email)
        return;

    m_email = email;
    emit emailChanged(email);
}
