#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <utility>

enum Direction { UP, DOWN, LEFT, RIGHT };

class snake {
private:
    std::deque<std::pair<int, int>> body;
    Direction dir;

public:
    snake(int startX, int startY);

    void move();
    void grow();
    bool isCollision(int x, int y);
    std::pair<int, int> getHead();
    const std::deque<std::pair<int, int>>& getBody() const;
    void setDirection(Direction newDir);
    Direction getDirection() const;
};

#endif
