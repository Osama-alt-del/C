// This is a program where I will turn the integer into the binary (return an integer)
#include <stdio.h>
#include <math.h>

int intToBin(int);

int main() { 
    // Run here

    int num = 10;
    printf("%d\n", intToBin(num));
    
    return 0;
}

// Beautiful
int intToBin(int num) {
    int bin = 0;
    int count = 0; // This is the amount of digits.

    // I need to review how to find a binary number
    while (num >= 1) { 
        bin += (num%2) * pow(10, count); 
        num/=2;
        count++;
    }

    return bin;
}

