#include <stdio.h>
#include <math.h>

float mean (float given_values[], float total_numbers);
float mode(float given_values[], int total_numbers);

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
	
	int total=0; int options[8];
	for (int j = 0; j< 8; j++) { // Place options inputted by user into an array
		scanf ("%d", &options[j]);
		if (options[j] > 8) { // Check for an option selection above (8)
			printf ("Invalid input, start over please");
			return -1;
		}
		if (options[j] == 0)
			break; // Break out of storing option choices if '0' selected
		total++; // Keep tally of how many options selected by user
		
	}
	
	for (int k = 0; k < total; k++) {
		switch (options[k]) {
			case 0: return -1;
			case 1: printf ("The sample mean is: %f \n", mean (values, numbers));
			break;
			case 2: printf ("The population mean is: %f \n", mean (values, numbers));
			break;
			case 3: mode (values, numbers);
			break;
			default: printf ("An error, try again please");
			break;
		}
	}
	
	return 0;
}


float mean (float given_values[], float total_numbers) { // Function for finding mean
	float sum = 0; float mean = 0;
	
	for (int z = 0; z<total_numbers; z++) {
		sum += given_values[z]; // Find sum of values
	}
	
	mean = sum/total_numbers; // Finding the mean
	
	return mean; //Returning the value of mean
}

float mode(float given_values[], int total_numbers) { // Function for finding mode
	float diff_values[total_numbers];  // Initalization of variables and array values
	int max_count[total_numbers];
	int appearances = 0;
	for (int x = 0; x < total_numbers; x++) {
		diff_values[x] = 0;
		max_count[x] = 0;
	} 
	
	for (int y = 0; y < total_numbers; y++) {
		for (int x = 0; x < total_numbers; x++) {
			if (diff_values[x] != given_values[y]) { // Check for diff values
				diff_values[x] = given_values[y]; 
				max_count[x] += 1; // Keep a running count 
				break;
			}
			}
		}
}