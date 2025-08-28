# SnakeGame
A classic Snake game implementation written in C++ with terminal-based graphics.

## Features

🐍 Classic Snake gameplay
🎮 WASD controls
🏆 Score tracking
🖥️ Terminal-based graphics
🧱 Collision detection (walls and self)
🍎 Random food placement

## Requirements

C++20 compatible compiler (GCC, Clang, or MSVC)
CMake 3.31 or higher
Unix-like system (Linux/macOS)

## Building the Game

### Clone the repository:

bashgit clone <repository-url>
cd SnakeGame

### Create build directory and compile:

bashmkdir build
cd build
cmake ..
make

### Run the game:

bash./SnakeGame

## How to Play

W - Move up
A - Move left
S - Move down
D - Move right

## Objective

Control the snake to eat food ('F')
Avoid hitting walls or your own body
Each food eaten increases your score by 10 points

## Game Elements

O - Snake head
o - Snake body
F - Food
# - Walls

