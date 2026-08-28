// This is our menu
#include <stdio.h>
#include "menu.h"
#include "types.h"

// this should return a gamestate type so that "game" knows what to do next

// right now this is the only place where we can change gameState
void mainMenu(GameTracker* gT){ // we are going to change the game state in the functions that we call

    printf("WELCOME TO THE GAME\n");
    printf("========================\n");
    // printf("0: Menu\n");
    printf("1: Play LV%d\n", gT->levelNow+1); // start from lv1 (or saved level)
    printf("2: Level Select\n");
    printf("3: Character Screen\n");
    printf("4: Settings\n");
    printf("5: Github\n");
    printf("6: QUIT\n");

    int input;
    scanf("%d", &input); 

    gT->stateNow = input;
    return;
} 

// Level select screen is a "menu"
void levelSelectScreen(GameTracker* gT){
    printf("LEVEL SELECT\n");
    printf("========================\n");
    printf("1: LEVEL 1\n");
    printf("2: LEVEL 2\n");
    printf("3: LEVEL 3\n");
    printf("4: LEVEL 4\n");
    printf("5: LEVEL 5\n");

    int input;
    scanf("%d", &input); 

    // input -1 because lv1 is == 0
    gT->levelNow = input-1; 

    // go back to the menu
    gT->stateNow = STATE_MENU;
    return;
}
