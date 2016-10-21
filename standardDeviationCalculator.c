#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>



int main () {
	uint8_t numbers;
	printf ("How many numbers will you be inputting: ");
	scanf("%i", &numbers);
	
	float values [numbers];
	printf ("Input all the numbers below: \n");
	for (uint8_t i = 0; i < numbers; i++) {
		printf ("Number %d: ", ++i);
		scanf ("%f", &values[--i]);
	} // Ask user for all numbers to be used for the statistics
	
	return 0;	
}

