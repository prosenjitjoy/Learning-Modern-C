cmake_minimum_required(VERSION 3.31)

project(preprocessor LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(preprocessor main.c)
