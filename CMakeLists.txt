cmake_minimum_required(VERSION 3.16)
project(stb_project LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# stb 서브모듈 포함
add_subdirectory(libstb)
add_subdirectory(appstb)
