#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "snakeGame.h"
using namespace std;



int Snake::getScore() {
	return score;
}

void Snake:: initialGame() {
	//start tje game at halt posiiton
			isGameRunning = true;
			dir = STOP;
	
			//initial snake coordinates
			xCoor = gameWidth / 4;
			yCoor = gameHeight / 4;
			
			//initial fruit coordinates
			srand(time(NULL)); //use seeds to ensure that truly random values are generated
			levelUpx = rand() % gameWidth;
			levelUpy = rand() % gameHeight;
			
			score = 0;
}

void Snake::drawCanvas(){
	cout << "  ";
	for (int i = 0; i < gameWidth+1; i++) {
		cout << "--";
	}
	
	cout << "-" << endl;
	
	for (int k = 0; k < gameHeight; k++) {
		for (int l = 0; l < 2*gameWidth; l++) {
			if (l == 0 || l == 2*gameWidth-1)
				cout << "  |";
			
			if (k == yCoor && l == xCoor)
				cout << "O";
			else if (l == levelUpx && k == levelUpy)
				cout << "F";
			else {
				bool printedTail = false;
				for (int b = 0; b < tailLength; b++) {
					if (tailCoordinates[0][b] == l && tailCoordinates[1][b] == k) {
						cout << "o";
						printedTail = true;
					}
				}
				if (!printedTail)
					cout << " ";
			}
		}
		cout << endl;
	}
	cout << "  ";
	for (int j = 0; j < gameWidth+1; j++) {
		cout << "--";
	}
	cout << "-" << endl;
	
	cout << "Score: " << score;
}

void Snake::keyInput () {
	
}

void Snake::gameWork () {
	
}

void gamePlay() {
	
}

Snake::Snake () { //default constructor
}

Snake::Snake(int requiredWidth, int requiredHeight) {
	
}

Snake::~Snake {
	
}