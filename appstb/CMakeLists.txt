cmake_minimum_required(VERSION 3.16)
project(appstb LANGUAGES CXX)

add_executable(appstb main.cpp)
target_link_libraries(appstb PRIVATE libstb)
