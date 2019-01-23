cmake_minimum_required (VERSION 2.8)

project (cmake_test)

message("CMAKE_HOME_DIRECTORY is" ${CMAKE_HOME_DIRECTORY})

add_custom_target(clean
        COMMAND echo "CLEAN CURL"
        COMMAND cd ${CMAKE_HOME_DIRECTORY}/third_party/curl && git clean -dxf

        COMMAND echo "CLEAN WOLFSSL"
        COMMAND cd ${CMAKE_HOME_DIRECTORY}/third_party/wolfssl && git clean -dxf
        )

add_subdirectory(third_party)
add_subdirectory(src)

