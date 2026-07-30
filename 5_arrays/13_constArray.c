// When passing a whole array, the actual values will end up being modified. If we want to stop this, we can use the const qualifier

#include <stdio.h>
#define SIZE 5

// we won't take the size as a paramtere, because we will only try to change the first value
void tryModifyArray(const int []);

int main() {
    // use the const qualifier to define an array:
    const int array[SIZE] = {0, 1, 2, 3, 4};

    tryModifyArray(array);


    return 0;
}

void tryModifyArray(const int array[]) {
    // try and modify the first value in the array:
    array[3] = 0;
}
