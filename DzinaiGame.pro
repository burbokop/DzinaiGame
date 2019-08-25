#-------------------------------------------------
#
# Project created by QtCreator 2016-08-21T09:35:08
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = DzinaiGame
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

LIBS += -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_gfx

QMAKE_CXXFLAGS = -std=c++11

SOURCES += main.cpp \
    af.cpp \
    pf.cpp \
    mainmenu.cpp \
    mainloop.cpp \
    spm.cpp

HEADERS += \
    af.h \
    pf.h \
    spm.h
