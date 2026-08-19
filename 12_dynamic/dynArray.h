#ifndef DYN_ARRAY_H /* header guards */
#define DYN_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for memcpy

/*

// isn't this more like a linked list???

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

    so we can use memcpy for void * like so:


        // we can use char* so that teh compiler isn't confused and also so that when we do pointer arithmetic, the compiler doesn't implicitly scale the arithmetic (if we use int* as a conversion, then the compiler might go ahead and multiply the offset by 4)

        // make sure you do a check to see if we have enough memory to insert the new value before this.
        - void* dest = (char*)arrData->val + (arrData->length * arrData->elemSize); // next empty slot
        - memcpy(dest, value, arrData->elemSize);  // write new value there
        - arrData->length++;  // NOW length reflects the new count, and also points to the *next* empty slot after this one

*/


struct DynArray { 
    void* val; // pointer to the point in memory (void* to raw memory type-agnostic)
    int capacity; // number of values
    int length;  // index of the latest value in the array
    size_t elemSize; // Size of one element (need to save this so that we can use in realloc)
};


/* you can return structs from functions in C */
struct DynArray createDynArray(int size, size_t elementSize) { 
    // making sure the elementSize isn't 0
    if (elementSize == 0 ) { 
        printf("[CREATE DYN ARRAY | ERROR] Invalid Size of Element\n");
        struct DynArray arrData;
        // make everythin null
        arrData.elemSize = 0; 
        arrData.length = 0;
        arrData.capacity = 0;
        arrData.val = 0;
        return arrData; /* return the useless arrData */
    }


    struct DynArray arrData;
    arrData.elemSize = elementSize; // save the size of each individual element
    void* temp; /* For error checking */
    temp = malloc(size * arrData.elemSize); /* allocate memory */
    arrData.capacity = size; /* number of values */
    arrData.length = 0; /* the length will start at the end */
    
    if (temp == NULL) { 
        printf("[CREATE DYN ARRAY | ERROR] : Failed to allocate memory \n");
        // Make it a useless arrData
        arrData.elemSize = 0; 
        arrData.length = 0;
        arrData.capacity = 0;
        arrData.val = 0;
        return arrData;  /* return the useless arrData */
    } else {
        arrData.val = temp; /* point to the allocated memory */
    }
    return arrData; /* return the arrData structure */
}


void freeDynArray(struct DynArray* arrData){ 
    free(arrData->val);
}

/* Function to reallocate memory */
/* REALLOC IS EXPENSIVE it's O(n) to copy every block to a bigger block of contiguous memory, 
so we don't want to call it all the time */
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
        return;
    } else {
        arrData->val = temp;
        arrData->capacity *= 2; /* the capacity is now double */
        return;
    }

}

/* adding to the array (append) */
// need to make int value void * value and instead work with that, because we want it to be type -agnostic
void appendArray(struct DynArray* arrData, void* value) {  
    if (arrData->length < arrData->capacity) { /* Check if we can add a value */
        
        // know the data address that we want to add to: (must start with char*, so the compiler does not scale by some type size)
        void * dest = (char*) arrData->val + (arrData->elemSize * arrData->length); // figure out the "next address" we want to add to 
        memcpy(dest, value, arrData->elemSize); // copy the data from the input value into the next address in the array
        arrData->length++; // now represents new length
        return;

    } else if (arrData->length >= arrData->capacity) { 
        reallocateMemory(arrData); /* reallocate memory */

        void * dest = (char*) arrData->val + (arrData->elemSize * arrData->length); // figure out the "next address" we want to add to 
        memcpy(dest, value, arrData->elemSize); // copy the data from the input value into the next address in the array
        arrData->length++; // now represents new length
        return;

    }
}

// this will return a memory address
void* getElement(struct DynArray* arrData, int index) { 
    // bounds check
    if (index < 0 || index > (arrData->length-1)) { 
        printf("[GET ELEMENT | ERROR] : Index out of range\n");  /* Print error message */
        return NULL; // get out (return nothing)
    }

    // code to get a value from the dynamic array
    void * value = (char*) arrData->val + (arrData->elemSize * index); // figure out the address of the current element
    return value; // return that address  (could return int, but that's not type - agnostic)
}

#endif
