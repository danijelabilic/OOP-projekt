#pragma once
#include "Obstacle.h"

class BigCactus : public Obstacle {
public:
    BigCactus();
    void draw() const override;
};
