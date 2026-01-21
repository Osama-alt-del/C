/* This is a C code where I check out how to take arguments into the main function through the command line 
So first, there's argc and argv
They don't have to be called as such, that's just convention and it should be followed. argc should be an integer

argc: the number of arguments that are passed into the main function through the command line
argv: */

#include <stdio.h>

// I don't really understand what *argv[] means. I assume this means it's a double pointer...
// Also we have to use string for the print instead of char? that's strange...
int main(int argc, char *argv[])
{

	printf("number of arguments: %d\n", argc);
	printf("arg1: %s\n", argv[0]); 
	printf("arg2: %s\n", argv[1]); 
	printf("arg2: %s\n", argv[2]); /* we don't get a seg fault if this is out of range, we just get null over here */


	return 0;
}
