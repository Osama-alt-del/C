/*
rotate_left will move the arrays to the left, and rotate it based on the number (k);

*/

#include "handy.h"

#define SIZE 5

void rotate_left(int*, int n, int k); // prototype

int main () {
    int array[SIZE] = {1, 2, 3, 4, 5};
     
    // print the current array:
    printArray(array, SIZE);

    // rotate
    rotate_left(array, SIZE, 12);

    // check the new array
    printArray(array, SIZE);

    return 0;
}

// Space complexity: O(1);
// Time complexity: O(n^2) as k ==> n (but not =to n, because we now have the remainder code (not that good);

void rotate_left(int array[], int n, int k) {  // takes the array, n = size, k = the number of spaces we want to move the array
    // edge case for if the size is 0
    if ( n == 0 ) return;

    // making it so we only move the array the remainder of k and n (if we make a 5 value array move left 20 times, it will just be the same)
    k = k%n;
    for (int i = 0; i < k; i++ ) { 
        printf("rotation %d\n", i+1); // checking that the remainder part of the code works
        // swapping variables
        int old = array[0]; 
        int next;
        // rotate code
        for (int j =n-1; j >= 0; j--) {
            /*
            if (j == n-1) { 
                next = array[n-1]; // save the value before we override it. (5)
                array[n-1] = old; // we use old and swap the values; 5 -> 1;
                old = next; // now that we have swapped the values, we can set "old" to be the value of next the next values is now 5
            }
            */

            next = array[j]; // save the value before we override it. (next = 4)
            array[j] = old; // we use old and swap the values; (old = 5, so the current value is now 5)
            old = next; // now that we have swapped the values, we can set "old" to be the value of next (old = 4) (next value to be replaced)

            // we can have 2 variables, 'old' and 'next' 'this determines the current value. 'next' dtermines the next valeu
            // 1, 2, 3, 4, 5 // initial (swap not set) 
            // 1, 2, 3, 4, 1 // 1. next = 5 and we make the last value = the first (old = first value), then we say next = 
            // 1, 2, 3, 5, 1 // 2. swap = 4, and we make the second last value = 5
            // 1, 2, 4, 5, 1 // 3. swap = 3 and we take 4 and put it in the current position
            // 1, 3, 4, 5, 1 // 
            // 2, 3, 4, 5, 1
        }
    }
}


