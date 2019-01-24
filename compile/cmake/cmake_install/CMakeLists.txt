cmake_minimum_required (VERSION 2.6)

project (cmake_example)

add_executable(cmake_example cmake_example.cpp)

INSTALL(TARGETS ${CMAKE_PROJECT_NAME} RUNTIME DESTINATION bin)
