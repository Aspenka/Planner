QT += gui widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR = ../bin
OBJECTS_DIR = ../obj
TARGET = Planner

CONFIG += app_bundle c++11

TEMPLATE = app

#RC_ICONS = $$PWD/style/images/icon.ico

SOURCES += \
    desktop/bj/calendarWidget.cpp \
    desktop/mainWindow.cpp \
    main.cpp \

FORMS += \
    desktop/bj/calendarWidget.ui \
    desktop/mainWindow.ui

HEADERS += \
    desktop/bj/calendarWidget.h \
    desktop/common/common.h \
    desktop/mainWindow.h

