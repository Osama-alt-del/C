#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dynArray.h"

/* To Do 
    // write a documentation on how to use the header in the header file
    // add new file to include (MAKE SURE YOU TALK ABOUT HOW TO PROPERLY USE GET VAL
    // make this a global header file you can use anywhere
    // separate the definition from the declaration
*/

int main() { 
    DynArray array = createDynArray(0, TYPE_CHAR); // starts with a capacity of 0
    char val = 'a';
    

    for (int i = 0; i < 5; i++) { 
        appendArray(&array, &val);
    }

    printArray(&array); // I want to be able to jump to definitions

    // this is just for reference for the documentation
    char * test = getElement(&array, 4);
    printf("%c\n", *test);



    freeDynArray(&array);


    return 0;
}

