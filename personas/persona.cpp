#include "persona.h"
#include <QStringBuilder>

long Persona::g_nextId = 0;

Persona::Persona(const Persona &p):
    QObject(),
    m_id(p.id()),
    m_nombre(p.nombre()),
    m_direccion(p.direccion()),
    m_telefono(p.telefono())
{

}

Persona::Persona(long id, QString &nombre, QString &direccion, QString &telefono)
    :
      QObject(),
      m_id(id),
      m_nombre(nombre),
      m_direccion(direccion),
      m_telefono(telefono)
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
    return QString("Persona(") % QString().setNum(id())
            % ", " % nombre()
            % ", " % direccion()
            % ", " % telefono() % ")";
}

long Persona::getNextId()
{
    return g_nextId++;
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
