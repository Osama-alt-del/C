// This is our menu
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "menu.h"
#include "types.h"

void clearStdin() { 
    int c; // making it int so that we can "represent" EOF
    // clear the stdin queue (getchar() for all values)
    while (((c = getchar()) != EOF) && (c != '\n')) { 
    };
}

// mainMenu has STATE_QUIT because it helps exiting the entire game. other menues do not have this state, and they simply change the game state to mainMenu when you exit them.

// this is why other menues do not need to involve enumerators that have a QUIT_STATE (for example,  we have LEVE1-5 for levels, but we don't have a quit state, because we don't need it, just go back to menu if you press 0)
void mainMenu(GameTracker* gT){ 
    int input = -1; // make it something invalid for now 
        
    int lowerB = 0;
    int higherB = 6;
    bool invalidInput = false; // at the start it's false

    // keep going so long as input is invalid
    // a problem with this code appears when we enter anything that isn't an integer.
    while ((input < lowerB ) || (input > higherB)){
        system("clear");
        printf("|=====================|\n");
        printf("  WELCOME TO THE GAME\n");
        printf("========================\n");
        printf("1: Play LV%d\n", gT->levelNow+1); // start from lv1 (or saved level)
        printf("2: Level Select\n");
        printf("3: Character Screen\n");
        printf("4: Settings\n");
        printf("5: Github & Credits\n");
        printf("\n");
        printf("0: QUIT\n");

        if (invalidInput) { 
            printf("===============\n");
            printf("!INVALID INPUT!\n");
        }

        scanf("%d", &input);  // this is skipped the second time??

        if ( (input < lowerB) || (input > higherB) ) { 
            clearStdin();
            invalidInput = true;

            // now that we have cleared the stdin stream and we have set invalid input to ture, we should be safe
        }
        
    }

    gT->stateNow = input; // because first state is menu

    clearStdin(); // clear at the end as well for safety
    return;
} 

// Level select screen is a "menu"
void levelSelectScreen(GameTracker* gT){
    int input = -1; // make it something invalid for now 
        
    int lowerB = 0; // because 0 is exit
    int higherB = 5;
    bool invalidInput = false; // at the start it's false

    // keep going so long as input is invalid
    // a problem with this code appears when we enter anything that isn't an integer.
    while ((input < lowerB ) || (input > higherB)){
        system("clear");
        printf("LEVEL SELECT\n");
        printf("========================\n");
        printf("1: LEVEL 1\n");
        printf("2: LEVEL 2\n");
        printf("3: LEVEL 3\n");
        printf("4: LEVEL 4\n");
        printf("5: LEVEL 5\n");
        printf("\n");
        printf("0: Main Menu\n"); // make 0 the "back number later"
        
        if (invalidInput) { 
            printf("===============\n");
            printf("!INVALID INPUT!\n");
        }

        scanf("%d", &input);  // this is skipped the second time??

        if ( (input < lowerB) || (input > higherB) ) { 
            clearStdin();
            invalidInput = true;
        }
    }

    // input -1 because lv1 is == 0
    // check if we didn't just hit exit
    if (input != 0) {
        gT->levelNow = input-1; 
    }

    // go back to the menu
    gT->stateNow = STATE_MENU;

    clearStdin(); // clear at the end as well for safety
    return;
}

// By that logic settings should also be here:
void settingsScreen(GameTracker* gT){
    system("clear");
    printf("|=====================|\n");
    printf("SETTINGS_SCREEN PAGE (press anything to go back)\n");



    int input;
    scanf("%d", &input);

    // do something with the input here:

    gT->stateNow = STATE_MENU; // go back after any input

    clearStdin(); // clear at the end as well for safety
    return;
}

void characterSelectScreen(GameTracker* gT) { 
    system("clear");
    printf("|=====================|\n");
    printf("CHARACTER_SCREEN PAGE (press anything to go back)\n");

    int input;
    scanf("%d", &input);

    // do something with the input here:

    gT->stateNow = STATE_MENU; // go back after any input

    clearStdin(); // clear at the end as well for safety
    return;
}

void githubScreen(GameTracker *gT){
    system("clear");
    printf("|=====================|\n");
    printf("GITHUB PAGE (press anything to go back)\n");

    int input;
    scanf("%d", &input);

    // do something with the input here:
    gT->stateNow = STATE_MENU; // go back after any input

    clearStdin(); // clear at the end as well for safety
    return;
}
