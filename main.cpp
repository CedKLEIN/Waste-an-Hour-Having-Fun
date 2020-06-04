#include <iostream>
#include "game.hpp"
#include "utility.hpp"

using namespace std;

int main() {

    utility::cleanConsole();

    while(true) {

        Game aNewGame;
        if (aNewGame.callMenu()) {
            aNewGame.startGame();
        }
        
        // Exit
        if (aNewGame.isExitGame()) {
            return 0;
        }
    }
    
    return 0;
}