cmake_minimum_required (VERSION 3.9)

set(BUILIB_MAJOR_VER 0)
set(BUILIB_MINOR_VER 1)
set(BUILIB_PATCH_VER 20)

project(Builib VERSION 0.1.20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

configure_file( "./config.h.in" "./include/config.h" )

include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)

find_package(Qt5 COMPONENTS Widgets Core REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS})
add_definitions(${QT5Widgets_DEFINITIONS})
include_directories(${Qt5Core_INCLUDE_DIRS})
add_definitions(${QT5Core_DEFINITIONS})

include_directories(${PROJECT_SOURCE_DIR}/include)
file( GLOB HEADERS
    ${PROJECT_SOURCE_DIR}/include/*.h
    )

add_definitions(-DBUILD_WITH_CMAKE)

aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SRCS)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${PROJECT_SOURCE_DIR}/include/)
file( GLOB UIS ${PROJECT_SOURCE_DIR}/include/*.ui )
set(RESOURCES buires.qrc)

set(CMAKE_DEBUG_POSTFIX d)
add_library(Builib SHARED ${DIR_SRCS} ${UIS} ${HEADERS} ${RESOURCES})
target_link_libraries(Builib Qt5::Widgets Qt5::Core)
set_target_properties( Builib
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
)
