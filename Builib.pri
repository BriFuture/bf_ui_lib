QT       += widgets qml quick gui
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

CONFIG(release, debug|release): {
    gcc:       LIBS  += -L"$$PWD/lib" -l"BuiLib-gcc$${_BUI_LIB_MAJOR_VER}"
    else:msvc: LIBS  += -L"$$PWD/lib" -l"BuiLib-msvc$${_BUI_LIB_MAJOR_VER}"

#    win32-g++: PRE_TARGETDEPS += $$PWD/lib/libBuiLib-gcc$${_BUI_LIB_MAJOR_VER}.a
#    else:win32:!win32-g++: PRE_TARGETDEPS += $$PWD/lib/BuiLib-msvc$${_BUI_LIB_MAJOR_VER}.lib
}
else:CONFIG(debug, debug|release): {
    gcc:       LIBS  += -L"$$PWD/lib" -l"BuiLibd-gcc$${_BUI_LIB_MAJOR_VER}"
    else:msvc: LIBS  += -L"$$PWD/lib" -l"BuiLibd-msvc$${_BUI_LIB_MAJOR_VER}"

#    win32-g++: PRE_TARGETDEPS += $$PWD/lib/libBuiLibd-gcc$${_BUI_LIB_MAJOR_VER}.a
#    else:win32:!win32-g++: PRE_TARGETDEPS += $$PWD/lib/BuiLibd-msvc$${_BUI_LIB_MAJOR_VER}.lib
}

} # contains(DEFINES, BUILIB_LIBRARY)

INCLUDEPATH += $$PWD/include
DEPENDPATH  += $$PWD/include
