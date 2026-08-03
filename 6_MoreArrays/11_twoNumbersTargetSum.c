// Given a target number, find two numbers in the array whose sum equals the target

#include <stdio.h>
#include "handy.h"

#define SIZE 5

struct IntTouple { 
    int int1; 
    int int2;
};

// we need to return a struct with 2 integers
struct IntTouple twoNumSum(int*, int, int);

int main() { 
    int array[SIZE] = {1, 2, 3, 4, 5};

    int target = 5;
    struct IntTouple touple =  twoNumSum(array, SIZE, target);
    
    // I've confirmed that this works properly i
    printf("Target: %d\n", target);
    printf("Number1: %d\n", touple.int1);
    printf("Number2: %d\n", touple.int2);

    return 0;
}

// Definition
struct IntTouple twoNumSum(int* array, int size, int target){ 
    struct IntTouple touple; // define the touple

    // disastrous time complexity O(N^2) worst case
    // Space complexity: O(1)
    for ( int i = 0 ; i < size; i ++) { 
        for (int j = 0; j < size; i++) { 
            if ( array[i] + array[j] == target) { 
                touple.int1 = array[i];
                touple.int2 = array[j];
                return touple;
            }
        }
    }

    // touple.int1 = 5;
    // printf("%d\n", touple.int1);
    printf("[NO NUMBERS]");
    return touple;
}

// The faster version uses a "hashtable" (will look into those more deeply later)
/*
Basically, hashes are "dictionaries" where keys are mapped to values.
*/
struct IntTouple twoNumSumFast(int* array, int size, int target) { 
    struct IntTouple touple; /* Define the touple that we will return */


    
    return touple; /* return the touple */ 
}



