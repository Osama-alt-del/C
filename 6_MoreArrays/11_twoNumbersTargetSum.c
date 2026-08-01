// Given a target number, find two numbers in the array whose sum equals the target


#include <stdio.h>
#include "handy.h"

#define SIZE 5

struct IntTouple { 
    int int1; 
    int int2;
};


// we need to return a struct with 2 integers
struct IntTouple twoNumSum(int*, int);


int main() { 
    int array[SIZE] = {1, 2, 3, 4, 5};

    struct IntTouple touple =  twoNumSum(array, SIZE);
    
    // I've confirmed that this works properly 
    printf("Outside: %d\n", touple.int1);



    return 0;
}


// Definition
struct IntTouple twoNumSum(int* array, int size){ 
    struct IntTouple touple; // define the touple
    




    // touple.int1 = 5;
    // printf("%d\n", touple.int1);


    return touple;
}



