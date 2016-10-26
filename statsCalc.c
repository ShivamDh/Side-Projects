#include <stdio.h>
#include <math.h>

float mean (float given_values[], float total_numbers);

int main () {
	int numbers;
	printf ("How many numbers will you be inputting: ");
	scanf("%d", &numbers); // Ask users for how many numbers to be inputted
	
	float values [numbers];
	printf ("Enter numbers one-by-one: \n");
	for (int i = 0; i < numbers; i++) {
		printf ("Number %d: ", ++i);
		scanf ("%f", &values[--i]);
	} // Ask user for all numbers to be used for the statistics
	
	printf ("Enter the option number(s) you would like, enter 0 to end choice selection\
	\n (1) Sample Mean \n (2) Population Mean \n (3) Mode \n (4) Median \
	\n (5) Sample Standard Deviation \n (6) Population Standard Deviation\
	\n (7) Sample Variance \n (8) Population Variance \n Enter choice:  ");
	// Print out options for the user to select
	
	return 0;
}