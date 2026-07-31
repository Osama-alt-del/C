/* This is a c program where I will reverse a C array without using a second array*/
#include <stdio.h>

void reverse(int*, int, int);


int main() {
    int array[6] = {1, 2, 3, 4, 5, 6};

    // print the array before reversal:
    for ( int i = 0; i < 6; i ++) { 
        printf("%d ", array[i]);
    }
    printf("\n");

    // reverse the array:
    reverse(array, 0, 6);

    // Print the array out again
    for ( int i = 0; i < 6; i ++) { 
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;

}



void reverse(int* array, int start, int end) { 
    int temp;
    for (int i = start; i < (end+start)/2; i++) { 
        temp = array[i];
        array[i] = array[end-1-(i-start)]; 
        array[end-1-(i-start)] = temp;
    }
}
