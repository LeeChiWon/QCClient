#-------------------------------------------------
#
# Project created by QtCreator 2016-06-13T14:06:56
#
#-------------------------------------------------

QT       += core gui sql network printsupport

#CONFIG   += console #Debug Console & Projects->Run->Run in terminal check

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QCClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    configration_form.cpp \
    workplan_form.cpp \
    temperature_form.cpp \
    temp_moniter_style1.cpp \
    moldcondition_form.cpp \
    moldcondition_style.cpp \
    moldcondition_style1.cpp \
    mold_set_popup.cpp \
    workmen_select_popup.cpp \
    tempnameset_popup.cpp

HEADERS  += mainwindow.h \
    configration_form.h \
    workplan_form.h \
    temperature_form.h \
    temp_moniter_style1.h \
    globalinclude.h \
    moldcondition_form.h \
    moldcondition_style.h \
    moldcondition_style1.h \
    mold_set_popup.h \
    workmen_select_popup.h \
    tempnameset_popup.h

FORMS    += mainwindow.ui \
    configration_form.ui \
    workplan_form.ui \
    temperature_form.ui \
    temp_moniter_style1.ui \
    moldcondition_form.ui \
    moldcondition_style.ui \
    moldcondition_style1.ui \
    mold_set_popup.ui \
    workmen_select_popup.ui \
    tempnameset_popup.ui

RESOURCES += \
    qcclientresource.qrc

TRANSLATIONS += Lang_ko_KR.ts\
                Lang_en_US.ts
win32
{
   RC_FILE = QCClient.rc
   CONFIG += embed_manifest_exe
   QMAKE_LFLAGS_WINDOWS += /MANIFESTUAC:level=\'requireAdministrator\'
}
