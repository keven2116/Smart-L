#-------------------------------------------------
#
# Project created by QtCreator 2016-01-05T21:20:12
# Version: V1.0
# Author: Keven
# Support email: keven@ongoingcre.com
#-------------------------------------------------

QT       += core gui
QT       += webkitwidgets webkit network  multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Smart_L
TEMPLATE = app

TRANSLATIONS = home_zh_CN.ts

SOURCES += main.cpp\
        main_widget.cpp \
    Content/app/public/bottom_btn.cpp \
    Content/app/public/loading_widget.cpp \
    Content/app/public/push_btn.cpp \
    Content/app/public/util.cpp \
    Content/app/private/about/about_us.cpp \
    Content/app/private/about/drop_shadow_widget.cpp \
    Content/app/private/device/device_descirtion.cpp \
    Content/app/private/device/devices_tablemodel.cpp \
    Content/app/private/login/login.cpp \
    Content/app/private/menu/cycle_mode.cpp \
    Content/app/private/menu/list_op_menu.cpp \
    Content/app/private/menu/main_menu.cpp \
    Content/app/private/menu/tray_menu.cpp \
    Content/app/private/music/lrc/lrc_view.cpp \
    Content/app/private/music/music_frame.cpp \
    Content/app/private/music/PaiHangBang/paihangbangwidget.cpp \
    Content/app/private/music/component/musiclistwidget.cpp \
    Content/app/private/music/component/pagenumbar.cpp \
    Content/app/private/device/nvr/nvr_view.cpp

HEADERS  += main_widget.h \
    Content/app/public/bottom_btn.h \
    Content/app/public/loading_widget.h \
    Content/app/public/push_btn.h \
    Content/app/public/util.h \
    Content/app/private/about/about_us.h \
    Content/app/private/about/common.h \
    Content/app/private/about/drop_shadow_widget.h \
    Content/app/private/device/device_descirtion.h \
    Content/app/private/device/devices_tablemodel.h \
    Content/app/private/login/login.h \
    Content/app/private/menu/cycle_mode.h \
    Content/app/private/menu/list_op_menu.h \
    Content/app/private/menu/main_menu.h \
    Content/app/private/menu/tray_menu.h \
    Content/app/private/music/lrc/lrc_view.h \
    Content/app/private/music/music_frame.h \
    Content/app/private/music/PaiHangBang/paihangbangwidget.h \
    Content/app/private/music/component/musiclistwidget.h \
    Content/app/private/music/component/pagenumbar.h \
    Content/app/private/device/nvr/nvr_view.h

RESOURCES += \
   Content/res/img.qrc
#RC_FILE += \
    Content/res/myapp.rc
FORMS += \
    Content/app/private/music/music_frame.ui \
    Content/app/private/device/nvr/nvr_view.ui

OTHER_FILES +=
