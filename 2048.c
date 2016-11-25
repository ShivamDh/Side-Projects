#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void printArea (int values[4][4]);
void shiftLeft (int themValues[4][4]);
void shiftRight (int themValues[4][4]);
void shiftUp (int themValues[4][4]);
void shiftDown (int themValues[4][4]);
int addNumber(int themValues[4][4]);
int possibleMoves (int themValues[4][4]);

int main () {
	system("cls");
	int box[4][4] = {0};
	addNumber(box);
	
	printArea(box);
	
	int keyboardInput;
	int secondInput;
	printf ("\nPress Esc to exit game\nEnter your next move (Left/Right/Up/Down)\n");
	
	
	
	while ((keyboardInput = _getch()) != 27) {
		if (keyboardInput == 97 || keyboardInput == 65) { // 'a' or 'A' button
			system ("cls");
			shiftLeft(box);
		} else if (keyboardInput == 100 || keyboardInput == 68) { // 'D' button
			system ("cls");
			shiftRight(box);
		} else if (keyboardInput == 119 || keyboardInput == 87) { // 'W' button
			system ("cls");
			shiftUp(box);
		} else if (keyboardInput == 115 || keyboardInput == 83) { // 'S' button
			system ("cls");
			shiftDown(box);
		} else if (keyboardInput == 224) { // If inputs are from arrow kee
			secondInput = _getch();
			if (secondInput == 75) { // Left arrow key
				system ("cls");
				shiftLeft(box);
			} else if (secondInput == 77) { // Right arrow key
				system ("cls");
				shiftRight(box);
			} else if (secondInput == 72) { // Up arrow key
				system ("cls");
				shiftUp(box);
			} else if (secondInput == 80) { // Down arrow key
				system ("cls");
				shiftDown(box);
			} else 
				printf ("\nInvalid move, try again");
		} else 
			printf ("\nInvalid move, try again");
		int point = addNumber(box);
		int point2 = possibleMoves(box);
		
		if (point < 0 && point2 < 0) {
			printArea(box);
			printf ("\n/nGame over, no more possible moves");
			break;
		}
		printArea(box);
		printf("\nPress Esc to exit game\nEnter your next move (Left/Right/Up/Down)\n");
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
	for (int z = 0; z < 3; z++) { // move if empty space exists
		for (int y = 0; y < 4; y++) {
			if (themValues[z][y] == 0) {
				themValues[z][y] = themValues[z+1][y];
				themValues[z+1][y] = 0;
				if (z < 2) {
					themValues[z+1][y] = themValues[z+2][y];
					themValues[z+2][y] = 0;
				}
				if (z < 1) {
					themValues[z+2][y] = themValues[z+3][y];
					themValues[z+3][y] = 0;
				}
			}
		}
	}
		
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

void shiftDown (int themValues[4][4]) {
	for (int z = 3; z > 0; z--) { // move if empty space exists
		for (int y = 0; y < 4; y++) {
			if (themValues[z][y] == 0) {
				themValues[z][y] = themValues[z-1][y];
				themValues[z-1][y] = 0;
				if (z > 1) {
					themValues[z-1][y] = themValues[z-2][y];
					themValues[z-2][y] = 0;
				}
				if (z > 2) {
					themValues[z-2][y] = themValues[z-3][y];
					themValues[z-3][y] = 0;
				}
			}
		}
	}
		
	for (int c = 3; c > 0; c--) { // move if common numbers exist
		for (int d = 0; d < 4; d++) {
			if (themValues[c][d] == themValues[c-1][d]) {
				themValues[c][d] += themValues[c-1][d];
				themValues[c-1][d] = 0;
				if (c > 1) {
					themValues[c-1][d] = themValues[c-2][d];
					themValues[c-2][d] = 0;
				}
				if (c > 2) {
					themValues[c-2][d] = themValues[c-3][d];
					themValues[c-3][d] = 0;
				}
				
			}
		}
	}
}

int addNumber(int themValues[4][4]) {
	int rows = rand() % 4;
	int columns = rand() % 4;
	int numAdd = ((rand() % 2)*2)+2;
	bool optout = false;
	
	
	if (themValues[rows][columns] == 0) 
		themValues[rows][columns] = numAdd;
	else {
		for (int ch1 = 0; ch1 < 4; ch1++){
			for (int ch2 = 0; ch2 < 4; ch2++){
				if (themValues[ch1][ch2] == 0)
					optout = true;
			}
		}
		if (optout)
			addNumber(themValues);
		else {
			return -1;
		}
	}
	return 0;
}

int possibleMoves (int themValues[4][4]) {
	bool allow = false;
	
	for (int q = 0; q < 4; q++) {
		for (int r = 0; r < 3; r++) {
			if (themValues[q][r] == themValues[q][r+1]){
				allow = true;
				break; break;
			}
		}
	}
	
	for (int s = 0; s < 3; s++) {
		for (int t = 0; t < 4; t++) {
			if (themValues[s][t] == themValues[s+1][t]) {
				allow = true;
				break;break;
			}
		}
	}
	
	if (allow)
		return 0;
	else
		return -1;
}