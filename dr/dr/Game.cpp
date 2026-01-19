#include "Game.h"
#include "SmallCactus.h"
#include "BigCactus.h"
#include "Utils.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

char screen[SCREEN_HEIGHT][SCREEN_WIDTH];

void clearBuffer() {
    for (int y = 0; y < SCREEN_HEIGHT; y++)
        for (int x = 0; x < SCREEN_WIDTH; x++)
            screen[y][x] = ' ';
}

void drawGround() {
    for (int x = 0; x < SCREEN_WIDTH; x++)
        screen[GROUND_Y + 1][x] = '_';
}

Game::Game() : running(true), paused(false), score(0), gameDelay(30) {
    spawnObstacle();
}

Game::~Game() {
    for (auto o : obstacles) delete o;
}

void Game::run() {
    hideCursor();
    while (running) {
        processInput();
        update();
        render();
        sleepMs(gameDelay);
    }
    gameOver();
}

void Game::spawnObstacle() {
    try {
        if (rand() % 2)
            obstacles.push_back(new SmallCactus());
        else
            obstacles.push_back(new BigCactus());
    }
    catch (const bad_alloc&) {
        running = false;
        cout << "Greska: nema dovoljno memorije!\n";
    }
}

void Game::processInput() {
    if (_kbhit()) {
        char key = _getch();
        if (key == 27) running = false;
        if (key == 'p' || key == 'P') paused = !paused;
        if (!paused) dino.handleInput(key);
    }
}

void Game::update() {
    if (paused) return;
    dino.update();
    for (auto o : obstacles) o->update();
    if (!obstacles.empty() && obstacles.back()->getX() < dino.right() - 10)
        spawnObstacle();
    for (int i = 0; i < obstacles.size(); i++) {
        if (obstacles[i]->collidesWith(dino.left(), dino.right(), dino.top(), dino.bottom()))
            running = false;
        if (!obstacles[i]->isScored() && obstacles[i]->getX() < dino.left()) {
            score++;
            obstacles[i]->markScored();
            if (score % 5 == 0 && gameDelay > 10) gameDelay -= 5;
        }
        if (obstacles[i]->getX() < 0) {
            delete obstacles[i];
            obstacles.erase(obstacles.begin() + i);
            i--;
        }
    }
}

void Game::render() {
    clearBuffer();
    drawGround();
    dino.draw();
    for (auto o : obstacles) o->draw();
    string s = "Score: " + to_string(score);
    for (int i = 0; i < s.size(); i++) screen[0][i] = s[i];
    if (paused) {
        string p = "PAUSED";
        int startX = (SCREEN_WIDTH - p.size()) / 2;
        for (int i = 0; i < p.size(); i++)
            screen[SCREEN_HEIGHT / 2][startX + i] = p[i];
    }
    moveCursorToTopLeft();
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++)
            cout << screen[y][x];
        cout << '\n';
    }
}

void Game::gameOver() {
    moveCursorToTopLeft();
    cout << "\n====================\n";
    cout << "     GAME OVER\n";
    cout << "====================\n";
    cout << "Final score: " << score << "\n";
    cout << "Prepreka ukupno generirano u igri: " << Obstacle::getTotalObstacles() << "\n";
    cout << "\nPritisni bilo koju tipku za povratak u izbornik...";
    _getch();
}
