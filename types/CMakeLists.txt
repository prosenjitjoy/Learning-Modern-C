cmake_minimum_required(VERSION 3.31)

project(types LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(types main.c)

target_link_libraries(types PRIVATE m)
