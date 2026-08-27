#include <stdbool.h>
#include <stdio.h>

#include "levels.h"


// while loops should be in the levels
void levels(LEVEL* level) { 
    switch (*level) {
        case LEVEL1:
            level1();
            break;
        case LEVEL2:
            level2();
            break;
        case LEVEL3:
            level3();
            break;
        case LEVEL4:
            level4();
            break;
        case LEVEL5:
            level5();
            break;
    
    }
}

// Can use this in tandem with levels() function 
LEVEL levelSelect() { 
    int input;
    printf("ENTER LEVEL (1 - 5)\n"); 
    scanf("%d", &input);

    // return the level (-1 because enum)
    LEVEL level = input-1;

    return level;
}

void level1() {
    bool run = true;
    while (run) {
        printf("Level1 \n"); 
    }
}

void level2() {
    bool run = true;
    while (run) {
        printf("Level 2 \n"); 
    }
}

void level3() {
    bool run = true;
    while (run) {
        printf("Level 3 \n"); 
    }
}

void level4() {
    bool run = true;
    while (run) {
        printf("Level 4 \n"); 
    }
}

void level5() {
    bool run = true;
    while (run) {
        printf("Level 5 \n"); 
    }
}

