#include "Game.h"
#include "Utils.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    srand((unsigned)time(nullptr));
    hideCursor();
    bool runningApp = true;
    while (runningApp) {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
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
            break;
        }
    }
    return 0;
}
