#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <deque>
#include "snakeGame.h"
using namespace std;


void Snake:: initialGame() {
	//start tje game at halt posiiton
	isGameRunning = true;
	direction = STOP;
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
				cout << snakeHead;
			else if (l == levelUpx && k == levelUpy)
				cout << "F";
			else {
				bool printedTail = false;
				for (int b = 0; b < tailLength; b++) {
					if (tailCoordinates[0][b] == l && tailCoordinates[1][b] == k) {
						cout << snakeTail;
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
				direction = LEFT;
				break;
			case 100: //capital letter D
			case 68: //lowercase letter d
				direction = RIGHT;
				break;
			case 119: //capital letter W
			case 87: //lowercase letter w
				direction = UP;
				break;
			case 115: //capital letter S
			case 83: //lowercase letter s
				direction = DOWN;
				break;
			case 224: //arrow key inputs are used
				switch (_getch()) {
					case 75:
						direction = LEFT;
						break;
					case 77:
						direction = RIGHT;
						break;
					case 72:
						direction = UP;
						break;
					case 80:
						direction = DOWN;
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
				isGameRunning = false;
				break;
		}
	} else 
		return;
}

void Snake::gameWork () {
	if (xCoor == levelUpx && yCoor == levelUpy) {
		score += 10;
		srand(time(NULL));
		tailCoordinates[0].push_front(xCoor);
		tailCoordinates[1].push_front(yCoor);
		levelUpx = rand() % gameWidth;
		levelUpy = rand() % gameHeight;
		tailLength++;
	} else {
		tailCoordinates[0].push_front(xCoor);
		tailCoordinates[1].push_front(yCoor);
		tailCoordinates[0].pop_back();
		tailCoordinates[1].pop_back();		
	}
	
	switch(direction) {
		case LEFT: 
			xCoor--;
			break;
		case RIGHT:
			xCoor++;
			break;
		case UP:
			yCoor--;
			break;
		case DOWN:
			yCoor++;
			break;
		default:
			break;
	}
	if (xCoor >= 2*gameWidth-1)
		xCoor = 0;
	else if (xCoor < 0)
		xCoor = 2*gameWidth-2;
	if (yCoor >= gameHeight)
		yCoor = 0;
	else if (yCoor < 0)
		yCoor = gameHeight;
		
	for (int c = 0; c < tailLength; c++) {
		if (tailCoordinates[0][c] == xCoor && tailCoordinates[1][c] == yCoor)
			isGameRunning = false;
	}
	
}

void Snake::gamePlay() {
	while (isGameRunning) {
		system("cls"); //clear console screen for snake game window to appear
		cout << endl << "  A CLASSIC GAME OF SNAKE" << endl << endl;
		for (int i = 0; i < gameWidth/12; i++)
			cout << "\t";
		cout << "Created by Shivam Dharme" << endl;
		drawCanvas();
		keyInput();
		gameWork();
		cout << endl << endl << "Press Esc or quit to exit the game anytime" << endl;
		cout << "Control the snake using Left/Right/Up/Down keys" << endl;
	}
}

Snake::Snake () { //default constructor
	gameWidth = 20;
	gameHeight = 20;
	tailLength = 0;
	snakeHead = 'O';
	snakeTail = 'o';
	initialGame();
	gamePlay();
}

Snake::Snake(int requiredWidth, int requiredHeight) {
	gameWidth = requiredWidth;
	gameHeight = requiredHeight;
	tailLength = 0;
	snakeHead = 'O';
	snakeTail = 'o';
	initialGame();
	gamePlay();
}

Snake::Snake(int requiredWidth, int requiredHeight, char specifiedHead, char specifiedTail) {
	gameWidth = requiredWidth;
	gameHeight = requiredHeight;
	tailLength = 0;
	snakeHead = specifiedHead;
	snakeTail = specifiedTail;
	initialGame();
	gamePlay();
}

Snake::~Snake () {
	//just some ending dialouge
	if (score < 100)
		cout << endl << "Can't you do better than that?" << endl;
	else if (score < 250)
		cout << endl << "That's a good score, think you can beat that?" << endl;
	else if (score < 500)
		cout << endl << "Very impressive score, tough to top" << endl;
	else 
		cout << endl << "Insane score, no one can beat that!" << endl;
}