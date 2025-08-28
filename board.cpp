#include "board.h"
#include <iostream>

board::board(int w, int h) : width(w), height(h), grid(h, std::vector<char>(w, ' ')) {}

void board::clear() {
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            grid[y][x] = ' ';
}

void board::setCell(int x, int y, char ch) {
    if (x >= 0 && x < width && y >= 0 && y < height)
        grid[y][x] = ch;
}

char board::getCell(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height)
        return grid[y][x];
    return ' ';
}

int board::getWidth() const {
    return width;
}

int board::getHeight() const {
    return height;
}

void board::draw() const {
    system("cls"); // Windows için ekranı temizler, Linux/Mac'te "clear" olabilir
    for (int i = 0; i < width + 2; i++) std::cout << '#';
    std::cout << std::endl;

    for (int y = 0; y < height; y++) {
        std::cout << '#';
        for (int x = 0; x < width; x++) {
            std::cout << grid[y][x];
        }
        std::cout << '#' << std::endl;
    }

    for (int i = 0; i < width + 2; i++) std::cout << '#';
    std::cout << std::endl;
}
