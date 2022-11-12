cmake_minimum_required(VERSION 3.20)
project(MultiThreadProj)

set(CMAKE_CXX_STANDARD 14)
include_directories(lib/googletest/googletest/include)

add_library(TsvFileHandler STATIC src/TsvFileHandler.cpp)
add_executable(MultiThreadProj main.cpp)
target_link_libraries(MultiThreadProj TsvFileHandler)

add_executable(MultiThreadProjTest ut/TsvFileHandlerTest.cpp)
target_link_libraries(MultiThreadProjTest TsvFileHandler)
