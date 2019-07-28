#-------------------------------------------------
#
# Project created by QtCreator 2019-07-24T11:15:55
#
#-------------------------------------------------

TEMPLATE = lib

DEFINES += BUILIB_LIBRARY
include(Builib.pri)

_BUI_LIB_MINOR_VER = 1
_BUI_LIB_PATCH_VER = 2

win32: VERSION=$$_BUI_LIB_MAJOR_VER"."$$_BUI_LIB_MINOR_VER"."$$_BUI_LIB_PATCH_VER".1"
else:  VERSION=$$_BUI_LIB_MAJOR_VER"."$$_BUI_LIB_MINOR_VER"."$$_BUI_LIB_PATCH_VER

DEFINES += _BUI_LIB_MAJOR_VER=$$_BUI_LIB_MAJOR_VER \
    _BUI_LIB_MINOR_VER=$$_BUI_LIB_MINOR_VER \
    _BUI_LIB_PATCH_VER=$$_BUI_LIB_PATCH_VER

DESTDIR = $$PWD/lib/
CONFIG(debug, debug|release) {
    TARGET = BuiLibd
} else {
    TARGET = BuiLib
}

TRANSLATIONS += res/builib_zh_CN.ts

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/BAboutDialog.cpp \
    src/BcConsole.cpp \
    src/BuiLib.cpp \
    src/BUiUtil.cpp

HEADERS += \
    include/BAboutDialog.h \
    include/BcConsole.h \
    include/BuiLib.h \
    include/builib_global.h \
    include/BUiUtil.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

RESOURCES += \
    buires.qrc

FORMS += \
    include/BAboutDialog.ui \
    include/BcConsole.ui

DISTFILES += \
    res/bui.qss
