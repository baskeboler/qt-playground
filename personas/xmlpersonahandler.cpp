#include "xmlpersonahandler.h"
#include "personacontroller.h"
#include <QDebug>

XmlPersonaHandler::XmlPersonaHandler()
{

}

bool XmlPersonaHandler::fatalError(const QXmlParseException &exception)
{
    qWarning() << "Fatal error on line " << exception.lineNumber()
               << ", column " << exception.columnNumber()
               << ": " << exception.message();
    return false;
}

bool XmlPersonaHandler::startDocument()
{
    qDebug() << "Start of XML parsing." << endl;
    return true;
}

bool XmlPersonaHandler::endDocument()
{
    qDebug() << "End of parsing" << endl;
    return true;
}

bool XmlPersonaHandler::startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts)
{
    if (localName == "persona") {
        QString nombre = atts.value(atts.index("nombre"));
        QString direccion = atts.value(atts.index("direccion"));
        QString telefono = atts.value(atts.index("telefono"));
        QString email = atts.value(atts.index("email"));
        long id = atts.value(atts.index("id")).toLong();
        p = new Persona(id, nombre, direccion, telefono, email);
        //qDebug() << p->toString() << endl;

    }
    return true;
}

bool XmlPersonaHandler::endElement(const QString &namespaceURI, const QString &localName, const QString &qName)
{
    if (localName == "persona") {

        PersonaController::getInstance()->add(p);
        qDebug() << p->toString() << " cargada a memoria" << endl;
    }
    return true;
}

