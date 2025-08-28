cmake_minimum_required(VERSION 3.31)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 20)

add_executable(SnakeGame
        main.cpp
        game.cpp
        board.cpp
        snake.cpp
)
