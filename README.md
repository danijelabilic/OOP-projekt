# OOP-projekt
CHROME DINO RUN - KONZOLNA ASCII IGRICA

Kako pokrenuti projekt:
Windows
1. Napravi prazan projekt u Visual Studio 2022
2. Dodaj sve .cpp i .h datoteke u projekt.
3. Buildaj projekt i pokreni.

Linux
1. Otvori terminal u direktoriju projekta.
2. Compile sve datoteke:
   ```bash
   g++ main.cpp Utils.cpp Menu.cpp Game.cpp Dino.cpp Obstacle.cpp SmallCactus.cpp BigCactus.cpp -o dino_game
3. Pokreni igricu
   ./dino_game

Kontrole u igri:
SPACE – skok
SPACE + SPACE – dupli skok (za velike kaktuse)
P – pauza / nastavak
ESC – izlaz iz igre

Ovisnosti:
Samostalni C++ projekt bez vanjskih biblioteka.
Projekt radi na Windows i Linux konzoli.

Rješenja za moguće probleme:
to_string nije prepoznat → Postaviti standard C++17 ili noviji u Visual Studiju.
Problemi s _kbhit i _getch na Linuxu → Implementirano u Utils.cpp za cross-platform kompatibilnost.
