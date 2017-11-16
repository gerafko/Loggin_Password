#-------------------------------------------------
#
# Project created by QtCreator 2017-10-23T04:27:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Loggin_password
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    struct.cpp \
    user_interface.cpp \
    admin_interface.cpp

HEADERS  += mainwindow.h \
    struct.h \
    user_interface.h \
    admin_interface.h

FORMS    += mainwindow.ui \
    user_interface.ui \
    admin_interface.ui
