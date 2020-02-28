QT += core
QT -= gui

CONFIG += c++11

TARGET = Proyecto
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    persona.cpp \
    estudiante.cpp \
    trabajador.cpp \
    facultad4.cpp

HEADERS += \
    persona.h \
    estudiante.h \
    trabajador.h \
    facultad4.h
