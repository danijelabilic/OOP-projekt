#pragma once
#include <vector>
#include "Dino.h"
#include "Obstacle.h"

using namespace std;

extern char screen[20][80];
const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 20;
const int GROUND_Y = 15;

void showMenu();
void showInstructions();

class Game {
    Dino dino;
    vector<Obstacle*> obstacles;
    bool running;
    bool paused;
    int score;
    int gameDelay;

public:
    Game();
    ~Game();
    void run();

private:
    void spawnObstacle();
    void processInput();
    void update();
    void render();
    void gameOver();
};

