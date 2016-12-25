#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Players {
	//inputted basic statistics
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
	//calculated advanced metrics
	float shot_percent;
	
} thePlayers, *PlayerStats;

int readFile (const char* tfile);
bool calcStats (int PlayerNumber);
bool exportData (int Players);

PlayerStats allPlayers;
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
	
	int people_number = 0; //the number of players that are present in the text file to be analyzed
	
	people_number = readFile (inputFile);
	if (people_number < 0) {
		printf ("An error occurred when reading data, ensure text file has statistics of each person on a separate line\
		\nAlso ensure that each statistic is in order and it is separated by a space(s) or comma(s)\n");
		return -1;
	} else if (people_number == 0) {
		printf ("No data was found in the text file");
	}
	
	if (!(calcStats (people_number))) {
		printf ("\nAn error occurred during advanced metrics calculations");
		return -1;
	}
	
	if (!(exportData(people_number))) {
		printf ("An error occurred during exporting data");
		return -1;
	}
	
	printf ("Test: Program finished running");
	
}

int readFile (const char* tfile) {
	int numPpl = 0;
	FILE* FileIN;
	
	FileIN = fopen(tfile, "r");
	if (FileIN == NULL) { //error check to ensure file opened properly
		printf ("Input file could not be opened\n");
		return -1;
	}
		
	char temp[500]; int linecheck;
	while (fgets(temp, 499, FileIN) != NULL) { //take in line by line
		linecheck = 0;
		while (temp[linecheck] != '\n')
			linecheck++;
		if (linecheck == 0) //empty line found
			continue;
		numPpl++; //count up the number of players to have their statistics inputted
	}
	
	clearerr(FileIN); //move back to the beginning to now start inputting tne data
	fseek(FileIN, 0, SEEK_SET);
	
	allPlayers = (PlayerStats) malloc (numPpl*sizeof(thePlayers)); //create appropriate number of structs
	
	int i = 0;
	for ( ; i < numPpl; i++) {
		fscanf(FileIN, "%49s", allPlayers[i].name); //take in the first word (should be a name)
		char temporary[25];
		fscanf(FileIN, "%24s", temporary); //take in the next word assuming it is the last name
		
		//if the first letter is not a character, it means that 2nd word was indeed a statistic, player's name is only 1 word
		if (temporary[0] > 47 && temporary[0] < 58) { 
			int ch = atoi (temporary); //convert number to integer
			int digits = 0;
			while (ch != 0) { //find the number of digits in the number
				ch = ch/10;
				digits++;
			}
			fseek (FileIN, -(digits+1), SEEK_CUR); //move back specific number of places according the number of digits
		} else {
			strcat(allPlayers[i].name, " "); //if 2nd word was indeed a character, player has a 2 word name
			strcat(allPlayers[i].name, temporary); // join the 2 words to form one string in the struct
		}
		
		int num_signed_int = 0;
		int temp[9] = {0}; //temp array to store data from file
		
		for (int structElements = 0; structElements < 9; structElements++) {	
			
			if (fscanf (FileIN, "%d", &temp[structElements]) == 0) 
				continue;
			
			if ((structElements < 4 || structElements > 4) && structElements < 10) { //error checking for statistic 1-4 and 5-10
				if (temp[structElements] < 0 && temp[structElements] > 65535) {
					printf ("Invalid numbers present in the data provided for player %d, statistics %d", i, structElements);
					return -1;
				}
			}
			
			char separation = fgetc (FileIN); //temp char to filter out separating characters between stat numbers
			while ((separation < '0' || separation > '9') && (separation != '\n' && separation != EOF))
				separation = fgetc (FileIN);
			
			if ((separation == EOF) || separation == '\n') //finish taking in input if EOF or end of line seen
				continue;
			else 
				fseek(FileIN, -1, SEEK_CUR); //move back one character to continue taking in statistics
		}
		allPlayers[i].faceoff_percent = 0; 
		fscanf (FileIN, "%f", &allPlayers[i].faceoff_percent); //directly put in the faceoff_percent value
		if (allPlayers[i].faceoff_percent < 0) {
			printf ("Invalid Faceoff Percentage statistic entered, must be a positive value\n");
		}
		
		allPlayers[i].GP = temp[0]; //transfer over data from temp integer array to struct data
		allPlayers[i].goals = temp[1];
		allPlayers[i].assists = temp[2];
		allPlayers[i].points = temp[3];
		allPlayers[i].plus_minus = temp[4];
		allPlayers[i].shots = temp[5];
		allPlayers[i].PIM = temp[6];
		allPlayers[i].hits = temp[7];
		allPlayers[i].blocked_shots = temp[8];
		
		fseek (FileIN, -1, SEEK_CUR);
		char tem = fgetc (FileIN);
		while (tem != '\n' && tem != EOF) //move past any unneccessary characaters at the end of the line
			tem = fgetc (FileIN);
		
	}
	fclose(FileIN); //close the files
	
	return numPpl; //return the value of the number of people;
} 

bool calcStats (int PlayerNumber) {
	int y= 1+1;
	
	return true;
}
