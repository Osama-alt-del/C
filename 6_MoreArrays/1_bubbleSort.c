// we will implement bubble sort to sort an array in C
// a "bubble" index will go through the array and comparisons will be made, swapping accordingly. This will continue until the bubble goes through without making a single comparison.
#include <stdio.h>
#include "handy.h"
#define SIZE 5
// takes an array and the size of the array
// void bubbleSort(int*, int);
// void printArray(int*, int); 

int main() {
    // define the array
    int array[5] = {19, -26, 43, -38, 0};
    
    // check array
    printArray(array, SIZE);

    // Sort array
    bubbleSort(array, SIZE);

    // print again
    printArray(array, SIZE);

    return 0;
}
// The following code has been added to handy
/*
void swap(int* x, int* y) {
    int temp;
    temp = *x; // temp has the value of what x is pointing to
    *x = *y; // now x is pointing to the same value that y is pointing to 
    *y = temp; // y is pointing to the same value that x was pointing to 
}

// define bubble sort
void bubbleSort(int* array, int size) {
    int flag = 1;
    int k = 0; // last values are sorted with each run
    while (flag) {
        flag = 0; // set this to the exit condition
        for (int i = 0; i < size-1-k; i++) {
            if (array[i]>array[i+1]){
                // swap
                swap(&array[i], &array[i+1]);
                flag = 1; // set back to the continue condition if there is a swap
            }
        }
        k++;
        if (!flag) break; //if the flag is still 0 then break
    }
}

// print array function:
void printArray(int* array, int size) {
    // print the array:
    for (int i = 0; i < size; i++) { 
        printf("%d ", array[i]);
    }
    printf("\n");
}
*/


