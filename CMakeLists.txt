cmake_minimum_required(VERSION 3.23)
project(MultiThreadProj)

set(CMAKE_CXX_STANDARD 11)

add_executable(MultiThreadProj main.cpp src/TsvFileHandler.cpp src/TsvFileHandler.h)
