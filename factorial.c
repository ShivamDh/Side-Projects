#include <stdio.h>

int main () {
	long long int factorial = 1;
	int index = 1;
	
	printf ("Enter a number whose factorial you wish to check: ");
	scanf ("%d", &index);
	
	if (index<0) {
		printf ("Sorry the number who inputted does not have a valid factorial");
	}
	
	if (index > 20) {
		printf ("Sorry you entered an index too high for this computer to compute a factorial of");
	}
	
	int i;
	
	for (i=1; i<= index; i++) {
		factorial = factorial * i;
	}
	
	printf ("The factorial for index %d is %d", index, factorial);
	
	return 0;
}