#ifndef DYN_ARRAY_H /* header guards */
#define DYN_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

struct DynArray { 
    int* val; // pointer to the point in memory
    int capacity; // number of values
    int length;  // index of the latest value in the array
};

/* you can return structs from functions in C */
struct DynArray createDynArray(int size) { 
    struct DynArray arrData;
    int* temp; /* For error checking */
    temp = (int *)malloc(size * sizeof(int)); /* allocate memory */
    arrData.capacity = size; /* number of values */
    arrData.length = 0; /* the length will start at the end */
    
    if (temp == NULL) { 
        printf("[CREATE DYN ARRAY | ERROR] : Failed to allocate memory \n");
    } else {
        arrData.val = temp; /* point to the allocated memory */
    }
    return arrData; /* return the arrData structure */
}


void freeDynArray(struct DynArray* arrData){ 
    free(arrData->val);
}

/* Function to reallocate memory */
void reallocateMemory(struct DynArray* arrData) { 
    /* if size is 0, then make it 1 and return */
    if (arrData->capacity == 0) { 
        int* temp= realloc(arrData->val, sizeof(*arrData->val));
        if (temp == NULL) {  /* error checking */
            printf("[REALLOCATE MEMORY | ERROR] : Failed to reallocate memory \n");
        } else {
            arrData->val = temp;
            arrData->capacity = 1 ; /* the capacity is 1 */
        }
        return;
    }

    /* double memory if capacity not 0 */
    int* temp= realloc(arrData->val, arrData->capacity*2 * sizeof(*arrData->val));
    if (temp == NULL) {  /* error checking */
        printf("[REALLOCATE MEMORY | ERROR] : Failed to reallocate memory \n");
    } else {
        arrData->val = temp;
        arrData->capacity *= 2; /* the capacity is now double */
    }

}

/* adding to the array (append) */
void appendArray(struct DynArray* arrData, int value) { 
    if (arrData->length < arrData->capacity) { /* Check if we can add a value */
        arrData->val[arrData->length] = value; /* Add the value to the end of the array */
        arrData->length++;
    } else if (arrData->length >= arrData->capacity) { 
        reallocateMemory(arrData); /* reallocate memory */

        arrData->val[arrData->length] = value; /* should have enough memory to add value */
        arrData->length++; 
    }
}

#endif
