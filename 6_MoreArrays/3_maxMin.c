// This is a file testing finding the minimum and maximum in C

#include "handy.h"

#define SIZE 6

int main() { 
    int array[SIZE] = {1, 2, 3, 4, 5, 1234};

    // find the max and the min of the array:
    printf("Max: %d\n", findMax(array, SIZE));
    printf("Min: %d\n", findMin(array, SIZE));

    return 0;
}


/* code in handy.h
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
    int min = INT_MAX; // maximum possible value something can be. This requires "limits.h"
    for (int i = 0; i < size; i++) { 
        if (min > array[i]){
            min = array[i]; // if a value is less, become that value
        }
    }
    return min;
}

*/
