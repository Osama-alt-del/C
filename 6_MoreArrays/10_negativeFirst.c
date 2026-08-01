// this is aprogram where we will put all of negative numbers in front of all of the other numbers


#include <stdio.h>
#include "handy.h"

#define SIZE 5
void negativeFirst(int*, int);


int main () { 
    
    int array[SIZE] = {-1, -2, 0, -3, 5};

    // print array
    printArray(array, SIZE);

    // implement 
    negativeFirst(array, SIZE);

    // print array
    printArray(array, SIZE);
    return 0;

}


void negativeFirst(int * array, int size) {
    int i = 0;
    int insert_neg = 0;
    while (i < size) { 
        if ( array[i] <  0 ) { // if negative number, shove it in the insert_neg
            swap(&array[i], &array[insert_neg]);
            insert_neg++; // you are going to want to increment to add to the next place
        }
        i++; // Increment anyway (if negative, will be shifted, if not, will be skipped)
    }
}
