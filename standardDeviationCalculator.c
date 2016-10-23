#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

float stdev (float numbers, float values[]);

int main () {
	uint8_t numbers;
	printf ("How many numbers will you be inputting: ");
	scanf("%i", &numbers); //Ask user for how many numbers to be used for statistics
	
	float values [numbers];
	printf ("Input all the numbers below: \n");
	for (uint8_t i = 0; i < numbers; i++) {
		printf ("Number %d: ", ++i);
		scanf ("%f", &values[--i]);
	} // Ask user for all numbers to be used for the statistics
	
	printf ("The population standard deviation of this set is: %.4f", stdev(numbers, values));
	
	return 0;	
}

float stdev (float numbers, float values []) { // Function for finding standard deviation
	float sum, mean, standarddev = 0;
	
	for (uint8_t i = 0; i<numbers; i++) {
		sum += values[i]; // Find mean of values
	}
	
	mean = sum/numbers;
	
	for (uint8_t j = 0; j<numbers; j++) {
		standarddev += pow (values[j]-mean, 2);
	}
	
	return sqrt(standarddev/numbers); //Return value of standarad deviation
}