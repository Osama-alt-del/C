// This is a C program to fine the second largest element in an array

#include <stdio.h>
#include <limits.h>

#define SIZE 5

int secondLargest(int*, int);
int secondLargest1Pass(int*, int);

int main ()  {
    int array[SIZE] = {1, 2, 3, 4, 5};

    printf("%d \n", secondLargest(array, SIZE));
    printf("%d \n", secondLargest1Pass(array, SIZE));
    
     
    return 0;
}

int secondLargest(int* array, int size) { 
    /* 
    Potential solutions:
        1. find the largest, save an array of differences to the largest, and then find out the second largest using that?

        2. find the largest, save the index, and then run through the array again, jumping over that index t =O(2n), s= O(1)
    */

    // 2:

    // edge cases:
    if ( size == 1) { 
        return array[0]; // because this means that there is no "second largest"
    }
    else if ( size == 0) { 
        return 0; // because this means that there is no "second largest"
    }
    int largestIndex = -1;
    int largest = INT_MIN;
    for ( int j = 0; j < size; j ++ ) { 
        if ( j == largestIndex){
            printf("continue\n");
            continue; // skjp jf you have are on the largest jndex
        }
        if ( array[j] > largest ) { 
            largest = array[j];
            // I need to make sure that this doesn't change the second time around
            largestIndex = j;
        }
    }
    largest = INT_MIN;
    for ( int j = 0; j < size; j ++ ) { 
        if ( j == largestIndex){
            continue; // skjp jf you have are on the largest jndex
        }
        if ( array[j] > largest ) { 
            largest = array[j];
            // I need to make sure that this doesn't change the second time around
            // largestIndex = j;
        }
    }
    return largest;
}


// this is technically the same time complexity as before, but it's faster because it's single pass

// O(n) O(1)
int secondLargest1Pass(int * array, int size ) { 
    // edge cases:
    if ( size == 1) { 
        return array[0]; // because this means that there is no "second largest"
    }
    else if ( size == 0) { 
        return 0; // because this means that there is no "second largest"
    }

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    // one pass
    for ( int i = 0; i < size; i ++ ) { 
        if ( array[i] > largest ) {
            secondLargest = largest; // so now the secondLargest takes the position of the largest
            largest = array[i]; // and the largeset is now the value that is greater than the largest
        }

        else if ( array[i] > secondLargest) {  // if val is not greater than largest, but secondL, then swap those
            secondLargest = array[i];
        }
    }


    return secondLargest;
}

