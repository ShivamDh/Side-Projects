#include <stdio.h>
#include <stdlib.h>

int main () {
	int box[4][4] = { {0, 1, 2, 3}, 
					  {5, 6, 7, 8}, 
					  {8, 9, 10, 11},
					  {12, 13, 14, 15}};
		
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++) {
			if (box[i][j] == 0) 
				printf ("| \t");
			else
				printf ("| %d \t", box[i][j]);
		}
		printf ("\n");
	}
}

