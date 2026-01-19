#include "BigCactus.h"
#include "Game.h"

BigCactus::BigCactus() : Obstacle(SCREEN_WIDTH - 2, GROUND_Y, 6) {}
void BigCactus::draw() const {
    for (int i = 0; i < 6; i++)
        screen[y - i][x] = '|';
}
