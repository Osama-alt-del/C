// This is a C program to implement a stack (with explanation)

#include <stdio.h>

void first();
void second();


int main() { 
    first();
    return 0;
}

// we will define a bunch of functions to see how the stack works:

void first() { 
    // we will define some int variables:
    int int1;
    int int2;

    // then we will print out their addresses:
    printf("First, Int1: %p\n", &int1);
    printf("First, Int2: %p\n", &int2);

    // now we will run second in first:
    second(); // and we will see what will happen. I'm guessing that values that are from second int will have lower memory addresses, even though they are at the "top" of the stack
}

void second() { 
    // we will define some int variables:
    int int1;
    int int2;

    // then we will print out their addresses:
    printf("Second, Int1: %p\n", &int1);
    printf("Second, Int2: %p\n", &int2);
}
