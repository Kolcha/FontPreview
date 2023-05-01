cmake_minimum_required(VERSION 3.8)

project(font_preview VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        fontpreviewwidget.cpp
        fontpreviewwidget.hpp
        mainwindow.cpp
        mainwindow.hpp
        mainwindow.ui
)

add_executable(font_preview ${PROJECT_SOURCES})

target_link_libraries(font_preview PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

install(TARGETS font_preview)
