cmake_minimum_required(VERSION 3.24)
project("Skillbox_30" VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)

set(CPR_BUILD_TESTS OFF)
set(CPR_ENABLE_SSL ON)
set(CPR_BUILD_TESTS_SSL OFF)
set(CPR_GENERATE_COVERAGE OFF)
set(CPR_CURL_NOSIGNAL OFF)
set(CPR_USE_SYSTEM_GTEST OFF)
set(CPR_FORCE_USE_SYSTEM_CURL OFF)
set(CPR_FORCE_OPENSSL_BACKEND OFF)
set(CPR_FORCE_WINSSL_BACKEND OFF)
set(CPR_FORCE_DARWINSSL_BACKEND OFF)
set(CPR_FORCE_MBEDTLS_BACKEND OFF)
set(CPR_ENABLE_LINTING OFF)
set(CPR_ENABLE_CPPCHECK OFF)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 871ed52d350214a034f6ef8a3b8f51c5ce1bd400) # The commit hash for 1.9.0. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)

