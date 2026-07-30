// We are going to use arrays and calculate their mean, median and mode
#include "handy.h"

#define SIZE 6 

// void makeRandArr(int*, int); // this will take the array and then randomize the values inside it

int main() {
    // make the array
    int array[SIZE];

    // Randomize the array
    makeRandArr(array, SIZE);

    // sort the array
    // bubbleSort(array, SIZE);


    // print the array out:
    printArray(array, SIZE);

    // printf("Mean: %d \n", findMean(array, SIZE));
    // printf("Mode: %d \n", findMode(array, SIZE));
    // printf("Median: %f \n", findMedian(array, SIZE));


    return 0;
}

/* This following code was added to the handy.h file
// this will randomize the values in the array that we have already created
void makeRandArr(int* array, int size) { 
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 9 +1; // start = 1, width = 9 (total values) so from 1 to 9
    }
}

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


*/





