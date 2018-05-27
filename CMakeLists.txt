project(thor)
cmake_minimum_required(VERSION 3.4)
set(SRCs EventLoop.cpp
        Thread.cpp)

set(FLAGS -Wall
          -std=c++11
          -Wno-unused-parameter
          -Wshadow)

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${FLAGS}")
message("inc dir " ${PROJECT_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}})
add_library(thor ${SRCs})
add_subdirectory(tests)