#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dynArray.h"

/* To Do 
  - work out what to return when elementSize == 0 in create array (we can't return NULL)
        Will just set a value to NULL and then return a "bad" struct 
  - work out how to actually use the getelement function (we can't dereference to get the value if what we return is also a void pointer??
        you have to reassign it as a 


*/

int main() { 
    struct DynArray array = createDynArray(0, sizeof(bool)); // starts with a size of 0
    bool val = true;
    

    for (int i = 0; i < 5; i++) { 
        appendArray(&array, &val);
    }


    // let's print and see if we did it right:

    for ( int i = 0; i < array.length; i ++ ) { 
        bool* element = getElement(&array, i);
        printf("%d ", *element);
    }
    printf("\n");

    freeDynArray(&array);


    return 0;
}

