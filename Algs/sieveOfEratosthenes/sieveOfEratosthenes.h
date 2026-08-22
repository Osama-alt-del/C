/* This is a file where I will try to implement the sieve of eratosthenes

given a number n, find all prime numbers less than or equal to n. So not exactly about finding if a number is prime or not 

example: input: n = 10; output = [2, 3, 5, 7]; it works!!! yay.

firstly I will try a "naive" approach

 - Have a boolean array of true | false flags, (true for prime, false for non-prime). Make 0 and 1 False and make the rest all true.
 - If you have a number that is prime, then add it to the prime number list.
 - Let's say you look at 2, and say it's a prime, you will then rule out all of the multiples of 2 (4, 6, 8 etc)
 - So your prime number list should also act as a list of divisors you will check for.

*/

#ifndef SIEVEOFERATOSTHENES_H
#define SIEVEOFERATOSTHENES_H

#include <math.h>
#include <stdbool.h>
#include "dynArray.h"

/* prime number function */
bool isPrime(int num) { 
    if (num < 2) {
        return false;
    }
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
void returnPrimes(DynArray* array, int input) { 
    // for now we wll just use the nomral array and then we will use the bool array
    // DynArray boolArray = createDynArray(0, TYPE_BOOL);  // start with size 0
    
    // we don't need to check fro prime numbers, so just skip those.
    // we add to the array, and then we can ignore the rest
    for (int i = 2; i<= input; i++) {  /* check all of the prime numbers up to input, if it's prime, add to array */
        if (isPrime(i)) {  // we can't even use it very usefully in functions because we need to write down what the type is???
            appendArray(array, &i); // append i into the array if we have the value that we want
        }
    }

}

// this is a helper function that sets all boolArray values except for the first two to true
void setBoolArray(DynArray* boolArray, int input) { 
    // add to the start
    bool False = false;
    bool True = true;

    // set the first 2 values to false
    appendArray(boolArray, &False); appendArray(boolArray, &False); // set the starting 2 values to false

    // set the rest of the values to true
    for (int i = 2; i < input + 1; i++) { // start from 2 to the end
        appendArray(boolArray, &True); // this always only adds to the end
    }
}

void boolToNum(DynArray* boolArray, int input) {
    bool* check;
    for (int i = 0; i < input + 1; i++) {
        check = getElement(boolArray, i);
        if (*check == true) { 
            printf("%d", i); /* print out only the values corresponding to true */
            printf(" ");
        }
    }

}

void sieve(int input) { 
    DynArray boolArray = createDynArray(input+1, TYPE_BOOL); // make the boolean array

    // set the array to have 2 falses and then trues all the way to the end
    setBoolArray(&boolArray, input);

    /*
    printf("Starting bool Array:\n");
    printArray(&boolArray); // just print this for debugging for now
    printf("\n");
    printf("\n");
    */

    /* sieve of Eratosthenes :
    firstly check for 2, then you know 2 is prime, so tick off all indexes that are multiples of 2
    */

    // search from the second value and then make all of the values false
    // firstly we check every prime number (starting from 2, if the next one is true, then we pretend that we know it's prime)
    bool* value;
    for (int i = 2; i < input+1; i++) {
        value = getElement(&boolArray, i);
        // skip values that are false
        if (*value == false) { 
            continue;
        }

        // check all multiples of i, starting from the next multiple
        for (int j = i*i; j < input+1; j+=i) { 
            // set array[j] to false
            value = getElement(&boolArray, j);
            *value = false;
        
        }
    }

    /*
    printf("Final bool Array:\n");
    printArray(&boolArray); // just print this for debugging for now
    printf("\n");
    printf("\n");
    */

    boolToNum(&boolArray, input); 
    printf("\n");

    freeDynArray(&boolArray); // free the boolean array at the end
}




#endif
