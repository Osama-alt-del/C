cmake_minimum_required(VERSION 3.10)
project(Project1)

add_executable(${PROJECT_NAME} Src/main.c)


# This makes it so whenever we include (either with "" or <>), our source code files can find the header files 
include_directories(Inc)



