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

(1) Function scope:
Labels (identifier followed by a colon such as start: or case:) are the only identifiers with function scope. They can be 
used anywhere in the function in which they appear, but can not be referenced outside the function body. The functions also
hide from each other. This is called 'function hiding' and it's one of the most fundamental principles of good software engineerin
(2) File scope:
An idnetifier decalred ouside any function has file scope. Such an identifier is  "known" in all functions. Global variables,
function definitions and function prototypes placed outside a function all have file scope.
(3) Block scope:
Block scope ends at the terminating brace (}) of the block. Local variables declared at the beginning of a function have block scope as
do function parameters.
(4) function-prototype scope:
The only indentifiers with function-prototype scope are those used in the parameter list of a function prototype. Function prototypes
do not require names in the parameter list - only types are required. If a name is used, the compiler ignores the name. Identifiers used
in a function prototype can be reused elsewhere in the program without ambiguity.
*/
#include <stdio.h>

void a( void ); /* Function prototype (promise the compiler that there is a function called a that outputs void */
void b( void ); 
void c( void ); 

int x = 1; /* Global Variables */
/* started using the { in the same line, since it's easier to write that in quicker */
int main(){
	int x = 5; /* local variable to main */
	
	printf("Local x in outer scope of main is %d\n", x);
	{
		int x = 7;
		printf("Local x in inner scope of main is %d\n", x);
	}
	printf("local x in outer scope of main is %d\n", x);

	a();	
	b();	
	c();	
	a();	
	b();	
	c();	
	
	printf("local x in outer scope of main is %d\n", x);

	
	return 0;
}

// Nevermind, starting the brackets on a new line looks prettier
void a( void )
{
	int x = 25;
	printf("\nlocal x in a is %d after entering a\n", x);
	++x;
	printf("local x in a is %d before exiting a\n", x);
}
void b( void )
{
	static int x = 25; /* because this is static, this runs first time b is called only */
	printf("\nlocal x in a is %d after entering a\n", x);
	++x;
	printf("local x in a is %d before exiting a\n", x);
}
void c( void )
{
	printf("\nglobal x is %d on entering c\n", x);
	x *= 10;
	printf("\nglobal x is %d on exiting c\n", x);
}
