#ifndef LEVELS_H
#define LEVELS_H
// This is a file for the enumerator for the levels

typedef enum { 
    LEVEL1, // 0 - 5
    LEVEL2,
    LEVEL3,
    LEVEL4,
    LEVEL5,
} LEVEL;

// LEVEL is an alias that represents the enum with all of the levels.

void levels(LEVEL* level);

// here are our actual level values
void level1();
void level2();
void level3();
void level4();
void level5();
#endif
