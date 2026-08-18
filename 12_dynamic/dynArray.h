#ifndef DYN_ARRAY_H /* header guards */
#define DYN_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

/*

note about void type : 

a void * is like saying: "I'm a pointer to something, but I'm not telling you what"

so if I have: 

       | - void * ptr;
       | - *p; // I don't know what this is "how many bytes am I meant to be looking at ?
       | - p[3]; // same problem - I can't compute the offset because I don't know the size 
       | - p+1; // Can't computer one element without knowing element size

Using memcpy:
    void* memcpy(void* dest, const void* src, size_t n); // takes void for both dest and source
    
    // memcpy operates in terms of raw bytes instead of "elements". you tell it how many bytes to copy via "n" 
    // it just goes through the following logic:

    void* memcpy(void* dest, const void* src, size_t n) { 
        char * d = dest; // we set to char because the size of char is 1 byte, and we want to copy 1 byte at a time
        const char * s = src;  // set to const (principle of least privilege)
        
        // keep in mind that n is in size_t (which is in bytes)
        for ( size_t i = 0; i < n; i++) { 
            d[i] = s[i]; // copy the data into the destination array
        }

        return dest; // this is just for convenience;

    }

    so we can use memcpy for void *

*/


struct DynArray { 
    void* val; // pointer to the point in memory (void* to raw memory type-agnostic)
    int capacity; // number of values
    int length;  // index of the latest value in the array
    size_t elemSize; // Size of one element (need to save this so that we can use in realloc)
};


/* you can return structs from functions in C */
struct DynArray createDynArray(int size, size_t elementSize) { 
    struct DynArray arrData;
    arrData.elemSize = elementSize; // save the size of each individual element
    void* temp; /* For error checking */
    temp = malloc(size * arrData.elemSize); /* allocate memory */
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
        void* temp= realloc(arrData->val, arrData->elemSize);  
        if (temp == NULL) {  /* error checking */
            printf("[REALLOCATE MEMORY | ERROR] : Failed to reallocate memory \n");
        } else {
            arrData->val = temp;
            arrData->capacity = 1 ; /* the capacity is 1 */
        }
        return;
    }

    /* double memory if capacity not 0 */
    void* temp= realloc(arrData->val, arrData->capacity*2 * arrData->elemSize);
    if (temp == NULL) {  /* error checking */
        printf("[REALLOCATE MEMORY | ERROR] : Failed to reallocate memory \n");
    } else {
        arrData->val = temp;
        arrData->capacity *= 2; /* the capacity is now double */
    }

}

/* adding to the array (append) */
// need to make int value void * value and instead work with that, because we want it to be type -agnostic
void appendArray(struct DynArray* arrData, void* value) {  
    if (arrData->length < arrData->capacity) { /* Check if we can add a value */
        arrData->val[arrData->length] = *value; /* Add the value to the end of the array (apparently we cannot do this with void*?)*/
        arrData->length++;
    } else if (arrData->length >= arrData->capacity) { 
        reallocateMemory(arrData); /* reallocate memory */

        arrData->val[arrData->length] = *value; /* should have enough memory to add value */
        arrData->length++; 
    }
}

void getElement(struct DynArray* arrData,int index) { 
    // code to get a value from the dynamic array
}

#endif
