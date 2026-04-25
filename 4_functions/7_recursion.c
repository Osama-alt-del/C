/* This is a C file where I will learn recursion!!! Yay!! 
recursive functions are functions that call themselves either directly or indirectly through another function.
The function only knows how to solve the base case. If the problem is more comlex, then the function divides the 
problem into two pieces. A piece that the function knows  how to do (without calling itself)
 and a piece that the function does not know how 
to do. To make recursion possible, the latter must be a slightly simpler or lsightly smaller version of the original problem.

Because the smaller problem looks like the original problem, the function can just call itself again *recursive call* I will use
recursive function call to program a factorial function I will try and do this by myself first
*/

#include <stdio.h>
// It's better to make these long ints, because factorials can get very large, but for now it's fine with ints
int factorialIterative(int);
int factorialRecursive(int);

int main()
{
	// Firstly we can find the factorial using a for loop
	printf("Iterative function: %d\n", factorialIterative(5));
	printf("Recursive function: %d\n", factorialRecursive(5));


	return 0;
}

/* Ok this is awesome, was able to shorten that code by so much. I have to remember to set a terminating condition though, which is
also called a base case　

再起関数での「べーすけーす」は再起関数がストップするような条件を指します。この場合のベースケースはｎ＜＝１という条件です */

int factorialIterative( int n )
{
	int factorial = 1;

	for (int i = n; i > 0; i--)
	{
		factorial *= i;
	}
	return factorial;
}

int factorialRecursive( int n )
{
	if (n <= 1) return 1; /* Terminating condition, also called a base case*/
	
	return (n * (factorialRecursive( n-1 )));
}
