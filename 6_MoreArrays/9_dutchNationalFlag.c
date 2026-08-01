// This is a C program where I will implement the code for the dutch national flag challenge

/* 
    so we have an array of 0s, 1s, and 2s, we want the 0s to be first, the 1s next, and the 2s last

    we must do this in one pass, using O(1) extra space 
    hint: use 3 pointers dividing the array into regions
*/

#include <stdio.h>
#include "handy.h"

#define SIZE 10 

void dutchFlag(int *, int);

int main () { 
    int array[SIZE] = {1, 2, 0, 2, 1, 1, 0, 0, 0, 1}; 

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
    int i = 0; // this is our epxloring index
    // we can make i go to inser_pos2 because we don't need it to go all of the way
    // it's better to use a while loop here:
    while (i <= insert_pos2) { 
        printf("%d %d\n", i, insert_pos2);
        if (array[i] == 0) {
            swap(&array[i], &array[insert_pos0]);
            insert_pos0++; // increment position to insert 
            i++; // increment the explorer 
        }
        else if (array[i] == 1 ) { 
            i++; // Just increment (1s should be arranged automatically at the end so we skip)
        }
        
        // we don't have to use else if, because this is searching an entirely different part of the array
        else { // using size-1-i can make an infinite loop, (think of {2, 1, 0}).
            swap(&array[i], &array[insert_pos2]);
            insert_pos2--; // decrement position to insert
            // [VERY IMPORTANT]:
            // do not increment the explorer, (i) because we need to recheck the current value with the first if 
        }
    }
}
