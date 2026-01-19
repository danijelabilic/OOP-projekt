#include "Menu.h"
#include "Utils.h"
#include <iostream>

using namespace std;

void showMenu() {
    cout << "=============================\n";
    cout << "      CHROME DINO (OOP)\n";
    cout << "=============================\n\n";
    cout << "1. Start Game\n";
    cout << "2. Instructions\n";
    cout << "3. Exit\n\n";
    cout << "Odaberi opciju: ";
}

void showInstructions() {
    cout << "SPACE         - skok\n";
    cout << "SPACE + SPACE - dupli skok\n";
    cout << "P             - pauza\n";
    cout << "Cilj je sto duze preskakti kaktuse. Veliki kaktus je potrebno preskociti sa duplim skokom.\n\n";
    cout << "Pritisni bilo koju tipku...\n";
    _getch();
}
