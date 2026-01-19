#include "Obstacle.h"
int Obstacle::totalObstacles = 0;

Obstacle::Obstacle(int sx, int sy, int h) : x(sx), y(sy), height(h), scored(false) {
    totalObstacles++;
}
Obstacle::~Obstacle() {}

int Obstacle::getTotalObstacles() { return totalObstacles; }
void Obstacle::update() { x--; }
bool Obstacle::collidesWith(int l, int r, int t, int b) const {
    return !(r < x || l > x || b < y - height + 1 || t > y);
}
int Obstacle::getX() const { return x; }
bool Obstacle::isScored() const { return scored; }
void Obstacle::markScored() { scored = true; }
