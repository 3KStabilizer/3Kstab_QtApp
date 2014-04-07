#-------------------------------------------------
#
# Project created by QtCreator 2014-02-10T13:21:16
#
#-------------------------------------------------

QT       += core gui webkit webkitwidgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += core gui widgets webkit webkitwidgets network

TARGET = test_Qt5
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialogmenu.cpp \
    userdata.cpp \
    serverthread.cpp

HEADERS  += mainwindow.h \
    dialogmenu.h \
    userdata.h \
    serverthread.h

FORMS    += mainwindow.ui \
    dialogmenu.ui
