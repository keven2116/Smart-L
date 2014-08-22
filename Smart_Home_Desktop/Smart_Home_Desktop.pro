#-------------------------------------------------
#
# Project created by QtCreator 2014-03-09T20:16:27
# Author:keven
# Blog:http://blog.163.com/wenwen10090215@126/
# github:https://github.com/bjwrkj/
#-------------------------------------------------

QT       += core gui
QT       += webkitwidgets webkit network  multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Smart_Home_Desktop
TEMPLATE = app
TRANSLATIONS = home_zh_CN.ts
RC_FILE = myapp.rc

SOURCES += main.cpp\
    push_btn.cpp \
    main_widget.cpp \
    tray_menu.cpp \
    table_view.cpp \
    main_menu.cpp \
    cycle_mode.cpp \
    lrc_view.cpp

HEADERS  += \
    push_btn.h \
    main_widget.h \
    tray_menu.h \
    table_view.h \
    main_menu.h \
    cycle_mode.h \
    lrc_view.h

FORMS    += \
    main_widget.ui

RESOURCES += \
    img.qrc
