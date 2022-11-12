cmake_minimum_required(VERSION 3.20)
project(MultiThreadProj)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)

add_library(TsvFileHandler STATIC src/TsvFileHandler.cpp)
add_executable(MultiThreadProj main.cpp)
target_link_libraries(MultiThreadProj TsvFileHandler)

add_executable(TestRunner ut/tsvFileHandlerTest/TsvFileHandlerTest.cpp)
target_link_libraries(TestRunner TsvFileHandler gtest_main)
