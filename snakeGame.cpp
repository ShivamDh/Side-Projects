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
	cout << "  "; //draw upper boundary
	for (int i = 0; i < gameWidth+1; i++) {
		cout << "--";
	}
	
	cout << "-" << endl; //compensation character for right corner
	
	for (int k = 0; k < gameHeight; k++) { //drawing the 2nd to n-1 rows of the game
		for (int l = 0; l < 2*gameWidth; l++) {
			if (l == 0 || l == 2*gameWidth-1)
				cout << "  |"; //left boundary
			
			if (k == yCoor && l == xCoor)
				cout << snakeHead; //draw snakehead if coordinates match
			else if (l == levelUpx && k == levelUpy)
				cout << "F"; //draw levelup symbol if coordinates match
			else {
				bool printedTail = false;
				for (int b = 0; b < tailLength; b++) {
					if (tailCoordinates[0][b] == l && tailCoordinates[1][b] == k) {
						cout << snakeTail; //draw snaketail if coordinates match
						printedTail = true;
					}
				}
				if (!printedTail)
					cout << " ";
			}
		}
		cout << endl;
	}
	cout << "  "; //drawing lower boundary/wall
	for (int j = 0; j < gameWidth+1; j++) {
		cout << "--";
	}
	cout << "-" << endl;
	
	cout << "Score: " << score; //display score
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
			case 9: //tab key, wanting to change game settings
				edit();
				break;
		}
	} else 
		return;
}

void Snake::gameWork () {
	if (xCoor == levelUpx && yCoor == levelUpy) { //if snake moves over the level up icon
		score += 10;
		srand(time(NULL));
		tailCoordinates[0].push_front(xCoor); //add one more to the tail coordinates
		tailCoordinates[1].push_front(yCoor);
		levelUpx = rand() % gameWidth; //get a new location for level up icon
		levelUpy = rand() % gameHeight;
		tailLength++;
	} else {
		tailCoordinates[0].push_front(xCoor); //keep adding the latest coordinate to tail coordintaes
		tailCoordinates[1].push_front(yCoor); //this is the snake head that now becomes the first tail
		tailCoordinates[0].pop_back(); //remove the coordinates for the last tail section
		tailCoordinates[1].pop_back();		
	}
	
	switch(direction) { //what direction the snake is moving in
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
	if (xCoor >= 2*gameWidth-1) { //boundary conditions depending on whether warping from one side of the wall to the other is allowed
		warpWalls ? xCoor = 0 : isGameRunning = false;
	} else if (xCoor < 0) {
		warpWalls ? xCoor = 2*gameWidth-2 : isGameRunning = false;
	} if (yCoor >= gameHeight) {
		warpWalls ? yCoor = 0 : isGameRunning = false;
	} else if (yCoor < 0) {
		warpWalls ? yCoor = gameHeight : isGameRunning = false;
	}
		
	for (int c = 0; c < tailLength; c++) { //if the snake head runs into the snake tail
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
		//basic game instructions listed below the game display
		cout << endl << endl << "Press Esc or quit to exit the game anytime" << endl;
		cout << "Press Tab to edit/change game settings" << endl;
		cout << "Control the snake using Left/Right/Up/Down keys" << endl;
	}
}

Snake::Snake () { //default constructor
	warpWalls = true; //warping default allowed
	gameWidth = 20;
	gameHeight = 20;
	tailLength = 0;
	snakeHead = 'O';
	snakeTail = 'o';
	initialGame();
	gamePlay();
}

Snake::Snake(int requiredWidth, int requiredHeight, bool warp) {
	warpWalls = warp;
	gameWidth = requiredWidth;
	gameHeight = requiredHeight;
	tailLength = 0;
	snakeHead = 'O';
	snakeTail = 'o';
	initialGame();
	gamePlay();
}

Snake::Snake(const int requiredWidth, const int requiredHeight, const char specifiedHead, const char specifiedTail, bool warp) {
	warpWalls = warp;
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

void Snake::edit() {
	pickEdit: cout << endl << "What gameplay settings would you like to edit: " << endl;
	cout << "\t (1) Game Width \n\t (2) Game Height \n\t (3) Head Symbol \n\t (4) Tail Symbol \n\t (5) Boundary Warp";
	cout << endl;
	int selection;
	cin >> selection;
	switch (selection) { //switch table regarding what game setting user chose the edit
		case 1:
			cout << "Original height was: " << gameHeight;
			cout << endl << "Pick your new height: ";
			cin >> gameHeight;
			break;
		case 2: 
			cout << "Original width was: " << gameWidth;
			cout << endl << "Pick your new width: ";
			cin >> gameWidth;
			break;
		case 3: 
			cout << "Original head symbol was: " << snakeHead;
			cout << endl << "Pick your new snake head: ";
			cin >> snakeHead;
			break;
		case 4: 
			cout << "Original tail symbol was: " << snakeTail;
			cout << endl << "Pick your new snake tail: ";
			cin >> snakeTail;
			break;
		case 5: 
			warpWalls ^= 1; //flip boolean value
			cout << "Boundary Warp will now be: ";
			(warpWalls)? cout << "True" : cout << "False";
			cout << endl << "Confirm switch with Y/y, abort with N/n:  ";
			char boolSwitch;
			cin >> boolSwitch;
			if (boolSwitch == 'n' || boolSwitch == 'N')
				warpWalls ^= 1;
			break;
		default:
			cout << endl << "Wrong selection picked, try again: " << endl;
			goto pickEdit;
			break;
	}
}