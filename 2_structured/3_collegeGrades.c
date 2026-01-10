/* This is a C code in which we take inputs of the grades and then decide whether or not to increase the tuition or not, the grades will
be represented as 1 (passed) , and a 2 (failed)*/

#include <stdio.h>

int main()
{
	int n, grade, count, numPass;
	count = 0;
	numPass = 0;
	n = 10;
	while (count < n)
	{
		printf("Enter result %d (1 = pass 2 = fail): ", count+1);	
		scanf("%d", &grade);
		if(grade == 1)
			numPass++;
		count++;
	}
	printf("Number of students that passed: %d\n", numPass);
	printf("Number of students that failed: %d\n", n-numPass);

	(numPass > 8)? printf("Raise tuition\n"): printf("Don't Raise tuition\n");

	return 0;
}
