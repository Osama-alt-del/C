/* This is a C program where I will roll a 6 sided die 6000 times and then display the frequencies of each roll using arrays */

/* This program basically uses a frequency array where each index represents a roll and if we get 1 for example, 1 is added to the first
element if we get 2, we add 1 to the second elemnt and so on. We then just display everything nicely and bam */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 6

int main()
{
	srand(time(NULL));
	int frequency[SIZE] = {0};
	int roll;

	for (int i = 0; i < 6000; i++)
	{
		roll = 1 + rand() % 6;
		frequency[roll-1]+=1;
	}

	printf("%s%15s\n", "Roll", "Frequency");

	for (int i = 0; i < 6; i++)
	{
		printf("%4d%15d\n", i+1, frequency[i]);
	}


	return 0;
}
