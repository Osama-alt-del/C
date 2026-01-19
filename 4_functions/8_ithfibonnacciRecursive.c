/* This is a C program where I will make a program to find the ith number in the fibonacci series in C using recursive 
functions

So it's not just simply create a fibonacci sequence, but it's make a recursive function that takes a number and returns the ith
value in the sequence. The fibonacci sequence is basically : the next number is the sum of the previous 2 numbers. Ok So all I have
to do is keep summing the last 2 numbers n times... easy I think

n = fib(n-1/2) + fib(n-1/2) which should be fine I think? I'll have to look into the relationship a little bit closer I guess
I just need to know how to derive the previous 2 numbers from the first one and then I think I can just keep on going? but wait.
what the function takes is the position, so all I actually have to do is
n = fib(n-1) + fib(n-2) i guess? and then since the base case is 1, it will all work out some how (it stops at the 0th value)? 
*/

#include <stdio.h>

long fibonacci(long);

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		printf("Number %2d: %4ld\n", i, fibonacci(i));
	}	


	return 0;
}

long fibonacci(long n)
{
	if (n == 1) return 1;
	
	long fibnum;
	fibnum = fibonacci(n-1) + fibonacci(n-2); // so add the previos two numbers
	// ok so I get a seg fault after the first number is printed for some reason.
	return fibnum;
	/* Things to think about:
		- Base case
		- The recursive call	
		- 書く前に図を書いた方が良いと思う
	*/	
}
