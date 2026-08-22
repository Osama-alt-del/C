#ifndef DYN_ARRAY_H /* header guards */
#define DYN_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for memcpy


// enum will automatically assign integers to these values (enumerate them), so TYPE_CHAR will basically be == to 0, TYPE_INT will be == 1 etc
// add a lookup table with the TYPEs as the indices (because they go from 0 to 1) and then linkn that to the sizes)
typedef enum {
    TYPE_CHAR,               // char
    TYPE_SIGNED_CHAR,        // signed char
    TYPE_UNSIGNED_CHAR,      // unsigned char

    TYPE_SHORT,               // short / short int
    TYPE_UNSIGNED_SHORT,      // unsigned short

    TYPE_INT,                 // int
    TYPE_UNSIGNED_INT,        // unsigned int

    TYPE_LONG,                 // long / long int
    TYPE_UNSIGNED_LONG,        // unsigned long

    TYPE_LONG_LONG,            // long long
    TYPE_UNSIGNED_LONG_LONG,   // unsigned long long

    TYPE_FLOAT,                // float
    TYPE_DOUBLE,                // double
    TYPE_LONG_DOUBLE,           // long double

    TYPE_BOOL,                 // _Bool / bool

    TYPE_POINTER,              // void* (generic pointer)
} ElementType; // alias name

// lookup table linking to the sizes of the elements (so we only have to enter the type)
// Static: this is already "static duration" "lives for the whole program, because it is global, however" we can
// make sure that there are no name clashes (there will only be one copy of type sizes for each translation unit
// this is just an array of type size_t, so this is defined (it's not a struct)
static const size_t typeSizes[16] = {
    [TYPE_CHAR]               = sizeof(char),
    [TYPE_SIGNED_CHAR]        = sizeof(signed char),
    [TYPE_UNSIGNED_CHAR]      = sizeof(unsigned char),
    [TYPE_SHORT]              = sizeof(short),
    [TYPE_UNSIGNED_SHORT]     = sizeof(unsigned short),
    [TYPE_INT]                = sizeof(int),
    [TYPE_UNSIGNED_INT]       = sizeof(unsigned int),
    [TYPE_LONG]               = sizeof(long),
    [TYPE_UNSIGNED_LONG]      = sizeof(unsigned long),
    [TYPE_LONG_LONG]          = sizeof(long long),
    [TYPE_UNSIGNED_LONG_LONG] = sizeof(unsigned long long),
    [TYPE_FLOAT]              = sizeof(float),
    [TYPE_DOUBLE]             = sizeof(double),
    [TYPE_LONG_DOUBLE]        = sizeof(long double),
    [TYPE_BOOL]               = sizeof(bool),
    [TYPE_POINTER]            = sizeof(void*),
};

// writing typedef here tells the comiler that DynArray is a struct, so we never have to write "struct" in front again
/* if you try to define this with "struct DynArray" then it won't work (error) because there is not "tag" to this struct (no name after 
 the struct part. However, we have shortened this whole "anonymous" struct into the name "DynArray" so in the end, you never need to write 
 "struct DynArray". This is why you should always write the names at the end.

 name after struct == TAG NAME. name after } and before ;  == either ALIAS or VARIABLE NAME; if there is no "typedef" then it's a variable name, meaning that we have just declared a struct, and we can use it immediately.
 */

typedef struct { 
    void* val; // pointer to the point in memory (void* to raw memory type-agnostic)
    int capacity; // number of values
    int length;  // index of the latest value in the array
    size_t elemSize; // Size of one element (need to save this so that we can use in realloc)
    ElementType elemType; // setting to ELEMENT_TYPE instead of just int is good because the compiler will warn us here if we have something outside. This helps us during checks.
} DynArray; // alias


/* you can return structs from functions in C */
// normal declaration: DynArray a = createDynArray(0, sizeof(int), TYPE_INT); // Ithink we should make it so we only take the type
DynArray createDynArray(int size, ElementType elementType) {  // now we don't input the size, 
    // maybe change this to be cleaner later (try and allocate memory and then check first)
    DynArray arrData;
    arrData.elemSize = typeSizes[elementType]; // save the size of each individual element
    arrData.elemType = elementType; // save the type of the element so that we can use for later
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


void freeDynArray(DynArray* arrData){ 
    free(arrData->val);
}

/* Function to reallocate memory */
/* REALLOC IS EXPENSIVE it's O(n) to copy every block to a bigger block of contiguous memory, 
so we don't want to call it all the time */
void reallocateMemory(DynArray* arrData) { 
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
void appendArray(DynArray* arrData, void* value) {  
    if (arrData->length < arrData->capacity) { /* Check if we can add a value */
        // [REASON WE CONVERT TO CHAR*
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
void* getElement(DynArray* arrData, int index) { 
    // bounds check
    if (index < 0 || index > (arrData->length-1)) { 
        printf("[GET ELEMENT | ERROR] : Index out of range\n");  /* Print error message */
        return NULL; // get out (return nothing)
    }

    // code to get a value from the dynamic array
    void * value = (char*) arrData->val + (arrData->elemSize * index); // figure out the address of the current element
    return value; // return that address  (could return int, but that's not type - agnostic)
}

void printer(ElementType elementType, void *value) {
    switch (elementType) {
        case TYPE_CHAR: {
            char *v = value;
            printf("%c ", *v);
            break;
        }
        case TYPE_SIGNED_CHAR: {
            signed char *v = value;
            printf("%d ", *v);
            break;
        }
        case TYPE_UNSIGNED_CHAR: {
            unsigned char *v = value;
            printf("%u ", *v);
            break;
        }
        case TYPE_SHORT: {
            short *v = value;
            printf("%hd ", *v);
            break;
        }
        case TYPE_UNSIGNED_SHORT: {
            unsigned short *v = value;
            printf("%hu ", *v);
            break;
        }
        case TYPE_INT: {
            int *v = value;
            printf("%d ", *v);
            break;
        }
        case TYPE_UNSIGNED_INT: {
            unsigned int *v = value;
            printf("%u ", *v);
            break;
        }
        case TYPE_LONG: {
            long *v = value;
            printf("%ld ", *v);
            break;
        }
        case TYPE_UNSIGNED_LONG: {
            unsigned long *v = value;
            printf("%lu ", *v);
            break;
        }
        case TYPE_LONG_LONG: {
            long long *v = value;
            printf("%lld ", *v);
            break;
        }
        case TYPE_UNSIGNED_LONG_LONG: {
            unsigned long long *v = value;
            printf("%llu ", *v);
            break;
        }
        case TYPE_FLOAT: {
            float *v = value;
            printf("%f ", *v);
            break;
        }
        case TYPE_DOUBLE: {
            double *v = value;
            printf("%f ", *v);
            break;
        }
        case TYPE_LONG_DOUBLE: {
            long double *v = value;
            printf("%Lf ", *v);
            break;
        }
        case TYPE_BOOL: {
            bool *v = value;
            printf("%s ", *v ? "true" : "false");
            break;
        }
        case TYPE_POINTER: {
            void **v = value;
            printf("%p ", *v);
            break;
        }
        default:
            printf("[PRINTER | ERROR] : unknown type\n");
            break;
    }
}
void printArray(DynArray* arrData) { 
    // could use a switch statement to check the element size and based on that, decide how to declare
    // potential problem : what if there are variables of the same size, but different types (hopefully this isnt' the case)
    for ( int i = 0; i < arrData->length; i++) { 
        printer(arrData->elemType, getElement(arrData, i)); // this might be really slow
    }
    printf("\n");
    
    
}


#endif
