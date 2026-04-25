/* This is a C program where I take the average of 10 values using a while loop */

#include <stdio.h>

int main()
{
	// Firstly we declare the variables we want to use:
	int grade, n, total, average, counter;
	// The variables that we need to add to, we set to 0 (avoid garbage values)
	total = 0;
	counter = 0;
	printf("total: %d   count: %d\n", total, counter);
	// Take the number of inputs we want
	printf("Enter the number of inputs: ");
	scanf("%d", &n); 
	while ( counter < n )
	{
		printf("Enter grade %d: \n", counter+1);
		scanf("%d", &grade);
		total += grade;
		counter +=1;	
	}
	average = total/n;
	printf("The average is %d: \n", average);
	return 0;
}
