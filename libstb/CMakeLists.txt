cmake_minimum_required(VERSION 3.16)
project(libstb LANGUAGES C CXX)

# STB 경로를 submodule로 지정
set(STB_DIR ${CMAKE_SOURCE_DIR}/external/stb)

add_library(libstb STATIC
    stb_wrapper.cpp
    ${STB_DIR}/stb_vorbis.c
)

# stb 헤더를 include 경로로 지정
target_include_directories(libstb PUBLIC
    ${STB_DIR}
)

set_target_properties(libstb PROPERTIES
    OUTPUT_NAME stb
)
