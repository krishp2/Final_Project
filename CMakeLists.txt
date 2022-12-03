cmake_minimum_required(VERSION 3.25.0)

# set the project name
project(test)


find_package(Catch2 REQUIRED)
add_executable(${PROJECT_NAME} main.cpp file_read.cpp Graph.cpp tests.cpp)
target_link_libraries(tests Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(tests)

# add the executable
