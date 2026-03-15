/* This is a C program where I will try to take user input for the length and values of an array and then try to average the values */
#include <stdio.h>

// Sometimes in main they have args and stuff and it does stuff? I don't really know what the differences are, maybe later I'll check it out
int main()
{
	int n;
	printf("Please enter the number of values: ");
	scanf("%d", &n);
	int c[n], total = 0, average;

	for (int i = 0; i < n; i++)
	{
		printf("Please enter number %d: ", i+1);
		scanf("%d", &c[i]);
		total += c[i];
	}

	average = total/n;	
	printf("The average is: %d\n", average);
	return 0;
}
