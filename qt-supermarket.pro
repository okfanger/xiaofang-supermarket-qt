#-------------------------------------------------
#
# Project created by QtCreator 2022-06-29T16:30:49
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-supermarket
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    buywidget.cpp \
    memberwidget.cpp \
    aboutus.cpp \
    genderbuttondelegate.cpp \
    startwidget.cpp \
    loginwidget.cpp \
    registerwidget.cpp \
    readonlydelegate.cpp \
    addmemeberwidget.cpp

HEADERS  += \
    sqlconnection.h \
    mainwindow.h \
    buywidget.h \
    memberwidget.h \
    aboutus.h \
    genderbuttondelegate.h \
    startwidget.h \
    loginwidget.h \
    registerwidget.h \
    readonlydelegate.h \
    addmemeberwidget.h

FORMS    += \
    mainwindow.ui \
    buywidget.ui \
    memberwidget.ui \
    aboutus.ui \
    startwidget.ui \
    loginwidget.ui \
    registerwidget.ui \
    addmemeberwidget.ui

DISTFILES +=

RESOURCES += \
    avatar.qrc
