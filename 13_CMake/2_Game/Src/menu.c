// This is our menu
#include <stdio.h>
#include "game.h"

// this should return a gamestate type so that "game" knows what to do next
void mainMenu(GAMESTATE* gameState){ // we are going to change the game state in the functions that we call

    printf("WELCOME TO THE GAME\n");
    printf("========================\n");
    printf("1: Level Select\n");
    printf("2: Character Screen\n");
    printf("3: Settings\n");
    printf("4: Github\n");

    int input;
    scanf("%d", &input); // already a pointer, so no need for &gameState
    *gameState = input -1;

} 


void levelSelectScreen(LEVEL* level){
}


