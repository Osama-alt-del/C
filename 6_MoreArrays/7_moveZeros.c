// In this file I will try code a program that will move all of the zeros in the array to the end of the array while maintaining the relative order of the non-zero elements

#include "handy.h"

#define SIZE 5

void moveZ(int*, int); // I assume I will only need the pointer and the size
void moveZFast(int*, int); // this is faster O(n) with the same space complexity as the previos one

int main() { 
    int array[SIZE] = {0, 0, 2, 0, 4};
    printArray(array, SIZE); 
    moveZFast(array, SIZE);
    printArray(array, SIZE); 


    return 0; 
}


// space: O(1)
// time: O(n^2)
void moveZ(int* array, int size) { 
    /* Potential solutions:

    1, "bubble sort all of the zeroes to the end of the array"

    */

    // 1:
    int loop = 1; // flag to check for completion
    int k = 0;
    int temp;
    while(loop) { 
        loop = 0; // we make the loop zero, if we need to move a zero, then we will make the loop equal to 1
        for (int i = 0; i < size-1-k; i ++) { 
            if (array[i]==0&&array[i+1]!=0) { 
                // what if it's : 001234 it will take 2 passes
                // swap the values if current=0 && next !=0
                // for some reason, the zero at the end becomes a junk value?
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;     
                loop = 1;
            }
        }

        k++; // every for loop, there is one less place we need to check.

    }

}

// We can make this better by using an "explorer" and another variable for our "insert position"
/*
{1, 2, 0, 3, 0, 4};
so we will have insert_pos and i start at index 0. i will move from 0 to size-1. 
if i encounters a non-zero number, then that number will be swapped into the insert_pos position.
if i encounters a zero, then it will just keep going
insert_pos will move by 1 only when a swap occurs (when i finds a non-zero number)
*/

void moveZFast(int * array, int size) { 
    int insert_pos = 0; int temp;
    for (int i = 0; i < size; i ++) { 
        if (array[i] !=0 )  {
            temp = array[i]; 
            array[i] = array[insert_pos];
            array[insert_pos] = temp;
            insert_pos++;
        }

    }

}
