#include <stdio.h>
#include <inttypes.h>
 
int main() {
	uint64_t number1 = 0;
	printf("Enter a positive number to transfer into bit form: ");
	scanf ("%d", &number1);
	
	printf("The first number in binary form is: ");
	uint64_t number1_bits[64]; // An array to store value of each bit
	for (uint8_t i = 0; i < 64; i++) {
		number1_bits [i] = number1 >> (63-i);
		number1_bits[i] = number1_bits[i] & 1; // Storing all the bits within the array created
		}
	
	uint8_t blanks = 0;
	
	for (uint8_t j = 0; j < 64; j++) { //Weeding out the initial zeroes seen in binary code due to 64-bit variable
		if (number1_bits[j] == 0) {
			printf("");
			blanks++;
		}
		else 
			break;
	}
	
	for (blanks; blanks < 64; blanks++) 
		printf ("%d", number1_bits[blanks]); //Printing out the relevant part of the binary code (right most)
	
	return 0;
}