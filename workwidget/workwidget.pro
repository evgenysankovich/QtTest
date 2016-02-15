#-------------------------------------------------
#
# Project created by QtCreator 2016-02-15T10:11:44
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = workwidget
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialogadddata.cpp

HEADERS  += mainwindow.h \
    dialogadddata.h

FORMS    += mainwindow.ui \
    dialogadddata.ui
