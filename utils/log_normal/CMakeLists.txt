cmake_minimum_required(VERSION 2.6)

project(LOG)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D__FILE_NAME__='\"$(subst ${CMAKE_SOURCE_DIR}/,,$(abspath $<))\"'")
add_definitions("-D__PROJECT__=\"[${CMAKE_PROJECT_NAME}]\"")
add_executable(cmake_example test_log.c log.c)
