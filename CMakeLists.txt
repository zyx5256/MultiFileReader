cmake_minimum_required(VERSION 3.20)
project(MultiThreadProj)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)

add_library(TsvFileHandler src/fileHandler/TsvFileHandler.cpp)
add_library(Utils src/utils/CommonUtils.cpp src/utils/Log.cpp)
add_library(MsgGenerator src/msgGenerator/MsgGenerator.cpp)

add_executable(MultiThreadProj main.cpp)
target_link_libraries(MultiThreadProj TsvFileHandler Utils MsgGenerator)

add_executable(TestFileHandler ut/FileHandlerTest.cpp)
target_link_libraries(TestFileHandler TsvFileHandler gtest_main)

add_executable(TestFileLog ut/LogTest.cpp)
target_link_libraries(TestFileLog Utils gtest_main)
