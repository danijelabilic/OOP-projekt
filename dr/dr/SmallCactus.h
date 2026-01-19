#pragma once
#include "Obstacle.h"
class SmallCactus : public Obstacle {
public:
    SmallCactus();
    void draw() const override;
};
