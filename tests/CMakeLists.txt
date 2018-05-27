include_directories(${PROJECT_SOURCE_DIR})
add_executable(EventLoop_test EventLoop_test.cpp)
target_link_libraries(EventLoop_test thor)