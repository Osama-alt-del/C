/* This is a C header file where I write a function that sums an array */

int sumArray(int n, int * array)
{
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += array[i];
	}
	return total;
}
