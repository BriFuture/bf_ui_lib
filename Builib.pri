QT       += widgets qml quick gui
CONFIG += c++11

# requires Qt 5.7 and a C++11 compiler
# include($$(BuiLib_DIR)/feature/Builib.prf)

contains(DEFINES, BUILIB_LIBRARY) {
MOC_DIR = ./qt/moc
RCC_DIR = ./qt/rcc/src
UI_DIR = ./qt/ui
UI_HEADERS_DIR = ./qt/ui/include
UI_SOURCES_DIR = ./qt/ui/src

}

INCLUDEPATH += $$PWD/include
DEPENDPATH  += $$PWD/include
include(feature/Builib.prf)
