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
        profilewindow.cpp \
        signindialog.cpp \
    registrationdialog.cpp \
    filterdialog.cpp \
    courcesdialog.cpp \
    courseview.cpp

HEADERS += \
        mainwindow.h \
        profilewindow.h \
        signindialog.h \
    registrationdialog.h \
    filterdialog.h \
    coursesdialog.h \
    courseview.h

FORMS += \
        mainwindow.ui \        
        profilewindow.ui

RESOURCES += \
    images.qrc
