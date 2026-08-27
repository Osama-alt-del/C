#ifndef GAME_H
#define GAME_H

#include "levels.h"

// game loop declaration
void game(LEVEL* level);

typedef enum {
    STATE_MENU,
    STATE_LEVEL_SELECT,
    STATE_CHARACTER_SCREEN,
    STATE_SETTINGS,
    STATE_GITHUB,
} GAMESTATE;

#endif
