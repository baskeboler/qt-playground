#-------------------------------------------------
#
# Project created by QtCreator 2015-06-27T06:09:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = persona-admin
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++0x


SOURCES += main.cpp\
        mainwindow.cpp \
    crearpersonadialog.cpp

HEADERS  += mainwindow.h \
    crearpersonadialog.h

FORMS    += mainwindow.ui \
    crearpersonadialog.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-personas-Desktop-Debug/release/ -lpersonas
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-personas-Desktop-Debug/debug/ -lpersonas
else:unix: LIBS += -L$$PWD/../build-personas-Desktop-Debug/ -lpersonas

INCLUDEPATH += $$PWD/../personas
DEPENDPATH += $$PWD/../personas

RESOURCES += \
    resources.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../personas/release/ -lpersonas
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../personas/debug/ -lpersonas
else:unix: LIBS += -L$$OUT_PWD/../personas/ -lpersonas

INCLUDEPATH += $$PWD/../personas
DEPENDPATH += $$PWD/../personas
