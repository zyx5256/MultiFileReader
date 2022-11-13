cmake_minimum_required(VERSION 3.20)
project(MultiThreadProj)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)

add_library(TsvFileHandler src/fileHandler/TsvFileHandler.cpp)
add_library(Utils src/utils/utils.cpp)
add_library(MsgGenerator src/msgGenerator/MsgGenerator.cpp)

add_executable(MultiThreadProj main.cpp)
add_executable(TestRunner ut/tsvFileHandlerTest/TsvFileHandlerTest.cpp)

target_link_libraries(MultiThreadProj TsvFileHandler Utils MsgGenerator)
target_link_libraries(TestRunner TsvFileHandler gtest_main)
