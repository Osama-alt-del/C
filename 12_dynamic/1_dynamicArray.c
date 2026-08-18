#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dynArray.h"

void printArray(struct DynArray * arrData) {
    for (int i = 0; i < arrData->length; i++) { /* we will print all of the available values */
        printf("%d ", arrData->val[i]); 
    }
    printf("\n");
}


int main() { 
    struct DynArray array = createDynArray(0); // starts with a size of 0
    bool val = true;

    for (int i = 0; i < 10; i++) { 
        appendArray(&array, val);
    }



    printArray(&array);


    freeDynArray(&array);


    return 0;
}

