# This is mean to tell clangd know the compimler's configuration
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cmake_minimum_required(VERSION 3.10)

project(2_Game) 

set(CMAKE_BUILD_TYPE Debug)

# These are all of our executables
add_executable(${PROJECT_NAME} 
    Src/main.c
    Src/levels.c
    Src/menu.c
    Src/game.c
    
)

include_directories(Inc)

