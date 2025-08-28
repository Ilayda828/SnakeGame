#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "board.h"
#include <utility>

class game {
private:
    board board;
    snake snake;
    std::pair<int, int> food;
    bool gameOver;
    int score;

    void placeFood();
    void update();
    void draw();

public:
    game(int width, int height);
    void run();
};

#endif
