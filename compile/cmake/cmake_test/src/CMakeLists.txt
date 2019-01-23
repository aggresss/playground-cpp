cmake_minimum_required (VERSION 2.8)

project(cmake_test)

set (CURL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/curl/output/${HOST})
include_directories("${CURL_PATH}/include")
link_directories("${CURL_PATH}/lib")

set (WOLFSSL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/wolfssl/output/${HOST})
include_directories("${WOLFSSL_PATH}/include")
link_directories("${WOLFSSL_PATH}/lib")

add_executable(test_curl.out
    getinfo.c
)

target_link_libraries(test_curl.out curl wolfssl m pthread)

