#-------------------------------------------------
#
# Project created by QtCreator 2017-01-25T22:18:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        dialog.cpp \
    compileDialog.cpp \
    compilesettingdialog.cpp \
    testwidget.cpp \
    testdialog.cpp \
    detaildialog.cpp \
    analyzedialog.cpp \
    analyzesettingsdialog.cpp \
    atactmdialog.cpp \
    radiosettingwidget.cpp \
    atacfiledsettingwidget.cpp \
    atacsummarysettingwidget.cpp

HEADERS  += dialog.h \
    compilesettingdialog.h \
    compileDialog.h \
    testwidget.h \
    testdialog.h \
    detaildialog.h \
    analyzedialog.h \
    analyzesettingsdialog.h \
    atactmdialog.h \
    radiosettingwidget.h \
    atacfiledsettingwidget.h \
    atacsummarysettingwidget.h

FORMS    += dialog.ui \
    compileDialog.ui \
    compilesettingdialog.ui \
    testwidget.ui \
    testdialog.ui \
    detaildialog.ui \
    analyzedialog.ui \
    analyzesettingsdialog.ui \
    atactmdialog.ui \
    analyzefiledsettingwidget.ui \
    radiosettingwidget.ui \
    atacfiledsettingwidget.ui \
    atacsummarysettingwidget.ui
