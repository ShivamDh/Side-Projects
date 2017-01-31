#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "snakeGame.h"
using namespace std;



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
				isGameRunning = false;
				break;
		}
	} else 
		return;
}

void Snake::gameWork () {
	int prevX = tailCoordinates[0][0];
	int prevY = tailCoordinates[1][0];
	int prev2X, prev2Y;
	tailCoordinates[0][0] = x;
	tailCoordinates[1][0] = y;
	for (int a = 1; a < tailLength; a++) {
		prev2X = tailCoordinates[0][a];
		prev2Y = tailCoordinates[1][a];
		tailCoordinates[0][a] = prevX;
		tailCoordinates[1][a] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	
	switch(dir) {
		case LEFT: 
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;
	}
	if (x >= 2*width-1)
		x = 0;
	else if (x < 0)
		x = 2*width-2;
	if (y >= height)
		y = 0;
	else if (y < 0)
		y = height;
		
	for (int c = 0; c < tailLength; c++) {
		if (tailCoordinates[0][c] == x && tailCoordinates[1][c] == y)
			isGameRunning = false;
	}
	
	if (x == fx && y == fy) {
		score += 10;
		srand(time(NULL));
		fx = rand() % width;
		fy = rand() % height;
		tailLength++;
	}
}

void gamePlay() {
	while (isGameRunning) {
		system("cls"); //clear console screen for snake game window to appear
		cout << endl << "  A CLASSIC GAME OF SNAKE" << endl << endl;
		for (int i = 0; i < width/12; i++)
			cout << "\t";
		cout << "Created by Shivam Dharme" << endl;
		draw();
		input();
		logic();
		cout << endl << endl << "Press Esc or quit to exit the game anytime" << endl;
		cout << "Control the snake using Left/Right/Up/Down keys" << endl;
	}
}

Snake::Snake () { //default constructor
	gameWidth = 20;
	gameHeight = 20;
	tailLength = 0;
	setup ();
	gamePlay();
}

Snake::Snake(int requiredWidth, int requiredHeight) {
	width = requiredWidth;
	height = requiredHeight;
	tailLength = 0;
	setup ();
	gamePlay();
}

Snake::~Snake {
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