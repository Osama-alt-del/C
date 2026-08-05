// this code will cause a segfault

#include <stdio.h>
#include <stdlib.h>
int main() { 
    int* pt = NULL;

    printf("%d/n", *pt); // trying to dereference a null pointer


    return 0;
}

