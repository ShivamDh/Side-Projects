#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct Players {
	//inputted basic statistics
	char name[50]; //first and/or last name of person
	unsigned short int GP; //games played
	unsigned short int goals;
	unsigned short int assists;
	unsigned short int points;
	short int plus_minus;
	unsigned short int shots; //on goal
	unsigned short int PIM; //penalty minutes
	unsigned short int hits; 
	unsigned short int blocked_shots; 
	float faceoff_percent; 
	char ATOI[6]; //average time on ice
	//calculated advanced metrics
	float shot_percent;
	float goals_per_60;
	float assists_per_60;
	float points_per_60;
	float shots_per_60;
	float plus_minus_per_60;
	float PIM_per_game;
	float goal_percentage; //goals account for how much of the total points
	float assist_percentage; //assists account for how much of the total points
	float defensiveness; //a combination of hits and blocked shots combined with games played
} thePlayers, *PlayerStats;

int readFile (const char* tfile);
int calcStats (int PlayerNumber);
int exportData (int Players);

PlayerStats allPlayers; //gloabl scope struct array pointer
int main () {
	printf ("Welcome to Hockey Manager,\nThis program that can be used to filter and sort statistics provided by you.\
	\nYour text file will be read and presented back in a comma separated value file (.csv) for you to analyze\n");
	
	printf ("\nEnter the file name (with .txt extension) you wish to open,\
	\nEnsure it is in the same folder as this program: ");
	char inputFile [50];
	scanf ("%s", inputFile); //attain input file name
	
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
	
	if ((calcStats (people_number) != 0)) { //error checking from calcStats function
		printf ("\nAn error occurred during advanced metrics calculations");
		return -1;
	}
	
	if ((exportData(people_number) != 0)) {
		printf ("\nAn error occurred during advanced metrics calculations");
		return -1;
	}
	
	printf ("\n\nFile has been read successfully! Open up HockeyStats.csv to see your new .csv file\n");
	
	return 0;
	
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
			int ch = 0;
			while (temporary[ch] != '\0')
				ch++;
			
			fseek (FileIN, -ch, SEEK_CUR); //move back specific number of places according the number of digits
		} else {
			strcat(allPlayers[i].name, " "); //if 2nd word was indeed a character, player has a 2 word name
			strcat(allPlayers[i].name, temporary); // join the 2 words to form one string in the struct
		}
		
		char t;
		t = getc(FileIN);
		while (!isalnum(t) && t!=EOF) //move forward until alphanumeric character seen
			t = getc(FileIN);
		
		if (!isalpha(t)) {
			int x = 0;
			int checker = 1000; //random large number added, will be used to count up char from mins to secs stat
			while (t != ' ' && t != '\n' && t != EOF && x < 5) {
				allPlayers[i].ATOI[x] = t;
				x++;
				t = getc (FileIN);
				if (t == ':') { //check for valid minutes number in ATOI
					checker = x;
					int check_mins = atoi (allPlayers[i].ATOI);
					if (check_mins < 0 || check_mins > 60) {
						printf ("Invalid ATOI minutes for player %d\n", i+1);
						return -1;
					}
				}
				if (x == checker + 2) { //check for valid seconds number in ATOI
					char secs [3];
					memcpy(secs, &allPlayers[i].ATOI[3], 2);
					secs[3] = '\0';
					int check_secs = atoi (secs);
					if (check_secs < 0 || check_secs > 60) {
						printf ("Invalid ATOI minutes for player %d\n", i+1);
						return -1;
					}
				}
			}
			if (x == 0) { //if no ATOI stat found
				memcpy(allPlayers[i].ATOI, "00:00", 5);
			}
			if (x == 2) { //if only ATOI mins found
				allPlayers[i].ATOI[2] = ':';
				allPlayers[i].ATOI[3] = '0';
				allPlayers[i].ATOI[4] = '0';
			}
			allPlayers[i].ATOI[5] = '\0'; //add null character
		} else {
			printf ("\nError: No ATOI stat found, a crucial statistic that is needed");
			return -1;
		}
		
		int num_signed_int = 0;
		int temp[9] = {0}; //temp array to store data from file
		
		for (int structElements = 0; structElements < 9; structElements++) {	
			
			if (fscanf (FileIN, "%d", &temp[structElements]) == 0) //error occurred
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
		
		//error checking to ensure stats entered make sense in the hockey sense
		if ((temp[1] + temp[2] != temp[3]) || (temp[1] > temp[3]) || (temp[2] > temp[3])) {
			printf ("Invalid number of goals/assists/points for player %d, goals+assists = points\n", i+1);
			return -1;
		}
		
		if ((temp[1] > temp[5])) {
			printf ("Invalid number of goals/shots for player %d, goals+assists = points\n", i+1);
			return -1;
		}
		
		allPlayers[i].faceoff_percent = 0; 
		fscanf (FileIN, "%f", &allPlayers[i].faceoff_percent); //directly put in the faceoff_percent value
		if (allPlayers[i].faceoff_percent < 0) {
			printf ("Invalid Faceoff Percentage statistic entered, must be a positive value\n");
		}
		
		//transfer over data from temp integer array to struct data
		allPlayers[i].GP = temp[0]; 
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

int calcStats (int PlayerNumber) {
	float fATOI;
	
	for (int num = 0; num < PlayerNumber; num++) {
		float TOI_mins = 0; //calculating the ATOI stat as a float
		int loc = 0;
		if (allPlayers[num].ATOI[loc] > '0' && allPlayers[num].ATOI[loc] < '6') {
			loc++;
			if (allPlayers[num].ATOI[loc] == ':') { //single minute ATOI
				char temp_ATOI[2]; //a temporary string
				temp_ATOI[0] = allPlayers[num].ATOI[loc-1];
				temp_ATOI[1] = '\0';
				int temporary_ATOI = atoi(temp_ATOI); //get integer vaule of the ATOI minutes
				TOI_mins += (float)temporary_ATOI;
			} else if (allPlayers[num].ATOI[loc] > '0' && allPlayers[num].ATOI[loc] <= '9') { //double digit minute ATOI
				char temp_ATOI2 [3]; //a temporary string for a 2-digit ATOI minute
				memcpy (temp_ATOI2, allPlayers[num].ATOI, 2);
				temp_ATOI2[2] = '\0';
				int temporary_ATOI2 = atoi(temp_ATOI2); //calc the integer value of ATOI in minutes
				TOI_mins += temporary_ATOI2;
				loc++;
			} else 
				break;
			
			loc++;
			char secs_ATOI[3]; //same procedure for calculating ATOI seconds as an integer value from string
			secs_ATOI[0] = allPlayers[num].ATOI[loc];
			loc++;
			secs_ATOI[1] = allPlayers[num].ATOI[loc];
			secs_ATOI[2] = '\0';
			int ATOI_secs = atoi(secs_ATOI); //calculate the integer value of the ATOI seconds
			fATOI = TOI_mins + (float)(ATOI_secs/60.0); //combine mins and secs to form the floating number for ATOi
		} else {
			printf ("Invalid ATOI present\n");
			return -1;
		}
		
		//default parameters for calculated values;
		allPlayers[num].shot_percent = allPlayers[num].points_per_60 = allPlayers[num].shots_per_60 = 0;
		allPlayers[num].goals_per_60 = allPlayers[num].assists_per_60 = allPlayers[num].plus_minus_per_60 = 0;
		allPlayers[num].goal_percentage = allPlayers[num].assist_percentage = 0;
		allPlayers[num].defensiveness  = allPlayers[num].PIM_per_game = 0;
		
		//calculate the different stats from the basic stats inputted for each player, only if they are non-zero
		if (allPlayers[num].points)
			allPlayers[num].points_per_60 = (float)allPlayers[num].points * (60.0/fATOI);
		
		if (allPlayers[num].shots)
			allPlayers[num].shots_per_60 = (float)allPlayers[num].shots * (60.0/fATOI);
		
		if (allPlayers[num].goals) {
			allPlayers[num].goals_per_60 = (float)allPlayers[num].goals * (60.0/fATOI);
			
			if (allPlayers[num].points)
				allPlayers[num].goal_percentage = ((float)allPlayers[num].goals)/((float)allPlayers[num].points) * 100.0;
			
			if (allPlayers[num].shots)
				allPlayers[num].shot_percent = ((float)allPlayers[num].goals)/((float)allPlayers[num].shots) * 100.0;
		}
		
		if (allPlayers[num].assists) {
			allPlayers[num].assists_per_60 = (float)allPlayers[num].assists * (60.0/fATOI);
			
			if (allPlayers[num].points)
				allPlayers[num].assist_percentage = ((float)allPlayers[num].assists)/((float)allPlayers[num].points) * 100.0;
			
		}
		
		if (allPlayers[num].plus_minus)
			allPlayers[num].plus_minus_per_60 = (float)allPlayers[num].plus_minus * (60.0/fATOI);
		
		if (allPlayers[num].GP) {
			if (allPlayers[num].PIM)
				allPlayers[num].PIM_per_game = ((float)allPlayers[num].PIM) / ((float)allPlayers[num].GP);
			
			if (allPlayers[num].hits || allPlayers[num].blocked_shots) //only one of them has to be non-zero since this is just addition
				allPlayers[num].defensiveness = ((float)(allPlayers[num].hits + allPlayers[num].blocked_shots)) / ((float)allPlayers[num].GP);
		}
		
	}
	
	return 0;
}

int exportData (int Players) {
	FILE* csvFile;
	csvFile = fopen ("HockeyStats.csv", "w");
	
	//print the top row, all headers for the statistics
	fputs("Name,Goals,Assists,Points,+/-,Shots,PIM,Hits,Blocks,F%,ATOI,\
	S%,Goals/60,Assists/60,Points/60,Shots/60,+/- /60,PIM/game,G%,A%,Def,\n",csvFile);
	
	//print out all the stats of each player, floats reduced to 2 decimal place
	// "'" added in front of ATOI to avoid Excel from convertin to time/date format
	for (int e = 0; e < Players; e++) {
		int safety = 0;
		safety = fprintf(csvFile, "%s,%d,%d,%d,%d,%d,%d,%d,%d,%.2f%,'%s,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,\n",\
		allPlayers[e].name,allPlayers[e].goals,allPlayers[e].assists,allPlayers[e].points,allPlayers[e].plus_minus,\
		allPlayers[e].shots,allPlayers[e].PIM,allPlayers[e].hits,allPlayers[e].blocked_shots,\
		allPlayers[e].faceoff_percent,allPlayers[e].ATOI,allPlayers[e].shot_percent,\
		allPlayers[e].goals_per_60,allPlayers[e].assists_per_60,allPlayers[e].points_per_60,\
		allPlayers[e].shots_per_60,allPlayers[e].plus_minus_per_60,allPlayers[e].PIM_per_game,\
		allPlayers[e].goal_percentage,allPlayers[e].assist_percentage,allPlayers[e].defensiveness);
		if (safety < 0){
			printf ("\nAn error occured when exporting the data, check your permission settings\n");
			return -1;
		}
	}
	
	fclose(csvFile);
	free(allPlayers);
	
	return 0;
}