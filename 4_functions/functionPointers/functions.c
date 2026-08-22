// This is the C file that contains the function definitions

#include "functions.h" // include for checking if definitions matches declarations (safety net)
#include <stdio.h>

int add(int a, int b) { 
    return a +b;
}

int subtract(int a, int b){
    return a-b;
}

int divide(int a, int b){
    if (b == 0) { 
        printf("[ERROR | DIVIDE] : DIVISION BY 0\n");
        return -1; 
    }
    return a/b;
}                          

int multiply(int a, int b){
    return a*b;
}                        
