#include <stdio.h>
#include <inttypes.h>

int main() {
	uint64_t number1;
	printf("Enter a positive number to transfer into bit form: ");
	scanf ("%d", &number1);
	
	printf("The first number in binary form is: ");
	for (uint8_t i = 0; i<=31; i++) {
		uint64_t temp_number1 = number1 >> (31-i);
		temp_number1 = temp_number1 & 1;
		printf("%d", temp_number1);
		}
		
	return 0;
}