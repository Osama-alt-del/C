/* If statement file

*/
#include <stdio.h>

int main()
{
	int num1, num2;

	printf("Enter two numbers and I will tell you \n");
	printf("the relationship that they satisfy: \n");
	// Writing %d one after the other takes one number per return (Enter) input.
	scanf("%d%d", &num1, &num2);

	if (num1 == num2)
		printf("%d is equal to %d\n", num1, num2);
	if (num1 != num2)
		printf("%d is not equal to %d\n", num1, num2);
	if (num1 < num2)
		printf("%d is less than %d\n", num1, num2);
	if (num1 > num2)
		printf("%d is greater than %d\n", num1, num2);
	if (num1 <= num2)
		printf("%d is less than or equal to %d\n", num1, num2);
	if (num1 >= num2)
		printf("%d is greater than or equal to %d\n", num1, num2);
	return 0;
}
