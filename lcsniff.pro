#-------------------------------------------------
#
# Project created by QtCreator 2018-12-11T13:09:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lcsniff
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    usbitem.cpp \
    usbmodel.cpp \
    usbpacket.cpp \
    usbrecord.cpp \
    helpers.cpp \
    usbgroup.cpp \
    usbtransaction.cpp \
    usbaggregator.cpp \
    capture.cpp \
    xbar/etherbone.c \
    xbar/xbar.c \
    configurewindow.cpp \
    usbproxy.cpp \
    filterwindow.cpp

HEADERS += \
        mainwindow.h \
    usbitem.h \
    usbmodel.h \
    usbpacket.h \
    usbrecord.h \
    helpers.h \
    usbgroup.h \
    usbtransaction.h \
    usbaggregator.h \
    capture.h \
    xbar/csr.h \
    xbar/etherbone.h \
    xbar/flags.h \
    xbar/sdram_phy.h \
    xbar/xbar.h \
    configurewindow.h \
    usbproxy.h \
    filterwindow.h

FORMS += \
        mainwindow.ui \
    configurewindow.ui \
    filterwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
