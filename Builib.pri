QT       += widgets qml quick gui serialport
CONFIG += c++11

# requires Qt 5.7 and a C++11 compiler
# include($$(BuiLib_DIR)/Builib.pri)
_BUI_LIB_MAJOR_VER = 0

contains(DEFINES, BUILIB_LIBRARY) {
MOC_DIR = ./qt/moc
RCC_DIR = ./qt/rcc/src
UI_DIR = ./qt/ui
UI_HEADERS_DIR = ./qt/ui/include
UI_SOURCES_DIR = ./qt/ui/src

}
else {

CONFIG(release, debug|release): LIBS += -L"$$PWD/lib/" -l"BuiLib$$_BUI_LIB_MAJOR_VER"
else:CONFIG(debug, debug|release): LIBS += -L"$$PWD/lib/" -l"BuiLibd$$_BUI_LIB_MAJOR_VER"


# static import
#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lBuiLib
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lBuiLibd
#else:unix: LIBS += -L$$PWD/lib/ -lBuiLib

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/libBuiLib.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/libBuiLibd.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/BuiLib.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/BuiLibd.lib
#else:unix: PRE_TARGETDEPS += $$PWD/lib/libBuiLib.a

} # contains(DEFINES, BUILIB_LIBRARY)

INCLUDEPATH += $$PWD/include
DEPENDPATH  += $$PWD/include
