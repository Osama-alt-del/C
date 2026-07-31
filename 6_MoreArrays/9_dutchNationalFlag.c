// This is a C program where I will implement the code for the dutch national flag challenge

/* 
    so we have an array of 0s, 1s, and 2s, we want the 0s to be first, the 1s next, and the 2s last

    we must do this in one pass, using O(1) extra space 
    hint: use 3 pointers dividing the array into regions
*/

#include <stdio.h>
#include "handy.h"

#define SIZE 13 

void dutchFlag(int *, int);

int main () { 
    int array[SIZE] = {0, 1, 0, 2, 2, 0, 0, 1, 1, 2, 2, 0, 0}; 

    // print the array before
    printArray(array, SIZE);

    // apply the algorithm
    dutchFlag(array, SIZE);

    // print the array after
    printArray(array, SIZE);

    return 0;
}

// helper swap function
/*
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
*/


void dutchFlag(int *array , int size){
    /*
    Potential solutions:
        similarly to the move 0, I think I might need 3 pointers, one explorer (i), one pointer telling me the insert_pos of 0s,
        one telling me the insert_pos of 2. the 1s should naturally be arranged on their own

        Step1: move the zeros to the start of the array
    */

    int insert_pos0 = 0;
    int insert_pos2 = size-1; // this has to start at the end of the array
    for ( int i = 0; i < size; i ++ ) {
        // put all of the zeroes in front
        // These two if statements can sometimes make it so that the 1s are out of place
        if (array[i] == 0 ) { // swap all 0s with the insert_pos0 element
            swap(&array[i], &array[insert_pos0]); 
            insert_pos0 ++; // then you just increment the "0 area"
        }

        if (array[i] ==2) { 
             swap(&array[i], &array[insert_pos2]); 
             insert_pos2--;
        }
    }
    
}
