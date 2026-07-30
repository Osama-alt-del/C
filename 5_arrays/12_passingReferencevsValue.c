// We have 2 functions, one to modify the entire array and multiply all elements by 2 and one that only modifies a single value, without changing the actual value in the array. 

// the array has 5 values, we have to firstly print the 5 values and then we can run the functions

#include <stdio.h>
#define SIZE 5

// prototypes
void modifyArray(int [], int); // pass by reference (change the actual values)
void modifyElement(int); // pass by value (does not change the actual values)

int main() {
    // define the array
    int array[SIZE] = {1, 2, 3, 4, 5};

    // first we will print our array
    for (int i = 0; i < SIZE; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    // double the array:
    modifyArray(array, SIZE);

    // Print the array again
    for (int i = 0; i < SIZE; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    // THen we will run the other function:
    modifyElement(array[3]);

    // printf the element in the index 3 to show that it hasn't changed
    printf("%d \n", array[3]);


    return 0;
}


// you can't write "int [] array" that's weird.
void modifyArray(int array[], int size) {
    for (int i = 0; i < size; i++){
        array[i]*=2; // times the actual value of the array
    }
}

// this will also print the new value, because that's the only way we can see the effect of the function
void modifyElement(int element){
    element *=2;
    printf("Doubled Element: %d\n", element);
}

