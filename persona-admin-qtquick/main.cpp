#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "callablemethods.h"
#include "personacontroller.h"
#include "persona.h"
#include <functional>
#include <QList>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
//    QGuiApplication app(argc, argv);
//    CallableMethods logic();
    QQmlApplicationEngine engine;
    qmlRegisterType<CallableMethods>("com.victor.cpp", 1, 0, "Logic");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject* window = engine.rootObjects().first();
    QVariant retVal;
    QMetaObject::invokeMethod(window, "addPersona",
                              Qt::AutoConnection,
                              Q_RETURN_ARG(QVariant, retVal),
                              Q_ARG(QVariant, 23),
                              Q_ARG(QVariant, "Victor Gil"),
                              Q_ARG(QVariant, "8 de oct 2323"),
                              Q_ARG(QVariant, "095253555"),
                              Q_ARG(QVariant, "mail@mail.com"));

  /*  PersonaController::getInstance()->add(
                new Persona(QString("victor"),
                            QString("9 de junio"),
                            QString("987987987"),
                            QString("baskeboler@gmail.com")
                            )
                );
    PersonaController::getInstance()->add(
                new Persona(QString("ramon"),
                            QString("9 de junio"),
                            QString("987987987"),
                            QString("baskeboler@gmail.com")
                            )
                );
    auto f = [](Persona *) -> bool {return true;};
    QList<Persona *> personas;
    personas = PersonaController::getInstance()->filter(f);
    QList<QObject *> *items = reinterpret_cast<QList<QObject*>*>(&personas);
*/
    //personas.append(new Persona("nombre1", "dir", "", ""));
    //personas.append(new Persona("nombre2", "dir", "", ""));
  /*  QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    QQmlContext *ctx = view.rootContext();
    ctx->setContextProperty("myModel", QVariant::fromValue(*items));
    view.setSource(QUrl("qrc:myview.qml"));
    view.show();
    */
  return app.exec();
}
