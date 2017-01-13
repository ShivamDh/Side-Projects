#include <stdio.h>
#include <inttypes.h>

int bits (int bit_number);

int main () {
	uint8_t operation = 0; //Initialization of variables and values
	uint32_t number1 = 0;
	uint32_t number2 = 0;
	uint32_t answer = 0;
	printf ("Enter the two numbers you would like to operate on: ");
	scanf ("%d %d", &number1, &number2); // Take in user input of two numbers to be used
	
	printf ("  (1) Addition \n  (2) Subtraction \n  (3) Multiplication \
	\n Enter your choice:  ");
	scanf ("%i", &operation); // Getting user input for which type of operation to undertake
	
	// Complete the mathematical part of the code
	// Choosing type of operation
	switch (operation) {
		case 1: answer = number1 + number2; //Add
		break;
		case 2: answer = number1 - number2; //Subtract
		break;
		case 3: answer = number1 * number2; //Multiplication
		break;
		default: printf ("Sorry wrong number entered \n"); return -1;
		break;
	}
	
	printf(" The first number in binary form is: "); bits(number1); // Print Number 1 in decimal 
	
	printf("\n The second number in binary form is: "); bits(number2); // Print Number 2 in binary
	
	printf("\n The operation is equal to %d", answer); // Print answer in decimal 
	
	printf("\n The answer in binary form is: "); bits(answer); // Print answer in binary again
	
	return 0;
}

int bits (int bit_number) {
	uint32_t number_bits[64]; // An array to store value of each bit
	for (uint8_t i = 0; i < 64; i++) {
		number_bits [i] = bit_number>> (63-i);
		number_bits[i] = number_bits[i] & 1; // Storing all the bits within the array created
		}
	
	uint8_t blanks = 0;
	
	for (uint8_t j = 0; j < 32; j++) { //Weeding out the initial zeroes seen in binary code due to 64-bit variable
		if (number_bits[j] == 0) {
			printf(""); // Do nothing if the inital bits are '0', aka. do not print the '0'
			blanks++; // Keep track of how many initial '0' there are
		}
		else 
			break; 
	}
	
	for (blanks; blanks < 32; blanks++) // Start printing from the first non-zero digit
		printf ("%d", number_bits[blanks]); //Printing the relevant binary code 

	
}
