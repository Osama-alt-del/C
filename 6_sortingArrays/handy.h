// This is a header file with a lot of handy functions to deal with arrays
#ifndef HANDY_H
#define HANDY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h> // we can get the integer limit from here

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

// this will randomize the values in the array that we have already created
void makeRandArr(int* array, int size) { 
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 9 +1; // start = 1, width = 9 (total values) so from 1 to 9
    }
}

// sum, mean, median, mode
int findSum (int * array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) { 
        sum += array[i];
    }
    return sum;
}

int findMean(int* array, int size) {
    int mean = findSum(array, size)/size;
    return mean;
}

int findMode(int* array, int size) {
    int freq[9] = {0}; // this is to calculate the frequency of each value
    int mode;

    for (int i = 0; i < size; i++) { 
        freq[array[i]-1]++;
    }

    printArray(freq, 9);
    
    // find the maximum (traversing the freq array)
    int max = 0;
    for (int i = 0; i < 9; i++) { 
        if (max < freq[i]){
            max = freq[i]; // if a value is greater, become that value
            mode = i+1; // the maximum is the frequency, the index+1 is the actual value 
        }
    }
     
    return mode;
}

float findMedian(int* array, int size) {
    // middle value of an array, if size is even, then average of middle 2 

    // then we will check if the size is even or not
    if (size % 2 == 0) { 
        // if it's even, then find the average of the middle 2 values
        float sum = (float)array[size/2]+array[(size/2)-1];
        float median = sum/2;
        return median;   
    }
    else { 
        return array[size/2]; // C automatically floors this so it's fine
    }
}


// max and min
int findMax(int* array, int size) {
    int max = 0;
    for (int i = 0; i < size; i++) { 
        if (max < array[i]){
            max = array[i]; // if a value is greater, become that value
        }
    }
    return max;
}

int findMin(int* array, int size) {
    int min = INT_MAX; // maximum possible value something can be
    for (int i = 0; i < size; i++) { 
        if (min > array[i]){
            min = array[i]; // if a value is less, become that value
        }
    }
    return min;
}

#endif
