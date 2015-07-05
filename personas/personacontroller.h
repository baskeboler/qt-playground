#ifndef PERSONACONTROLLER_H
#define PERSONACONTROLLER_H

#include <functional>
#include <QObject>
#include <QMap>
#include <QXmlStreamWriter>

#include "persona.h"
class PERSONASSHARED_EXPORT PersonaController : public QObject
{
    Q_OBJECT

public:
    static PersonaController* getInstance();
    Persona *find(long id);
    bool exists(long id);
    void add( Persona * p);
    void save(const QString& filePath);
    void load(const QString &filePath);
    void remove(long id);
    void removeAll();
    QList<Persona *> filter(std::function<bool (Persona *)> func);
signals:
    void personaAdded(Persona *p);
    void personaDeleted(long id);
public slots:

private:
    explicit PersonaController(QObject *parent = 0);
    static PersonaController *s_instance;
    QMap<long, Persona*> m_personas;

protected:
    void savePersona(QXmlStreamWriter &w, Persona *p);
};

#endif // PERSONACONTROLLER_H
