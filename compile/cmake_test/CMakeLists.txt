cmake_minimum_required (VERSION 2.8)

project (cmake_test)

message("CMAKE_HOME_DIRECTORY is" ${CMAKE_HOME_DIRECTORY})

add_custom_target(clean
        COMMAND echo "CLEAN CURL"
        COMMAND make -C ${CMAKE_HOME_DIRECTORY}/third_party/curl clean
        COMMAND rm -rf ${CMAKE_HOME_DIRECTORY}/third_party/curl/output
        COMMAND cd ${CMAKE_HOME_DIRECTORY}/third_party/curl && git reset --hard

        COMMAND echo "CLEAN WOLFSSL"
        COMMAND make -C ${CMAKE_HOME_DIRECTORY}/third_party/wolfssl clean
        COMMAND rm -rf ${CMAKE_HOME_DIRECTORY}/third_party/wolfssl/output
        COMMAND cd ${CMAKE_HOME_DIRECTORY}/third_party/wolfssl && git reset --hard
        )

add_subdirectory(third_party)
add_subdirectory(src)

