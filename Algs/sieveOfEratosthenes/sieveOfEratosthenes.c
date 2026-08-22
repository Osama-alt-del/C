/* 
     - make the sieve of eratosthenes (make a boolean dynarray and use that to dictate whether or not something is prime or not)
         - check for prime, if prime, you will rule out all of the multiples of that number. fpr example. if I have 2, then I will rule out( 4, 6, 8).  terrific, I think that that's really cool, but I also want to practice and get faster at writing using one hand.  
*/


// this is so so sos so so so much better oh my god. I can' 


#include "sieveOfEratosthenes.h"


int main(int argc, char **argv) {  /* params are the number of inputs and an array of all inputs, tokenised */
    if (argv[1] == NULL) { 
        printf("[ERROR] Expected input number\n");
        return -1;
    }
    
    // we should probably check for the input integer and see if it's really a string or not    

    int input = atoi(argv[1]); /* atoi function turns an integer string into an integer */

    sieve(input); 


    /*
    printf("[");
    printArray(&output);
    printf("]\n");
    */

    return 0;
}

