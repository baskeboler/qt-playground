#ifndef XMLPERSONAHANDLER_H
#define XMLPERSONAHANDLER_H
#include <QXmlContentHandler>
#include <QXmlErrorHandler>

#include "persona.h"

class PERSONASSHARED_EXPORT XmlPersonaHandler: public QXmlDefaultHandler
{
public:
    XmlPersonaHandler();

public:
    virtual bool fatalError(const QXmlParseException &exception);

public:
    //virtual QString errorString() const;

    // QXmlContentHandler interface
public:
    virtual bool startDocument();
    virtual bool endDocument();
    virtual bool startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts);
    virtual bool endElement(const QString &namespaceURI, const QString &localName, const QString &qName);
private:
    Persona *p;
};

#endif // XMLPERSONAHANDLER_H
