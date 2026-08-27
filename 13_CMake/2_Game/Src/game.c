// This is where the actual game is
#include <stdbool.h>

#include "menu.h"
#include "levels.h"

// this is the game loop:
void game(LEVEL* level) {  // we check the current level we wanna start at
    // have a title select screen here first
    // <---WORKING HERE
    mainMenu(GAMESTATE *gameState);

    switch (level) {
    
    }

    levels(level);
}

