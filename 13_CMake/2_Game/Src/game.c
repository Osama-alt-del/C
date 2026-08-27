// This is where the actual game is
#include <stdbool.h>
#include <stdio.h>

#include "game.h"
#include "menu.h"
#include "levels.h"

// this is the game loop:
void game(LEVEL* level) {  // we check the current level we wanna start at
    // have a title select screen here first
    GAMESTATE gameState;  // need to save this in a struct gameState = STATE_MENU;
    
    bool run;
    // constantly check the game state
    while (run) { 
        // this is the switch statement for the game states
        switch (gameState) {
            case STATE_MENU: 
                mainMenu(&gameState);
                
                break;
            case STATE_PLAY:
                levels(level); // the level of the GAME structure will change

                break;
            case STATE_LEVEL_SELECT: 
                LEVEL inputLevel;
                inputLevel = levelSelect(); 
                levels(&inputLevel); 
                
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
        }
    }

    // levels(level); (this is still not perfect)
}

