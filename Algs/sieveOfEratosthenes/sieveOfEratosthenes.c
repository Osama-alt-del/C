#include "sieveOfEratosthenes.h"

int main(int argc, char **argv) {  /* params are the number of inputs and an array of all inputs, tokenised */
    if (argv[1] == NULL) { 
        printf("[ERROR] Expected input number\n");
        return -1;
    }

    struct DynArray output = createDynArray(0); /* start with 0 length */
    int input = atoi(argv[1]); /* atoi function turns an integer string into an integer */

    sieve(&output, input); 
    printArray(&output);

    freeDynArray(&output);
    return 0;
}
