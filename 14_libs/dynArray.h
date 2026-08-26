#ifndef DYN_ARRAY_H /* header guards */
#define DYN_ARRAY_H

#include <stdio.h>
#include <stdbool.h>

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

typedef struct { 
    void* val; // pointer to the point in memory (void* to raw memory type-agnostic)
    int capacity; // number of values
    int length;  // index of the latest value in the array
    size_t elemSize; // Size of one element (need to save this so that we can use in realloc)
    ElementType elemType; // setting to ELEMENT_TYPE instead of just int is good because the compiler will warn us here if we have something outside. This helps us during checks.
} DynArray; // alias

DynArray createDynArray(int size, ElementType elementType);

void freeDynArray(DynArray* arrData);

void reallocateMemory(DynArray* arrData);

void appendArray(DynArray* arrData, void* value);

void* getElement(DynArray* arrData, int index);

void printer(ElementType elementType, void *value);

void printArray(DynArray* arrData);


#endif
