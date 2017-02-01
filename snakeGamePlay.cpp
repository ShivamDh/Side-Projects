#include <iostream>
#include <stdlib.h>
#include "snakeGame.h"
using namespace std;


int main () {
	
	cout << "Would you like to:" << endl;
	cout << "   (1) Create your own game" << endl;
	cout << "   (2) Use the default version" << endl;
	int choice;
	cin >> choice;
	
	if (choice == 1) {
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
		
		cout << endl << "Would you like to change the head of the snake to something else? (Y/N)";
		cout << endl << "\t Current Head Symbol: O\n";
		char choice;
		char head = '\0'; //initializing a null character tail to start off
		cin >> choice;
		if (choice == 'y' || choice == 'Y'){
			cout << "Type the symbol (1 character) you choose as your snake head: ";
			cin >> head;
		}
		
		cout << endl << "Would you like to change the tail of the snake to something else? (Y/N)";
		cout << endl << "\t Current Head Symbol: o\n";
		char choice2;
		char tail = '\0'; //initializing a null character tail to start off
		cin >> choice2;
		if (choice2 == 'y' || choice2 == 'Y'){
			cout << "Type the symbol (1 character) you choose as your snake tail: ";
			cin >> tail;
		} 
		
		if (head == '\0' && tail == '\0') 
			Snake game(newWidth, newHeight);
		else if (head == '\0')
			Snake game (newWidth, newHeight, 'O', tail);
		else if (tail == '\0')
			Snake game (newWidth, newHeight, head, 'o');
		else
			Snake game (newWidth, newHeight, head, tail);
		
		
	} else if (choice == 2) {
		Snake game;
	}
	
	gameFinished: return 0;
}
