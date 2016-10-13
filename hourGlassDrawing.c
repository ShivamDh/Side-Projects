#include <stdio.h>

int main () {
	int base;
	
	printf ("Please enter the base/height (an odd number) for the hour-glass to be drawn: ");
	scanf ("%i", &base);
	
	if (base<1 || base%2 == 0) {
		printf("Error: Wrong input entered");
		return -1;
	}
	
	int top_half_row = base;
	
	for (int j = 1; j<= ((base+1)/2); j++) {
		for (int k = 1; k<j; k++)
			printf(" ");
		for (int l = 1; l<=top_half_row; l++)
			printf ("*");
		top_half_row -= 2;
		printf ("\n");
	}
	
	int bottom_half_row = 3;
	
	for (int a = ((base+3)/2); a <=base; a++) {
		for (int b = 0; b<(base-a); b++)
			printf (" ");
		for (int c = 0; c<bottom_half_row; c++)
			printf ("*");
		bottom_half_row += 2;
		printf ("\n");
	}
	
	
	return 0;
}