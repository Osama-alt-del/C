#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dynArray.h"

/* To Do 
     - Make the interface for get element better (having to always return void pointer and then reassigning to the type that you want to assign to is really annoying to implement in code. 

     - Use the enum and typedef to write the types
     - Use only ELEMENT_TYPE and somehow figure out the size based on that. (maybe somehow link the enum constants like TYPE_INT with a size
     - can have another enum that's the same size and we can target the same "index" of the enum.
     - Need to figure out the size based onthe element TYPE


*/

int main() { 
    struct DynArray array = createDynArray(0, sizeof(bool)); // starts with a capacity of 0
    bool val = true;
    

    for (int i = 0; i < 5; i++) { 
        appendArray(&array, &val);
    }

    printArray(&array); // I want to be able to jump to definitions


    // let's print and see if we did it right:

    /*
    for ( int i = 0; i < array.length; i ++ ) { 
        bool* element = getElement(&array, i);
        printf("%d ", *element);
    }
    printf("\n");
    */

    freeDynArray(&array);


    return 0;
}

