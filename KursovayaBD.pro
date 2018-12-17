#-------------------------------------------------
#
# Project created by QtCreator 2018-11-27T19:50:31
#
#-------------------------------------------------

QT     += core gui
CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = KursovayaBD
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


OBJECTS_DIR    = build/obj
MOC_DIR        = build/moc
UI_HEADERS_DIR = build/ui


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        courseswindow.cpp \
        profilewindow.cpp \
        filterwindow.cpp \
        courseview.cpp \
        signindialog.cpp \
    registrationdialog.cpp \
    filterdialog.cpp

HEADERS += \
        mainwindow.h \
        courseswindow.h \
        profilewindow.h \
        filterwindow.h \
        courseview.h \
        signindialog.h \
    registrationdialog.h \
    filterdialog.h

FORMS += \
        mainwindow.ui \
        courseswindow.ui \
        profilewindow.ui \
        filterwindow.ui

RESOURCES += \
    images.qrc
