cmake_minimum_required(VERSION 2.8)
project(oldschler)

set(PROJECT_RUNTIME_DIR ${PROJECT_SOURCE_DIR}/rt)
set(PROJECT_UTIL_DIR ${PROJECT_SOURCE_DIR}/util)

include_directories("${PROJECT_RUNTIME_DIR}")
include_directories("${PROJECT_UTIL_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

add_subdirectory(tests)

enable_testing()
add_test(NAME oldschler_test COMMAND ${CMAKE_CURRENT_BINARY_DIR}/tests/test)
