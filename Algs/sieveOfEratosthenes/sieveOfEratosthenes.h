/* This is a file where I will try to implement the sieve of eratosthenes

given a number n, find all prime numbers less than or equal to n. So not exactly about finding if a number is prime or not 

example: input: n = 10; output = [2, 3, 5, 7]; it works!!! yay.

firstly I will try a "naive" approach

 you just allocate more memory in run time (heap), then you do a memory copy of all of the values into the new address, then free all of the old values, and then point to that new array

 this is what the "realloc()" function does for you
    returns NULL if cannot resize memory, so make sure to check for a null pointer.

*/
#include "dynArray.h" /* for dynamic arrays (also includes stdio.h and stdlib.h) */
#include <math.h>
#include <stdbool.h>

/* prime number function */
bool isPrime(int num) { 
    if (num == 2) { 
        return true;
    }
    int limit = sqrt(num);
    int i = 2; // we start dividing by 2
    while (i <= limit) { 
        if (num % i==0) {
            return false; /* divided evenly by something? then not prime */
        }
        i++;
    }
    return true; /* went all the way without returning false? then prime */
}

/* find the prime numbers up to target */
void sieve(struct DynArray* array, int input) { 
    for (int i = 2; i<= input; i++) {  /* check all of the prime numbers up to input, if it's prime, add to array */
        if (isPrime(i)) { 
            appendArray(array, i);
        }
    }
}

void printArray(struct DynArray* array) { 
    printf("[");
    for (int i = 0; i < array->length-1; i++) { 
        printf("%d ", array->val[i]);
    }
    printf("%d", array->val[array->length-1]);
    printf("]");
    printf("\n");
}

