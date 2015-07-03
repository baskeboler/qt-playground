#-------------------------------------------------
#
# Project created by QtCreator 2015-06-24T07:36:36
#
#-------------------------------------------------

QT       += xml testlib

QT       -= gui

TARGET = personas
TEMPLATE = lib
QMAKE_CXXFLAGS += -std=c++0x

DEFINES += PERSONAS_LIBRARY

SOURCES += persona.cpp \
    personacontroller.cpp \
    xmlpersonahandler.cpp

HEADERS += persona.h\
        personas_global.h \
    personacontroller.h \
    xmlpersonahandler.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
