// this is a file with all of the types I need
#ifndef TYPES_H
#define TYPES_H

// Level types
typedef enum { 
    LEVEL1, // 0 - 5
    LEVEL2,
    LEVEL3,
    LEVEL4,
    LEVEL5,
} LEVEL;



// Game types
typedef enum {
    STATE_MENU,
    STATE_PLAY,
    STATE_LEVEL_SELECT,
    STATE_CHARACTER_SCREEN,
    STATE_SETTINGS,
    STATE_GITHUB,
    STATE_QUIT,
} GAMESTATE;

// in Headers, we don't want to allocate memory using "var name" so we will just give it a tag name
// The reason is that we don't want to allocate memory everything time we include this file

// will probably start this in the main loop
// (maybe make a game_init() and initializet here (allocate to the heap and return address)
typedef struct { 
    LEVEL levelNow;
    GAMESTATE stateNow;    
} GameTracker;

#endif
