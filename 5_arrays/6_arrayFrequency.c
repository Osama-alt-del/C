/* This is a C program where I will find the number of recurring elements in an array and then print them out as the frequency */

#include <stdio.h>
#include "randomResponse.h"
#include "sumArray.h"
#define FREQUENCY_SIZE 10
#define RESPONSE_SIZE 40


int main()
{
	// 次のアレーの値をランダムで決めるプログラムを作って 
	int responses[RESPONSE_SIZE] = { 0 }; 
	int frequency[FREQUENCY_SIZE] = { 0 };
	// It's better to use void to deal with arrays in functions and just take their address in instead
	randResponse(RESPONSE_SIZE, responses);

	/* Print Responses  */
	/*
	for (int i = 0; i < RESPONSE_SIZE; i++)
	{
		printf("%2d%4d\n", i, responses[i]);
	}
	*/

	// Values in frequency arr are the frequncy of the current index being in RESPONSE_SIZE
	for (int i = 0; i < RESPONSE_SIZE; i++)
	{
		// Did -1 because the frequency array has indexes 0-9
		frequency[responses[i]-1] ++;
	}

	printf("%s%15s\n", "Number", "Frequency");
	
	for (int i = 0; i < FREQUENCY_SIZE; i++)
	{
		printf("%2d%17d\n", i+1, frequency[i]);
	}	

	printf("Total Frequency: %d\n", sumArray(FREQUENCY_SIZE, frequency));

	return 0;
}
