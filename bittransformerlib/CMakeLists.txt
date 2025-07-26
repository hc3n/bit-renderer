cmake_minimum_required(VERSION 3.14)

project(bittransformerlib LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Core Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui)

add_library(bittransformerlib STATIC
  bittransformerlib.cpp
  bittransformerlib.h
)

target_link_libraries(bittransformerlib
    PRIVATE Qt${QT_VERSION_MAJOR}::Core
    PRIVATE Qt${QT_VERSION_MAJOR}::Gui
)

target_include_directories(bittransformerlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
