#ifndef GAME_H
#define GAME_H

#include "types.h"

// to fix the mutual inclusion problem, I will put all types in a types.h file


// game loop declaration
// call by reference to game tracker
void game(GameTracker* gT); 



#endif
