#ifndef MENU_H
#define MENU_H

// this is our meny header file (declarations)
#include "types.h"

// helper function to clear the input stream
void clearStdin(void);

// main menu
void mainMenu(GameTracker* gT); 

// level select manu
void levelSelectScreen(GameTracker* gT);

// also a menu
void settingsScreen(GameTracker* gT);

// also a menu
void characterSelectScreen(GameTracker* gT);

// github screen is also a menu
void githubScreen(GameTracker* gT);

#endif
