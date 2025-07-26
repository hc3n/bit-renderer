cmake_minimum_required(VERSION 3.5)
project(renderer LANGUAGES CXX)
set(CMAKE_AUTOMOC ON)



set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 5.15 REQUIRED COMPONENTS Widgets)

add_executable(${PROJECT_NAME}
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

add_subdirectory(bittransformerlib)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt5::Widgets
    PRIVATE bittransformerlib
)
