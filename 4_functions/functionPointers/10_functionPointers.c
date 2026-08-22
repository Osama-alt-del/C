// this is a C program where I will try and use the function program
#include "functions.h" // only need to show compiler the declarations.
#include <stdio.h>

// we can only declare in a struct, we cannot initialize/assign a value
typedef struct { 
    int(*op1)(int, int);
    int(*op2)(int, int);
    int(*op3)(int, int);
    int(*op4)(int, int);
} Calc;


int main() { 
    Calc calc;
    calc.op1 = add; 
    calc.op2 = subtract;
    calc.op3 = multiply; 
    calc.op4 = divide; 
    
    int a = 15;
    int b = 5;

    printf("Addition: \n");
    printf("%d\n", calc.op1(a, b));
    
    printf("Subtraction: \n");
    printf("%d\n", calc.op2(a, b));

    printf("Multiplication: \n");
    printf("%d\n", calc.op3(a, b));

    printf("Division: \n");
    printf("%d\n", calc.op4(a, b));
    
    return 0;
}

