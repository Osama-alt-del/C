/* This is a C program where I will draw a diamond using for loops 

IT WORKS!!! YESS!! HAHAHAHA

There is still the problem where if the length is even, the last point is not drawn, but I could very easily just add one to the length if it's
even (lol)


*** There was a problem with a swap file when I added everything to github, for some reason, I recovered an old version and then my changes 
dissapeared. I need to find a way to get ovet this, or just get rid of swap files in general I guess*/

/* We use the absolute value of the length/2-i/2  so that eventually when we reach the middle,
i starts to go up instead. That way, when we know i has passed the middle, we can begin to increase the number of spaces again.

Based on this value which goes from 4, 3, 2, 1, 0, 1, 2, 3, 4 , we can then notice that for i>8 subtracting the absolute value of 
length/2-i/2 gives us the number of stars for the equivalent position where i < 8 (the middle).

This means that we can use this and with our increasing spaces, subtract the number of stars properly and make a perfect diamond.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* Maybe I can try and make a triangle facing outwards first. I need i to go up and then go down I guess, so I could try and write a
	program where I put a condition in the increment part of the for loop I guess*/
	int length, counter;
	counter = 0;
	printf("Enter the length of the diamond: ");
	scanf("%d", &length);
	// Just add 1 if the number is odd so that we can get a nice diamond at the end	
	if ( length%2 == 0 ) length++;

	// Print the entire length (all of the rows)	
	for (int i = 0; i<=length*2-1; i+=2)
	{
		printf("%3d: ", abs(length/2-(i/2)));
		printf("%3d", i);
		// Print the spaces, which decrease as i increase, but then increase again
		for (int j = abs(length/2-(i/2)); j>=0; j--)
		{
			//printf("j1: %d", j);
			printf(" ");
		}
		// Find the relationship between i, length/2 -i/2, and then set a conditional for loop condition 
		// (This is so that the subtraction only happens when i is greater than 8 (we are past the middle)
		for (int j = 0; i <= length-1 ?j<=i : j<= i-(4*abs(length/2-(i/2))); j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}

