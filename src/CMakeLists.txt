cmake_minimum_required(VERSION 3.24)

add_executable(Skillbox_30
        main.cpp
        use_lib.cpp
        solution_1.cpp
        )

target_link_libraries(Skillbox_30 PRIVATE cpr::cpr)
target_include_directories(Skillbox_30 PUBLIC ${INCLUDE_DIR})

# при возникновении этой ошибки - добавляем в настройку FetchContent_Declare( :: DOWNLOAD_EXTRACT_TIMESTAMP NEW
#  --->  cmake-build-debug/_deps/cpr-src/CMakeLists.txt:248 (FetchContent_Declare)
#FetchContent_Declare(
#        curl
#        URL                    https://github.com/curl/curl/releases/download/curl-7_80_0/curl-7.80.0.tar.xz
#        URL_HASH               SHA256=a132bd93188b938771135ac7c1f3ac1d3ce507c1fcbef8c471397639214ae2ab # the file hash for curl-7.80.0.tar.xz
#  --->  DOWNLOAD_EXTRACT_TIMESTAMP NEW
#        USES_TERMINAL_DOWNLOAD TRUE)   # <---- This is needed only for Ninja to show download progress


