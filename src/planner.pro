QT += gui widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR = ../bin
OBJECTS_DIR = ../obj
TARGET = Planner

CONFIG += app_bundle c++11

TEMPLATE = app

#RC_ICONS = $$PWD/style/images/icon.ico

SOURCES += \
    desktop/bj/calendarLabel.cpp \
    desktop/bj/calendarWidget.cpp \
    desktop/bj/yearWidget.cpp \
    desktop/mainWindow.cpp \
    main.cpp \

FORMS += \
    desktop/bj/calendarWidget.ui \
    desktop/bj/yearWidget.ui \
    desktop/mainWindow.ui

HEADERS += \
    desktop/bj/calendarLabel.h \
    desktop/bj/calendarWidget.h \
    desktop/bj/yearWidget.h \
    desktop/common/common.h \
    desktop/mainWindow.h

