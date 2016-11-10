#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void printArea (int values[4][4]);

int main () {
	int box[4][4] = { {0, 10, 69, 0}, 
					  {10, 1, 1, 1}, 
					  {695, 1024, 1, 1},
					  {5102, 1024, 2048, 8}};
	
	printArea(box);
	
	int keyboardInput;
	printf ("Press Esc to exit game\nEnter your next move: ");
	
	while ((keyboardInput = _getch()) != 27) {
		if (keyboardInput == 97 || keyboardInput == 100 || keyboardInput == 119 || keyboardInput == 115)
			printf ("%d", keyboardInput);
		else if (keyboardInput == 224)
			printf ("%d    %d", keyboardInput, _getch());
		else 
			printf ("\nInvalid move, try again");
		printf("\n");
		printf ("Enter your next move: ");
	}
	
}

void printArea (int values[4][4]) {
	for (int a = 0; a < 65; a++) {
			printf ("-");
	}
	
	printf ("\n");
	
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++) {
			if (values[i][j] == 0) 
				printf ("|\t\t");
			else {
				if (values[i][j] < 100)
					printf ("|\t%d\t", values[i][j]);
				else if (values[i][j] < 1000)
					printf ("|      %d      ", values[i][j]);	
				else 
					printf ("|      %d     ", values[i][j]);	
		}
		}
		printf ("|");
		printf ("\n");
		for (int k = 0; k < 65; k++) {
			printf ("-");
		}
		printf ("\n");
	}
}

