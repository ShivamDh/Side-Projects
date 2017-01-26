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
	if (_kbhit()) {
		switch (_getch()) {
			case 97: //capital letter A
			case 65: //lowercase letter a
				dir = LEFT;
				break;
			case 100: //capital letter D
			case 68: //lowercase letter d
				dir = RIGHT;
				break;
			case 119: //capital letter W
			case 87: //lowercase letter w
				dir = UP;
				break;
			case 115: //capital letter S
			case 83: //lowercase letter s
				dir = DOWN;
				break;
			case 224: //arrow key inputs are used
				switch (_getch()) {
					case 75:
						dir = LEFT;
						break;
					case 77:
						dir = RIGHT;
						break;
					case 72:
						dir = UP;
						break;
					case 80:
						dir = DOWN;
						break;
					default:
						cout << endl << "Wrong key is being pressed" << endl;
						break;
				}
				break;
			case 27: //end program buttons
			case 81: //include Esc, 'q', Q, Ctr+C 
			case 113:
			case 3: 
				gameRunning = false;
				break;
		}
	} else 
		return;
}

void Snake::gameWork () {
	
}

void gamePlay() {
	
}

Snake::Snake () { //default constructor
	gameWidth = 20;
	gameHeight = 20;
	tailLength = 0;
	setup ();
	gamePlay();
}

Snake::Snake(int requiredWidth, int requiredHeight) {
	
}

Snake::~Snake {
	
}