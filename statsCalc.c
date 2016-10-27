#include <stdio.h>
#include <math.h>

float mean (float given_values[], float total_numbers);

int main () {
	int numbers;
	printf ("How many numbers will you be inputting: ");
	scanf("%d", &numbers);
	
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
	
	int total=0; int options[8];
	for (int j = 0; j< 8; j++) {
		scanf ("%d", &options[j]);
		if (options[j] > 8) {
			printf ("Invalid input, start over please");
			return -1;
		}
		if (options[j] == 0)
			break;
		total++;
		
	}
	
	for (int k = 0; k < 8; k++) {
		switch (options[k]) {
			case 1: printf ("The sample mean is: \n "); // Create mean function
			break;
			case 2: printf ("The population mean is: \n"); // Use same mean function
			break;
			default: printf ("Error");
			break;
		}
	}
	
	return 0;
