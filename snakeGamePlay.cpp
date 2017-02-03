#include <iostream>
#include <stdlib.h>
#include "snakeGame.h"
using namespace std;


int main () {
	
	cout << "Would you like to:" << endl; //ask user input regarding game settings
	cout << "   (1) Create your own game" << endl;
	cout << "   (2) Use the default version" << endl;
	int choice;
	cin >> choice;
	
	if (choice == 1) { //user wants to create their own game
		int newWidth = 0;
		int newHeight = 0;
		AskWidth: cout << endl << "What width should your snake game have: ";
		cin >> newWidth;
		if (newWidth < 5) {
			cout << endl << "Sorry, your specified width is too small, try again";
			goto AskWidth;
		}
		AskHeight: cout << "What height should your snake game have: ";
		cin >> newHeight;
		if (newHeight < 5) {
			cout << endl << "Sorry, your specified height is too small, try again";
			goto AskHeight;
		}
		//finished setting game dimesions, onto setting snake features
		cout << endl << "Would you like to change the head of the snake to something else?";
		cout << endl << "\t Current Head Symbol: O\n";
		cout << endl << "Press Y/y to change the symbol, press N/n to keep it the same: ";
		char choice;
		char head = '\0'; //initializing a null character tail to start off
		cin >> choice;
		if (choice == 'y' || choice == 'Y'){
			cout << "Type the symbol (1 character) you choose as your snake head: ";
			cin >> head;
		}
		
		cout << endl << "Would you like to change the tail of the snake to something else?";
		cout << endl << "\t Current Head Symbol: o\n";
		cout << endl << "Press Y/y to change the symbol, press N/n to keep it the same: ";
		char choice2;
		char tail = '\0'; //initializing a null character tail to start off
		cin >> choice2;
		if (choice2 == 'y' || choice2 == 'Y'){
			cout << "Type the symbol (1 character) you choose as your snake tail: ";
			cin >> tail;
		} 
		
		//ask if user wants a boundaryless snake game where walls of snake game are warped around and no restrictions of boundaries
		cout << endl << "How do you want to set up the wall boundaries:";
		cout << "\n\t(1) Warp Around \n\t(2) Be Rigid and no wrapping/warping\n";
		int choice3;
		cin >> choice3;
		
		if (head == '\0' && tail == '\0') { //no unique head or tail chosen
			if (choice3 == 2)
				Snake game (newWidth, newHeight, false);
			else 
				Snake game (newWidth, newHeight);
		} else if (head == '\0') { //unique tail chosen
			if (choice3 == 2)
				Snake game (newWidth, newHeight, 'O', tail, false);
			else 
				Snake game (newWidth, newHeight, 'O', tail);
		} else if (tail == '\0') { //unique head chosen
			if (choice3 == 2)
				Snake game (newWidth, newHeight, head, 'o', false);
			else 
				Snake game (newWidth, newHeight, head, 'o');
		} else { //unique head and tail chosen
			if (choice3 == 2)
				Snake game (newWidth, newHeight, head, tail, false);
			else 
				Snake game (newWidth, newHeight, head, tail);
		}
	} else if (choice == 2) { //user just wants to play default game version
		myGame = new Snake();
	}
	
	gameFinished: return 0;
}
