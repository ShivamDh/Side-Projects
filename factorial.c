#include <stdio.h>
#include <inttypes.h>

int main () {
	uint64_t factorial = 1;
	uint8_t index = 1;
	
	printf ("Enter a number whose factorial you wish to check: ");
	scanf ("%d", &index);
	
	if (index<0) {
		printf ("Sorry the number who inputted does not have a valid factorial");
	}
	
	if (index > 20) {
		printf ("Sorry you entered an index too high for this computer to compute a factorial of");
	}
	
	//checks to make sure that input from user is valid and within boundaries of 
	
	uint8_t i;
	
	for (i=1; i<= index; i++) {
		factorial = factorial * i;
	}
	
	printf ("The factorial for index %d is %d", index, factorial);
	
	return 0;
}