# This file will make a Makefile. go into build, run cmake ..   when you run cmake --build in the build directory, it will make the build file compile the project.


# This is mean to tell clangd know the compimler's configuration
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cmake_minimum_required(VERSION 3.10)

# This isets the project name: 
project(Project1) 

# Mention all of the executables that should be compiled
add_executable(${PROJECT_NAME} 
    Src/main.c
    Src/function.c
)

# This makes it so whenever we include (either with "" or <>), our source code files can find the header files 
include_directories(Inc)

# ok so how does this know how to compile it?
#It just does apparently lol.



