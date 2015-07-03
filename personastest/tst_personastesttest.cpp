#include <QString>
#include <QtTest>
#include "personacontroller.h"
#include <functional>

class PersonastestTest : public QObject
{
    Q_OBJECT

public:
    PersonastestTest();
    PersonaController *controller;
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
    void testCase2();
    void testCase3();
    void personaAdded();
};

PersonastestTest::PersonastestTest()
{
}

void PersonastestTest::personaAdded() {
    QTest::qWarn("Persona added");
}

void PersonastestTest::initTestCase()
{
    controller = PersonaController::getInstance();
    connect(controller, SIGNAL(personaAdded()), this, SLOT(personaAdded()));
    for (int i=0; i < 10 ; i++) {
        Persona *p = new Persona;
        p->setNombre(tr("Victor Gil").append(QString().setNum(i)));
        p->setDireccion(tr("8 de Octubre 2323"));
        p->setTelefono(tr("095253555"));
        p->setEmail(tr("basket@gmail.com"));
        controller->add(p);
    }

    controller->save();
}

void PersonastestTest::cleanupTestCase()
{
}

void PersonastestTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

void PersonastestTest::testCase2()
{
    controller->removeAll();
    controller->load(tr("/home/victor/base.xml"));

}

void PersonastestTest::testCase3()
{
    auto f = [] (Persona *p) -> bool { return p->id() > 496;};
    QList<Persona *> personas = controller->filter(f);
    qDebug() << "Personas filtradas" << endl;
    for (int i = 0; i < personas.size(); i++) {
        Persona *p = personas.at(i);
        qDebug() << p->toString() << endl;
    }
    qDebug() << "Fin de personas filtradas" << endl;
}

QTEST_APPLESS_MAIN(PersonastestTest)

#include "tst_personastesttest.moc"
