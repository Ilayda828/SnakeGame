#include "snake.h"

snake::snake(int startX, int startY) {
    body.push_front({startX, startY});
    dir = RIGHT;
}

void snake::move() {
    auto head = body.front();
    switch (dir) {
        case UP:    head.second--; break;
        case DOWN:  head.second++; break;
        case LEFT:  head.first--; break;
        case RIGHT: head.first++; break;
    }
    body.push_front(head);
    body.pop_back();
}

void snake::grow() {
    auto tail = body.back();
    body.push_back(tail); // basitçe son konumu tekrar ekliyoruz
}

bool snake::isCollision(int x, int y) {
    for (auto& segment : body) {
        if (segment.first == x && segment.second == y)
            return true;
    }
    return false;
}

std::pair<int, int> snake::getHead() {
    return body.front();
}

const std::deque<std::pair<int, int>>& snake::getBody() const {
    return body;
}

void snake::setDirection(Direction newDir) {
    // ters yöne gitmeyi engelle
    if ((dir == UP && newDir == DOWN) || (dir == DOWN && newDir == UP) ||
        (dir == LEFT && newDir == RIGHT) || (dir == RIGHT && newDir == LEFT))
        return;
    dir = newDir;
}

Direction snake::getDirection() const {
    return dir;
}
