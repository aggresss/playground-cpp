cmake_minimum_required (VERSION 2.6)

project (cmake_example)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D__FILE_NAME__='\"$(subst ${CMAKE_SOURCE_DIR}/,,$(abspath $<))\"'")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__FILE_NAME__='\"$(subst ${CMAKE_SOURCE_DIR}/,,$(abspath $<))\"'")
add_executable(cmake_example test_log.c log.c)
