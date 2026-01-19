#include "Dino.h"
#include "Game.h"

Dino::Dino() : x(SCREEN_WIDTH / 2), y(GROUND_Y), velocity(0), jumpsUsed(0) {}

void Dino::handleInput(char key) {
    if (key == ' ' && jumpsUsed < maxJumps) {
        velocity = -3;
        jumpsUsed++;
    }
}

void Dino::update() {
    y += velocity;
    velocity++;
    if (y >= GROUND_Y) {
        y = GROUND_Y;
        velocity = 0;
        jumpsUsed = 0;
    }
}

void Dino::draw() const {
    screen[y - 2][x] = 'O';
    screen[y - 1][x - 1] = '/';
    screen[y - 1][x] = '|';
    screen[y - 1][x + 1] = '\\';
    screen[y][x - 1] = '/';
    screen[y][x + 1] = '\\';
}

int Dino::left() const { return x - 1; }
int Dino::right() const { return x + 1; }
int Dino::top() const { return y - 2; }
int Dino::bottom() const { return y; }
