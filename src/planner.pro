QT += gui widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR = ../bin
OBJECTS_DIR = ../obj
TARGET = Planner

CONFIG += app_bundle c++11

TEMPLATE = app

#RC_ICONS = $$PWD/style/images/icon.ico

SOURCES += \
    desktop/bj/addTextWidget.cpp \
    desktop/bj/calendarLabel.cpp \
    desktop/bj/calendarWidget.cpp \
    desktop/bj/itemListWidget.cpp \
    desktop/bj/itemWidget.cpp \
    desktop/bj/plannerWidget.cpp \
    desktop/bj/yearWidget.cpp \
    desktop/startWidget.cpp \
    desktop/mainWindow.cpp \
    main.cpp \

FORMS += \
    desktop/bj/addTextWidget.ui \
    desktop/bj/calendarWidget.ui \
    desktop/bj/itemListWidget.ui \
    desktop/bj/itemWidget.ui \
    desktop/bj/plannerWidget.ui \
    desktop/bj/yearWidget.ui \
    desktop/startwWdget.ui \
    desktop/mainWindow.ui

HEADERS += \
    desktop/bj/addTextWidget.h \
    desktop/bj/calendarLabel.h \
    desktop/bj/calendarWidget.h \
    desktop/bj/itemListWidget.h \
    desktop/bj/itemWidget.h \
    desktop/bj/plannerWidget.h \
    desktop/bj/yearWidget.h \
    desktop/common/common.h \
    desktop/startWidget.h \
    desktop/mainWindow.h

