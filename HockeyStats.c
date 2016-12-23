#include <stdio.h>
#include <stdlib.h>

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
	float faceoff_percent; 
};

int readFile (Players* allPlayers, const char* tfile);

int main () {
	printf ("Welcome to Hockey Manager,\nThis program that can be used to filter and sort statistics provided by you.\
	\nYour text file will be read and presented back in a comma splicted file (.csv) for you to analyze\n");
	
	printf ("\nEnter the file name (with .txt extension) you wish to open,\
	\nEnsure it is in the same folder as this program: ");
	char inputFile [50];
	scanf ("%s", inputFile);
	
	int count1 = 0;
	while (inputFile[count1] != '.') //this will find the length of input file
		count1++;
	
	if (inputFile[count1+1] != 't' || inputFile[count1+2] != 'x' || inputFile[count1+3] != 't') {
		printf ("Invalid file name inputted, not a .txt extension");
		return -1;
	}
	
	Players* People;
	int people_number = 0; //the number of players that are present in the text file to be analyzed
	
	people_number = readFile (People, inputFile);
	if (people_number < 0) {
		printf ("An error occurred when reading data, ensure text file has statistics of each person on a separate line\
		\nAlso ensure that each statisitc is in order and it is separated by a space(s) or comma(s)\n");
		return -1;
	} else if (people_number == 0) {
		printf ("No data was found in the text file");
	}
	
	
}

int readFile (Players* allPlayers, const char* tfile) {
	int numPpl = 0;
	FILE* FileIN;
	
	FileIN = fopen(tfile, "r");
	if (FileIN == NULL) { //error check to ensure file opened properly
		printf ("Input file could not be opened\n");
		return -1;
	}
	
	FILE* csvFile;
	csvFile = fopen("HockeyStatistics.csv", "w'");
	
	char temp[500]; int linecheck;
	while (fgets(temp, 60, FileIN) != NULL) {
		linecheck = 0;
		while (temp[linecheck] != '\n')
			linecheck++;
		if (linecheck == 0) //empty line found
			continue;
		numPpl++; //count up the number of players to have their statistics inputted
	}
	
	clearerr(inFile);
	fseek(inFile, 0, SEEK_SET);
	
	allPlayers = (Players*) malloc (numPpl*sizeof(Players)); //create appropriate number of structs
	
	fclose(FileIN); //close the files
	fclose(csvFile);
	
	return numPpl; //return teh value of the number of people;
} 