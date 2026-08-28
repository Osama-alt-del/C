// This is the main game loop for the program
#include "game.h"

int main() { 
    GameTracker gT;

    // start at the main menu
    gT.stateNow = STATE_MENU;

    // just for now we will say that the level is 1
    gT.levelNow = LEVEL1;


    game(&gT); // run the game loop
    
    return 0;
}


