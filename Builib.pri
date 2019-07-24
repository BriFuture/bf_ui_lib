QT       += widgets qml quick gui
CONFIG += c++11

# requires Qt 5.7 and a C++11 compiler
# include($$(BUILib_DIR)/Builib.pri)
_BUI_LIB_MAJOR_VER = 0
_BUI_LIB_MINOR_VER = 1
_BUI_LIB_PATCH_VER = 2


contains(DEFINES, BUILIB_LIBRARY) {
DEFINES += _BUI_LIB_MAJOR_VER=$$_BUI_LIB_MAJOR_VER \
    _BUI_LIB_MINOR_VER=$$_BUI_LIB_MINOR_VER \
    _BUI_LIB_PATCH_VER=$$_BUI_LIB_PATCH_VER

}
else {

DEPENDPATH += $$PWD/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lBUILib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lBUILibd
else:unix: LIBS += -L$$PWD/lib/ -lBUILib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/libBUILib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/libBUILibd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/BUILib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/BUILibd.lib
else:unix: PRE_TARGETDEPS += $$PWD/lib/libBUILib.a

} # contains(DEFINES, BUILIB_LIBRARY)

INCLUDEPATH += $$PWD/include

MOC_DIR = ./qt/moc
RCC_DIR = ./qt/rcc/src
UI_DIR = ./qt/ui
UI_HEADERS_DIR = ./qt/ui/include
UI_SOURCES_DIR = ./qt/ui/src
