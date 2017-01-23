#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <vector>
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
		Snake game(newWidth, newHeight);
	} else if (choice == 2) {
		Snake game;
	}
	
	
	
	return 0;
}
