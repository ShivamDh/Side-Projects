#ifndef SNAKEGAME_H
#define SNAKEGAME_H

enum snakeDirection { LEFT, RIGHT, UP, DOWN, STOP };

class Snake {
	public:
		Snake ();
		Snake (const int requiredWidth, const int requiredHeight);
		~Snake();
		int getScore();
	
	private:
		//paramters
		bool isGameRunning;
		int gameWidth;
		int gameHeight;
		snakeDirection direction;
		int xCoor, yCoor;
		int score;
		int tailLength;
		void initialGame();
		void drawCanvas();
		void keyInput ();
		void gameWork ();
		void gamePlay();
};
#endif
