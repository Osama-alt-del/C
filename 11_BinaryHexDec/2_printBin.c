// Print a binary uint8_t value using printf

#include <stdint.h>
#include <stdio.h>

void printBin(uint8_t);


int main() { 
    // define the binary number
    uint8_t num = 0b10101010;
    // print the binary number
    printBin(num);
    
    return 0;
}

void printBin(uint8_t n) {
    for (int i = 7; i >= 0; i--) { 
        printf("%d ", n>>i&1);
    }
    printf("\n");
}



