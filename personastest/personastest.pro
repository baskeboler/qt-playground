#-------------------------------------------------
#
# Project created by QtCreator 2015-06-24T08:23:22
#
#-------------------------------------------------

QT       += xml testlib

QT       -= gui

TARGET = tst_personastesttest
CONFIG   += console
CONFIG   -= app_bundle

QMAKE_CXXFLAGS += -std=c++0x

TEMPLATE = app


SOURCES += tst_personastesttest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../personas/release/ -lpersonas
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../personas/debug/ -lpersonas
else:unix: LIBS += -L$$OUT_PWD/../personas/ -lpersonas

INCLUDEPATH += $$PWD/../personas
DEPENDPATH += $$PWD/../personas
