#pragma once
class Obstacle {
protected:
    int x, y, height;
    bool scored;
    static int totalObstacles;

public:
    Obstacle(int sx, int sy, int h);
    virtual ~Obstacle();
    static int getTotalObstacles();
    virtual void update();
    virtual void draw() const = 0;
    bool collidesWith(int l, int r, int t, int b) const;
    int getX() const;
    bool isScored() const;
    void markScored();
};
