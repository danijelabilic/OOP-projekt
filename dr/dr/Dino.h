#pragma once

class Dino {
    int x, y, velocity, jumpsUsed;
    const int maxJumps = 2;

public:
    Dino();
    void handleInput(char key);
    void update();
    void draw() const;
    int left() const;
    int right() const;
    int top() const;
    int bottom() const;
};

