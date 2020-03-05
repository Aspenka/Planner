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
    desktop/bj/taskCheckBoxx.cpp \
    desktop/bj/taskWidget.cpp \
    desktop/bj/yearWidget.cpp \
    desktop/mainWindow.cpp \
    main.cpp \

FORMS += \
    desktop/bj/addTextWidget.ui \
    desktop/bj/calendarWidget.ui \
    desktop/bj/taskCheckBox.ui \
    desktop/bj/taskWidget.ui \
    desktop/bj/yearWidget.ui \
    desktop/mainWindow.ui

HEADERS += \
    desktop/bj/addTextWidget.h \
    desktop/bj/calendarLabel.h \
    desktop/bj/calendarWidget.h \
    desktop/bj/taskCheckBox.h \
    desktop/bj/taskWidget.h \
    desktop/bj/yearWidget.h \
    desktop/common/common.h \
    desktop/mainWindow.h

