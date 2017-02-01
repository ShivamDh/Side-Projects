#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <deque> //needed for the deque to be properly defined

//enum regarding snake direction control
enum snakeDirection { LEFT, RIGHT, UP, DOWN, STOP };

class Snake {
	public:
		Snake (); //default constructor
		//constructor for specified user dimensioss for game play
		Snake (const int requiredWidth, const int requiredHeight);
		~Snake(); //destructor
	
	private:
		//paramters
		bool isGameRunning; //boolean to check is the game still continuing
		int gameWidth; //game area width`
		int gameHeight; //game area height
		snakeDirection direction; //direction of the snake, defined using enums
		int xCoor, yCoor; //x and y coordinates (specifically of the head)
		int levelUpx, levelUpy; //x and y coordinates of the level up food for snake
		int score; //current game score
		int tailLength; //length of the tail
		//create deque linked lists to store previous coordinates of tail coordinates
		std::deque <int> tailCoordinates[2]; 
		void initialGame(); //method for starting the game up 
		void drawCanvas(); //method for drawing the game
		void keyInput(); //method that checks for keyboard input from user
		void gameWork(); //method that runs over all the logic and game constraints
		void gamePlay(); //keeps the game running, moves frame to frame
};
#endif
