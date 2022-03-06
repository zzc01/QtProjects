#-------------------------------------------------
#
# Project created by QtCreator 6.0.2
#
#-------------------------------------------------

cmake_minimum_required(VERSION 3.14)

project(Q5-66QTcpSocketUsingSignalsAndSlots LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Network REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Network REQUIRED)

add_executable(Q5-66QTcpSocketUsingSignalsAndSlots
  main.cpp
  sockettest.h
  sockettest.cpp
)
target_link_libraries(Q5-66QTcpSocketUsingSignalsAndSlots Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network)
