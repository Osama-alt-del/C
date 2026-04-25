/* This is the same as the previous file, but I'm going to use a sentinel value (like -1 or something)
To stop the program and I'm going to continue to calculate the average over and over */

#include <stdio.h>

int main()
{
	float average;
	int count, total, grade;
	// total, count = 0;
	total = 0;
	count = 0;
	printf("total: %d   count: %d\n", total, count);
	while ( grade != -1 )
	{
		printf("Enter grade %d: ", count+1);
		scanf("%d", &grade);
		if (grade != -1)
		{
			total += grade;
			count ++;
		}
	}

	if (count > 0)
	{
		// Here we only need to assign one of the operands to be a float, the other one will be 'implicitly converted'
		average =  total/(float)count;
		printf("total: %d   count: %d\n", total, count);
		printf("The average is: %.2f\n", average);
	}

}
