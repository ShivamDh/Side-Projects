#include <stdio.h>
#include <inttypes.h>

int main () {
	uint8_t operation = 0; //Initialization of variables and values
	uint64_t number1 = 0;
	uint64_t number2 = 0;
	uint64_t answer = 0;
	printf ("Enter the two numbers you would like to operate on: ");
	scanf ("%d %d", &number1, &number2);
	
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
	printf("The operation is equal to %d", answer); 
	
	
	return 0;
}