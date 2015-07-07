TEMPLATE = app

QT += qml quick widgets declarative

SOURCES += main.cpp \
    callablemethods.cpp

RESOURCES += qml.qrc

QMAKE_CXXFLAGS += -std=c++0x
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    callablemethods.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../personas/release/ -lpersonas
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../personas/debug/ -lpersonas
else:unix: LIBS += -L$$OUT_PWD/../personas/ -lpersonas

INCLUDEPATH += $$PWD/../personas
DEPENDPATH += $$PWD/../personas
