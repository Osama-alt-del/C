#include <math.h>
#include <stdio.h>
#include <stdint.h>

// Integer to Binary
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

// Print binary uint8_t:
void printBin(uint8_t n) {
    for (int i = 7; i >= 0; i--) { 
        printf("%d ", n>>i&1);
    }
    printf("\n");
}
