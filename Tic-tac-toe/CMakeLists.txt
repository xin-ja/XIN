cmake_minimum_required(VERSION 4.0)
project(Tic-tac-toe C)

set(CMAKE_C_STANDARD 11)

add_executable(Tic-tac-toe main.c
        game.c
        game.h
)
