cmake_minimum_required(VERSION 3.4)
project(print)

set(PRINT_VERSION_MAJOR 0)
set(PRINT_VERSION_MINOR 1)
set(PRINT_VERSION_PATCH 0)
set(PRINT_VERSION_TWEAK 0)
set(PRINT_VERSION ${PRINT_VERSION_MAJOR}.${PRINT_VERSION_MINOR}.${PRINT_VERSION_PATCH}.${PRINT_VERSION_TWEAK})
set(PRINT_VERSION_STRING v${PRINT_VERSION})

option(BUILD_TESTS "Build tests" OFF)

add_library(print STATIC sources/print.cpp)
target_include_directories(print PUBLIC include)

install(TARGETS print ARCHIVE DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)

if(BUILD_TESTS)
  enable_testing()
  add_executable(check tests/test1.cpp)
  target_include_directories(check PRIVATE include)
  target_link_libraries(check print)
  add_test(NAME check COMMAND check)
endif()

include(CPackConfig.cmake)
