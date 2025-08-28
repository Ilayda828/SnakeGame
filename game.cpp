#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>     // usleep için
#include <termios.h>    // kbhit ve getch için
#include <fcntl.h>

// Linux/macOS için _kbhit alternatifi
int kbhit() {
    termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

// Linux/macOS için _getch alternatifi
char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0) perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0) perror ("tcsetattr ~ICANON");
    return buf;
}

game::game(int width, int height)
    : board(width, height), snake(width / 2, height / 2), gameOver(false), score(0) {
    srand(time(0));
    placeFood();
}

void game::placeFood() {
    int x, y;
    do {
        x = rand() % board.getWidth();
        y = rand() % board.getHeight();
    } while (snake.isCollision(x, y));
    food = {x, y};
}

void game::update() {
    snake.move();

    auto head = snake.getHead();

    // Duvara çarpma kontrolü
    if (head.first < 0 || head.first >= board.getWidth() || head.second < 0 || head.second >= board.getHeight()) {
        gameOver = true;
        return;
    }

    // Kendine çarpma kontrolü
    auto body = snake.getBody();
    for (size_t i = 1; i < body.size(); i++) {
        if (body[i] == head) {
            gameOver = true;
            return;
        }
    }

    // Yem yeme kontrolü
    if (head == food) {
        score += 10;
        snake.grow();
        placeFood();
    }
}

void game::draw() {
    board.clear();

    // Yem
    board.setCell(food.first, food.second, 'F');

    // Yılan
    const auto& body = snake.getBody();
    bool isHead = true;
    for (auto& segment : body) {
        board.setCell(segment.first, segment.second, isHead ? 'O' : 'o');
        isHead = false;
    }

    board.draw();

    std::cout << "Score: " << score << std::endl;
}

void game::run() {
    while (!gameOver) {
        if (kbhit()) {
            char key = getch();
            switch (key) {
                case 'w': snake.setDirection(UP); break;
                case 's': snake.setDirection(DOWN); break;
                case 'a': snake.setDirection(LEFT); break;
                case 'd': snake.setDirection(RIGHT); break;
            }
        }

        update();
        draw();

        usleep(100000);  // 100 ms bekle
    }

    std::cout << "Game Over! Final Score: " << score << std::endl;
}
