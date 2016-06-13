#-------------------------------------------------
#
# Project created by QtCreator 2016-06-13T14:06:56
#
#-------------------------------------------------

QT       += core gui sql network

#CONFIG   += console #Debug Console & Projects->Run->Run in terminal check

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QCClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    configration_form.cpp \
    workplan_form.cpp \
    temperature_form.cpp

HEADERS  += mainwindow.h \
    configration_form.h \
    workplan_form.h \
    temperature_form.h

FORMS    += mainwindow.ui \
    configration_form.ui \
    workplan_form.ui \
    temperature_form.ui

RESOURCES += \
    qcclientresource.qrc
