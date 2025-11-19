cmake_minimum_required(VERSION 3.31)

project(operators LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(operators main.c
    main.h)
