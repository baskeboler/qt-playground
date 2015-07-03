#include "personacontroller.h"
#include <QXmlStreamWriter>
#include <QXmlSimpleReader>
#include <QFile>
#include <map>
#include "xmlpersonahandler.h"

PersonaController * PersonaController::s_instance = nullptr;

PersonaController::PersonaController(QObject *parent) : QObject(parent)
{

}

PersonaController *PersonaController::getInstance()
{
    if (s_instance == nullptr)
        s_instance = new PersonaController();
    return s_instance;
}

Persona *PersonaController::find(long id)
{
    Persona * r = nullptr;
    if (m_personas.contains(id))
        r = this->m_personas.value(id);
    return r;
}

bool PersonaController::exists(long id)
{
    return m_personas.contains(id);
}

void PersonaController::add(Persona *p)
{

    if (p->id() == -1) {
        long nextId = Persona::getNextId();
        while(exists(nextId )) {
            nextId = Persona::getNextId();
        }
        p->setId(nextId);
    }
    m_personas.insert(p->id(), p);
    emit personaAdded(p);
}

void PersonaController::save()
{
    QFile f("base.xml");
    f.open(QFile::WriteOnly);
    QXmlStreamWriter w(&f);
    w.setAutoFormatting(true);
    w.writeStartDocument();
    w.writeStartElement("personas");
    foreach (Persona *p, m_personas.values()) {
        savePersona(w, p);
    }
    w.writeEndElement();
    w.writeEndDocument();
    f.flush();
    f.close();
}

void PersonaController::load(const QString &filePath)
{
    QFile f(filePath);
    f.open(QFile::ReadOnly);
    QXmlSimpleReader reader;
    QXmlInputSource *source = new QXmlInputSource(&f);
    XmlPersonaHandler *h = new XmlPersonaHandler();
    reader.setContentHandler(h);
    reader.setErrorHandler(h);
    reader.parse(*source);
    f.close();
    delete h;
    delete source;
}

void PersonaController::remove(long id)
{
    Persona *p = find(id);
    if (p != nullptr) {
        m_personas.remove(id);
        delete p;
        emit personaDeleted(id);
    }
}

void PersonaController::removeAll()
{
    for (int i = 0; i < m_personas.size(); i++) {
        Persona *p = m_personas.values().at(i);
        emit personaDeleted(p->id());
        delete p;
    }
    m_personas.clear();
}

QList<Persona *> PersonaController::filter(std::function<bool (Persona *)> func)
{
    QList<Persona *> ret, all = m_personas.values();
    for (int i=0; i < all.size(); i++) {
        Persona *p = all.at(i);
        if (func(p)) {
            ret.append(p);
        }
    }
    return ret;
}

void PersonaController::savePersona(QXmlStreamWriter& w, Persona *p) {
    w.writeStartElement(tr("persona"));
    w.writeAttribute("id", QString().setNum(p->id()));
    w.writeAttribute(tr("nombre"), p->nombre());
    w.writeAttribute(tr("telefono"), p->telefono());
    w.writeAttribute(tr("direccion"), p->direccion());
    w.writeAttribute(tr("email"), p->email());
    w.writeEndElement();
}

