// This is the main file for testing all of the algorithms in C

#include <stdio.h>
// #include "./bubbleSort.h"
#include "./quickSort.h"
#define SIZE 5

int  main(){
    int array[SIZE] = {5, 3, 2, 4, 1};

    // ----------------Bubble Sort Check-----------------------
    // bubbleSort(array, SIZE);
    
    // ----------------Quick Sort Check------------------------ 
    quickSort(array, 0, SIZE);

    // Print the array (that should be sorted):
    for (int i = 0; i < SIZE; i++){
        printf("%d\n", array[i]);
    }

    return 0;
}
