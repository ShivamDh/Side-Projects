#include <stdio.h>
#include <stdlib.h>

	// unsigned short int GWG; //gamne winning goals
	// unsigned short int PPG; //powerplay goals
	// unsigned short int PPA; //powerplay assists 
	// unsigned short int SHG; //short handed goals
	// unsigned short int SHA; //short handed assists
	// unsigned short int giveaways;
	// unsigned short int takeaways;
struct Players {
	char name[50]; //first and/or last name of person
	unsigned short int GP; //games played
	unsigned short int goals;
	unsigned short int assists;
	unsigned short int points;
	short int plus_minus;
	unsigned short int shots;
	unsigned short int PIM; //penalty minutes
	unsigned short int hits; 
	unsigned short int blocked_shots; 
	float ATOI; //average time on ice (per game)
};

int readFile (Players* allPlayers);

int main () {
	printf ("Welcome to Hockey Manager,\nThis program that can be used to filter and sort statistics provided by you.\
	\nYour text file will be read and presented back in a comma splicted file (.csv) for you to analyze\n");
	
	printf ("\nEnter the file name (with .txt extension) you wish to open,\
	\nEnsure it is in the same folder as this program: ");
	char inputFile [50];
	scanf ("%s", inputFile);
	
	printf ("%s", inputFile);
	
	Players* People;
	int people_number = 0; //the number of players that are present in the text file to be analyzed
	
	people_number = readFile (People);
	if (people_number < 0) {
		printf ("An error occurred when reading data, ensure text file has statistics of each person on a separate line\
		\nAlso ensure that each statisitc is in order and it is separated by a space(s) or comma(s)");
		return -1;
	} else if (people_number == 0) {
		printf ("No data was found in the text file");
	}
	
	
	
	
	
	People = new Players[10];
	People[1].GP = 10;
	printf ("%d", People[1].GP);
	
}

int readFile (Players* allPlayers) {
	int numPpl = 0;
	
	
	
	return numPpl; //return teh value of the number of people;
} 