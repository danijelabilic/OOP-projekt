#include "SmallCactus.h"
#include "Game.h"
SmallCactus::SmallCactus() : Obstacle(SCREEN_WIDTH - 2, GROUND_Y, 1) {}
void SmallCactus::draw() const { screen[y][x] = '|'; }
