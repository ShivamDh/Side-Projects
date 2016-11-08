#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

void printArea (int values[4][4]);

int main () {
	int box[4][4] = { {0, 10, 69, 0}, 
					  {10, 1, 1, 1}, 
					  {695, 1024, 1, 1},
					  {5102, 1024, 2048, 8}};
	
	printArea(box);
	
}

void printArea (int values[4][4]) {
	for (int a = 0; a < 65; a++) {
			printf ("-");
	}
	
	printf ("\n");
	
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++) {
				printf ("|\t%d\t", values[i][j]);	
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