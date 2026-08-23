// #include "function.h"
#include <function.h> // <>  ignores local directories, so it won't find if we don't use -I.
#include "stdio.h" // this will still work because it will firstly check local and THEN it will check system

void printFunction() { 
    printf("This is printing something\n");
}

