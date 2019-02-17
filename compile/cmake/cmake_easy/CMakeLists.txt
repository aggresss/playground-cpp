cmake_minimum_required (VERSION 2.8)

project (cmake_test2)

message("====> CMAKE_HOME_DIRECTORY is" ${CMAKE_HOME_DIRECTORY})
MESSAGE(STATUS "====> HOME dir: $ENV{HOME}")

MESSAGE(STATUS "====> PROJECT_SOURCE_DIR dir: ${PROJECT_SOURCE_DIR}")

find_program(VALGRIND valgrind)
if (VALGRIND)
    message(STATUS "valgrind: ${VALGRIND}")
endif()

add_custom_target(custom
    COMMAND echo "TEST CUSTOM TARGET"
    )

option(WITH_OPTION "TEST OPTION" ON)

if (DEFINED $ENV{HOME})
    message("WITH_OPTION equ ON")
endif()

add_subdirectory(test)

