/* This is a C file, where I will just play around with storage types 

C provides four storage classes indicated by auto, register,extern, and static. An identifier's storage class 
determines its storage duration (1), scope (2) and linkage (3). 

(1) Storage Duration: 
period during which identifier (variable / function name) exists in memory. Some identifiers 
exist for a short while, some are repeatedly created and destroyed , and others exist for the entire execution of a 
program. Some identifiers can exist for the entire execution of the program.

(2) Scope:
The scope of an identifier is where the identifier can be referenced in a program. Some can be referenced throughout
a program, while others can only be referenced in certain portions of the program

(3) Linkage:
An Identifiers linkage determines for a multiple-source-file program whether an identifier is known only in the 
current source file or in any source file with proper declarations.

There are two storage durations: (a) automatic and (b) static

(a) automatic:
Keywords, 'auto' and 'register' are used to declare variables of automatic storage duration are active when the 
block in which they are declared is entered ( block = {} ). They are basically local variables. They are destroyed 
when their block is exited. register tells the computer to store the variable in one of the high-speed hardware 
registers Variables such as counters or totals can be maintained in hardware registers.

(b) static:
Keywords 'extern' and 'static' are used to declare identifiers of static storage duration. They exist from the point
at which the program begins execution. There are two different types of identifiers with static storage duration
external identifiers (such as function names and global variables) and local variables declared with the static
specifier.  global variables are created by placing the declarations outside any function definition.

static local variables are only defined when the function block is called the first time, and they retain their 
value when the function is exited. Next time the function is called, the variable has the same value as before

____________________SCOPE_____________________
There are 4 scopes: function scope, file scope, block scope, and function-prototype scope. 

Function scope:
Labels (identifier followed by a colon such as start: or case:) are the only identifiers with function scope. They can be 
used anywhere in the function in which they appear, but can not be referenced outside the function body.




*/
#include <stdio.h>

/* started using the { in the same line, since it's easier to write that in quicker */
int main(){


return 0;
}
