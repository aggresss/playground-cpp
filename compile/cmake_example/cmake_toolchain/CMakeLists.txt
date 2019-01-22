cmake_minimum_required (VERSION 2.8)

project (cmake_toolchain)

message(STATUS "${PROJECT_SOURCE_DIR}")

message("${CMAKE_C_COMPILER}")

execute_process(COMMAND ${CMAKE_C_COMPILER} -dumpmachine
                OUTPUT_VARIABLE TOOLCHAIN_TRIPLET
                OUTPUT_STRIP_TRAILING_WHITESPACE)

message(STATUS "toolchain triplet: ${TOOLCHAIN_TRIPLET}")

add_definitions("-Wall -g")
aux_source_directory(./src SRC_LIST)
add_executable(cmake_toolchain ${SRC_LIST})
