#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 20;
const int GROUND_Y = 15;

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

void printBuffer() {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++)
            cout << screen[y][x];
        cout << '\n';
    }
}

void hideCursor() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(h, &info);
}

void moveCursorToTopLeft() {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
}


class Obstacle {
protected:
    int x;
    int y;

public:
    Obstacle(int startX, int startY) : x(startX), y(startY) {}

    virtual void update() = 0;
    virtual void draw() const = 0;
    virtual bool collidesWith(int dx, int dy) const = 0;
};

class SmallCactus : public Obstacle {
public:
    SmallCactus()
        : Obstacle(SCREEN_WIDTH - 2, GROUND_Y) {
    }

    void update() override {
        x--;
        if (x < 0)
            x = SCREEN_WIDTH - 2;
    }

    void draw() const override {
        screen[y][x] = '|';
    }

    bool collidesWith(int dx, int dy) const override {
        return dx == x && dy == y;
    }
};

class Dino {
private:
    int x;
    int y;
    bool jumping;
    int velocity;

public:
    Dino() : x(5), y(GROUND_Y), jumping(false), velocity(0) {}

    void handleInput(char key) {
        if (key == ' ' && !jumping) {
            jumping = true;
            velocity = -4;
        }
    }

    void update() {
        if (jumping) {
            y += velocity;
            velocity++;
            if (y >= GROUND_Y) {
                y = GROUND_Y;
                jumping = false;
            }
        }
    }

    void draw() const {
        screen[y][x] = 'D';
    }

    int getX() const { return x; }
    int getY() const { return y; }
};

class Game {
private:
    Dino dino;
    Obstacle* obstacle;
    bool running;

public:
    Game() : running(true) {
        obstacle = new SmallCactus();
    }

    ~Game() {
        delete obstacle;
    }

    void run() {
        hideCursor();
        while (running) {
            processInput();
            update();
            render();
            Sleep(30);
        }
    }

private:
    void processInput() {
        if (_kbhit()) {
            char key = _getch();
            if (key == 27) running = false; 
            dino.handleInput(key);
        }
    }

    void update() {
        dino.update();
        obstacle->update();

        if (obstacle->collidesWith(dino.getX(), dino.getY())) {
            gameOver();
            running = false;
        }
    }

    void render() {
        clearBuffer();
        drawGround();
        dino.draw();
        obstacle->draw();
        moveCursorToTopLeft();
        printBuffer();
    }

    void gameOver() {
        system("cls");
        cout << "====================\n";
        cout << "     GAME OVER\n";
        cout << "====================\n";
        Sleep(1200);
    }
};

void showMenu() {
    system("cls");
    cout << "=============================\n";
    cout << "      CHROME DINO (OOP)\n";
    cout << "=============================\n\n";
    cout << "1. Start Game\n";
    cout << "2. Instructions\n";
    cout << "3. Exit\n\n";
    cout << "Odaberi opciju: ";
}

void showInstructions() {
    system("cls");
    cout << "=============================\n";
    cout << "        INSTRUCTIONS\n";
    cout << "=============================\n\n";
    cout << "SPACE  - jump\n";
    cout << "ESC    - exit game\n\n";
    cout << "Avoid the cactus by jumping over it.\n\n";
    cout << "Press any key to return to menu...";
    _getch();
}

int main() {
    hideCursor();
    bool runningApp = true;

    while (runningApp) {
        showMenu();
        char choice = _getch();

        switch (choice) {
        case '1': {
            Game game;
            game.run();
            break;
        }
        case '2':
            showInstructions();
            break;
        case '3':
            runningApp = false;
            system("cls");
            cout << "Exiting...\n";
            break;
        default:
            break;
        }
    }

    return 0;
}
