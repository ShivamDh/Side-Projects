#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void printArea (int values[4][4]);
void shiftLeft (int themValues[4][4]);
void shiftRight (int themValues[4][4]);
void shiftUp (int themValues[4][4]);
void shiftDown (int themValues[4][4]);

int main () {
	system("cls");
	int box[4][4] = { {0, 10, 69, 0}, 
					  {2048, 1, 1, 2}, 
					  {1024, 1024, 1, 1},
					  {1024, 1024, 2048, 8}};
	
	printArea(box);
	
	int keyboardInput;
	int secondInput;
	printf ("\nPress Esc to exit game\nEnter your next move (Left/Right/Up/Down)\n");
	
	while ((keyboardInput = _getch()) != 27) {
		if (keyboardInput == 97) // 'A' button
			printf ("%d", keyboardInput);
		else if (keyboardInput == 100) // 'D' button
			printf ("%d", keyboardInput);
		else if (keyboardInput == 119) // 'W' button
			printf ("%d", keyboardInput);
		else if (keyboardInput == 115) // 'S' button
			printf ("%d", keyboardInput);
		else if (keyboardInput == 224) { // If inputs are from arrow kee
			secondInput = _getch();
			if (secondInput == 75)
				printf ("%d    %d", keyboardInput, secondInput);
			else if (secondInput == 77)
				printf ("%d    %d", keyboardInput, secondInput);
			else if (secondInput == 72)
				printf ("%d    %d", keyboardInput, secondInput);
			else if (secondInput == 80)
				printf ("%d    %d", keyboardInput, secondInput);
			else 
				printf ("\nInvalid move, try again");
		}
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

void shiftLeft (int themValues[4][4]) {
	for (int z = 0; z < 4; z++) { // move if empty space exists
		for (int y = 0; y < 3; y++) {
			if (themValues[z][y] == 0) {
				themValues[z][y] = themValues[z][y+1];
				themValues[z][y+1] = 0;
				if (y < 2) {
					themValues[z][y+1] = themValues[z][y+2];
					themValues[z][y+2] = 0;
				}
				if (y < 1) {
					themValues[z][y+2] = themValues[z][y+3];
					themValues[z][y+3] = 0;
				}
			}
		}
	}
		
	for (int c = 0; c < 4; c++) { // move if common numbers exist
		for (int d = 0; d < 3; d++) {
			if (themValues[c][d] == themValues[c][d+1]) {
				themValues[c][d] += themValues[c][d+1];
				themValues[c][d+1] = 0;
				if (d < 2) {
					themValues[c][d+1] = themValues[c][d+2];
					themValues[c][d+2] = 0;
				}
				if (d < 1) {
					themValues[c][d+2] = themValues[c][d+3];
					themValues[c][d+3] = 0;
				}
				
			}
		}
	}
}

void shiftRight (int themValues[4][4]) {
	for (int z = 0; z < 4; z++) { // move if empty space exists
		for (int y = 3; y > 0; y--) {
			if (themValues[z][y] == 0) {
				themValues[z][y] = themValues[z][y-1];
				themValues[z][y-1] = 0;
				if (y > 1) {
					themValues[z][y-1] = themValues[z][y-2];
					themValues[z][y-2] = 0;
				}
				if (y > 2) {
					themValues[z][y-2] = themValues[z][y-3];
					themValues[z][y-3] = 0;
				}
			}
		}
	}
		
	for (int c = 0; c < 4; c++) { // move if common numbers exist
		for (int d = 3; d > 0; d--) {
			if (themValues[c][d] == themValues[c][d-1]) {
				themValues[c][d] += themValues[c][d-1];
				themValues[c][d-1] = 0;
				if (d > 1) {
					themValues[c][d-1] = themValues[c][d-2];
					themValues[c][d-2] = 0;
				}
				if (d > 2) {
					themValues[c][d-2] = themValues[c][d-3];
					themValues[c][d-3] = 0;
				}
				
			}
		}
	}
}

void shiftUp (int themValues[4][4]) {
		
	for (int c = 0; c < 3; c++) { // move if common numbers exist
		for (int d = 0; d < 4; d++) {
			if (themValues[c][d] == themValues[c+1][d]) {
				themValues[c][d] += themValues[c+1][d];
				themValues[c+1][d] = 0;
				if (c < 2) {
					themValues[c+1][d] = themValues[c+2][d];
					themValues[c+2][d] = 0;
				}
				if (c < 1) {
					themValues[c+2][d] = themValues[c+3][d];
					themValues[c+3][d] = 0;
				}
				
			}
		}
	}
}
