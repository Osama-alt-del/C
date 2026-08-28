// This is where the actual game is
#include <stdbool.h>
#include <stdio.h>

#include "game.h"
#include "menu.h"
#include "levels.h"
#include "types.h"

// this is the game loop:
void game(GameTracker* gT) {  // we check the current level we wanna start at
    // have a title select screen here first
    // printf("%d\n", gT->stateNow);
    
    bool run = true;
    // constantly check the game state
    while (run) { 
        // this is the switch statement for the game states
        switch (gT->stateNow) {
            case STATE_MENU: 
                mainMenu(gT);
                
                break;
            case STATE_PLAY:
                playLevels(gT); // run the levels based on current level
                break;
            case STATE_LEVEL_SELECT: 
                levelSelectScreen(gT);
                
                break;
            case STATE_CHARACTER_SCREEN: 
                printf("CHARACTER_SCREEN PAGE\n");
                
                break;
            case STATE_SETTINGS: 
                printf("STATE_SETTINGS PAGE\n");
                
                break;
            case STATE_GITHUB: 
                printf("GITHUB PAGE\n");
                
                break;
            case STATE_QUIT: 
                run = false; // quit the game
                break;

            default:
                break;
        }
    }

    // levels(level); (this is still not perfect)
}

