cmake_minimum_required(VERSION 3.23)
project(MultiThreadProj)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG release-1.12.1
)
FetchContent_GetProperties(googletest)
if (NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

add_library(TsvFileHandler STATIC src/TsvFileHandler.cpp)
add_executable(MultiThreadProj main.cpp)
target_link_libraries(MultiThreadProj TsvFileHandler)

add_executable(MultiThreadProjTest ut/TsvFileHandlerTest.cpp)
target_link_libraries(MultiThreadProjTest TsvFileHandler)
