#ifndef BOARD_H
#define BOARD_H

#include <vector>

class board {
private:
    int width;
    int height;
    std::vector<std::vector<char>> grid;

public:
    board(int w, int h);
    void clear();
    void setCell(int x, int y, char ch);
    char getCell(int x, int y) const;
    int getWidth() const;
    int getHeight() const;
    void draw() const;
};

#endif
