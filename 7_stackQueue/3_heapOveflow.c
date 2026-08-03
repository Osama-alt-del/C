// Just like there is stack overflow, there is also heap overflow. This happens when the memory that we allocate at run time (with malloc in C, or new in C++) exceedsthe boundary of an allocated block of memory on the memory heap, corrupting adjacent data. that's all you need to know.

// This is stack overflow and heap overflow

// STACK OVERFLOW::
// stack smashing = when you get a stack overflow so severe, it can alter the return address in a stack frame
// segmentation fault: when the program tries to access memory that it isn't allowed to/it cannot access: (going beyond the bounds of an array), (dereferencing a NULL pointer)
// Tripwires to detect = stack canaries (small integer, randomly chosen value at program start in memory just before the stack return pointer) Prior to function return, this value is checked. If it is changed, then we know something is wrong they. They usually return stack smashing and check if the return address could have potentially been overridden

// HEAP OVERFLOW:
// heap overflow: nothing to detect, which is why it's so dangerous

#include <string.h>
#include <stdlib.h>

int main() { 
    // according to AI (I should probably check this):

    char buf[10]; // local variable (main scope) lives on the stack
    // strcpy(buf, "This is much much longer than 10 bytes, so it will affect other data in the stack"); // stack overflow 

    char* buf2 = malloc(10); // allocate 10 bytes of memory in runtime for this char pointer (in the heap)
    strcpy(buf2, "This is also much longer than 10 bytes, considering that a single character is 1"); // heap overflow
    
    return 0;
}

// that's how you know that strcpy and strncpy are not safe to use. Basically they don't check for bounds which is why if the destination string is smaller than the source string, there can be an overflow into adjacent memory.
