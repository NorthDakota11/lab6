cmake_minimum_required(VERSION 3.4)
project(solver_package)

set(PACKAGE_VERSION_MAJOR 0)
set(PACKAGE_VERSION_MINOR 1)
set(PACKAGE_VERSION_PATCH 0)
set(PACKAGE_VERSION_TWEAK 0)
set(PACKAGE_VERSION_FULL ${PACKAGE_VERSION_MAJOR}.${PACKAGE_VERSION_MINOR}.${PACKAGE_VERSION_PATCH}.${PACKAGE_VERSION_TWEAK})

option(BUILD_TESTS "Build tests" OFF)

add_library(formatter STATIC formatter_lib/sources/formatter.cpp)
target_include_directories(formatter PUBLIC formatter_lib/include)

add_library(solver_lib STATIC solver_lib/calc.cc)
target_include_directories(solver_lib PUBLIC solver_lib)

add_executable(solver solver_application/app.cc)
target_link_libraries(solver solver_lib formatter)

install(TARGETS formatter solver_lib solver
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin)
install(DIRECTORY formatter_lib/include/ DESTINATION include)
install(DIRECTORY solver_lib/ DESTINATION include FILES_MATCHING PATTERN "*.hpp")

if(BUILD_TESTS)
  enable_testing()
  add_test(NAME solver_runs COMMAND solver)
endif()

include(CPackConfig.cmake)
