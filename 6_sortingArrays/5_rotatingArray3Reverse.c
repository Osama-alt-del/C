/* There is an easier, faster way to rotate arrays
    if you have {1, 2, 3, 4, 5} and you want to move left k = 3 times, then we will take the first k elements:
        {1, 2, 3} and reverese that block: {3, 2, 1}
        then we will reverse the remaining block: {5, 4}
        then concatenate them: {3, 2, 1, 5, 4}
        then we will reverse the whole thing: {4, 5, 1, 2, 3}

** CHECK THIS BECAUSE SOMETHING IS WRONG WITH IT APPARENTLY (ASK AI AND LEARN), RUN THE BLOCK B AND A PARTS SEPARATELY
*/

#include <stdio.h>
#include "handy.h"

#define SIZE 5

void rotate_left3r(int *, int, int);
void reverse(int *, int, int);

int main () { 

    int array[SIZE] = {1, 2, 3, 4, 5};

    // print the array 
    printArray(array, SIZE);

    // rotate:
    rotate_left3r(array, SIZE, 3);

    // print the new array:
    printArray(array, SIZE);

    return 0;
}


// I could make another array, work on that and then make the current array equal to that array and it would only be a multiple of n in terms of time complexity

// space complexity: O(n) (not good) (it can be O(1)
// time complexity: O(n) (good) (using temp array), O(1) using the reverse helper
// this reverse helper function uses index for start, and #vals for end
void reverse(int * array, int start, int end){
    int temp;
    // reverse the current block in place
    // for B:
    // i is start (3), but (end-start)/2 is equal to "1"
    // it has to be the average, not the difference and then divided by 2
    for (int i = start; i < (end+start)/2; i ++) { 
        temp = array[i]; // first value 
        array[i] = array[end-1-(i-start)];
        array[end-1-(i-start)] = temp;
    }
}

void rotate_left3r(int array[], int n, int k) { 
    if ( n ==0 || k == 0) return; // make sure that we account for an empty array and when k = 0
    // firstly we will work on block a:
    // if k = 3:
    // blocks are divided by: 0, 1, 2 <= 0 -> k-1 | 3, 4 <= k -> n-1

    reverse(array, 0, k);
    printf("Block A: \n");
    printArray(array, n);

    reverse(array, k, n);
    printf("Block B: \n");
    printArray(array, n);

    // now we reverse the whole array
    reverse(array, 0, n);
}

