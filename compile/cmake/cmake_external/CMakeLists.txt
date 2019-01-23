cmake_minimum_required (VERSION 2.8)

project (cmake_test)

message("CMAKE_HOME_DIRECTORY is" ${CMAKE_HOME_DIRECTORY})

execute_process(COMMAND ${CMAKE_C_COMPILER} -dumpmachine
                OUTPUT_VARIABLE TOOLCHAIN_TRIPLET
                OUTPUT_STRIP_TRAILING_WHITESPACE)

add_custom_target(clean
        COMMAND echo "CLEAN CURL"
        COMMAND echo "CLEAN WOLFSSL"
        )

add_subdirectory(third_party)
add_subdirectory(src)

