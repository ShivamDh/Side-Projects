#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Person {
	char firstName[20];
	char midInitial;
	char lastName[20];
	int age;
	char city[20];
	char country[20];
	struct Person* next; //the struct pointer for the next item in the list
}People, *thePeople;

int read ();
int read(const char* iFile);

thePeople head; //struct pointer for the first struct, global scope to keep it accessible in all functions
int Ppl = 0;; //global scope integer for how many people exist within the linked list

int main() {
	printf("How would you like to enter the data?\n");
	printf("\t(1) Manually\n \t(2) Through a text file\n");
	
	int choice;
	scanf("%d", &choice);
	if (choice == 1) {
		if (read()){
			printf ("\nAn error occurred while inputting data manually\n");
			return -1;
		}
	} else if (choice == 2) {
		printf ("\nEnter the text file with extension (.txt)\n");
		printf ("Ensure that all 6 fields are entered in the text file, \
		\nif information is not present for a specific field, enter a '-' within that field:\n");
		char givenFile[50];
		scanf ("%s", givenFile);
		printf ("%s", givenFile);
		if (read (givenFile)) {
			printf ("\nAn error occurred when reading the file\n");
			return -1;
		} else 
			printf ("\nData has been read:");
		
	} else {
		printf ("Sorry wrong choice input entered");
		return -1;
	}
	
	thePeople toPrint = head;
	for (int reading = 0; reading < Ppl; reading++) {
		printf ("\nPerson %i: %s %c %s %i %s %s", reading, toPrint->firstName,\
		toPrint->midInitial, toPrint->lastName, toPrint->age, toPrint->city, toPrint->country);
		toPrint = toPrint->next;
		if (toPrint == NULL)
			break;
	}
	
	
	
	return 0;
}

int read () {
	int key = 65;
	puts ("Press Esc to finish inputting information\n");
	int attain_info = 0;
	head = (thePeople) malloc(sizeof(People)); //create one struct to begin with
	thePeople input = head;

	int check = 0; //a checker to know that every time a new person is made, new memory is used
	int maxL = 19; //the max length of any of the strings
	do {
		attain_info = attain_info % 6; //asking for the right information in the right order
		switch (attain_info) {
			case 0: 
				if(check){
					Ppl++;
					thePeople newPerson = (thePeople) malloc(sizeof(People));
					input->next = newPerson;
					input = newPerson;
				}
				printf("\n\nPerson %d\n", Ppl+1);
				puts ("Enter the first name: ");
				for (int j = 0; j < maxL-1; j++) {
					key = getch();
					if (key == 27 || key == 3) //escape or CtrC pressed
						goto inputEnded;
					else if (key == 13) { //new line char seen
						input->firstName[j] = 0;
						break;
					} else if (key == 8){ //if backspace is asked for
						input->firstName[j-1] = 0;
						j-=2;
						printf("\n%s", input->firstName);
						continue;
					}
					input->firstName[j] = key;
					printf ("%c", key);
				}
				break;
			case 1: 
				puts("\nEnter the middle initial: ");
				key = getch();
				if (key == 27 || key == 3) //escape or Ctr+C pressed
					goto inputEnded;
				printf ("%c", key);
				input->midInitial = key;
				break;
			case 2:
				puts("\nEnter the last name: ");
				for (int k = 0; k < maxL-1; k++) {
					key = getch();
					if (key == 27 || key == 3) //escape or CtrC pressed
						goto inputEnded;
					else if (key == 13) { //new line char seen
						input->lastName[k] = 0;
						break;
					} else if (key == 8){ //if backspace is asked for
						input->lastName[k-1] = 0;
						k-=2;
						printf("\n%s", input->lastName);
						continue;
					}
					input->lastName[k] = key;
					printf ("%c", key);
				}
				break;
			case 3:  {
				puts ("\nEnter their age: ");
				int numb = 0;
				key = getch();
				for (int l = 0; l < 3; l++) {
					if (!isdigit(key) && key != 8 && key != 13) {
						goto inputEnded;
						input->age = numb;
					}
					if (key == 8){
						l -=2;
						numb /= 10;
						printf ("\n%i", numb);
						key = getch();
						continue;
					} else if (key == 13) { //new line char seen
						break;
					}
					printf ("%c", key);
					numb = numb*10 + (key-48);
					key = getch();
				}
				input->age = numb;
				break; }
			case 4: 
				puts("\nEnter their city: ");
				for (int m = 0; m < maxL-1; m++) {
					key = getch();
					if (key == 27 || key == 3) //escape or CtrC pressed
						goto inputEnded;
					else if (key == 13) { //new line char seen
						input->city[m] = 0;
						break;
					} else if (key == 8){ //if backspace is asked for
						input->city[m-1] = 0;
						m-=2;
						printf("\n%s", input->city);
						continue;
					}
					input->city[m] = key;
					printf ("%c", key);
				}
				break;
			case 5:
				puts("\nEnter their country: ");
				for (int n = 0; n < maxL-1; n++) {
					key = getch();
					if (key == 27 || key == 3) //escape or CtrC pressed
						goto inputEnded;
					else if (key == 13) { //new line char seen
						input->country[n] = 0;
						break;
					} else if (key == 8){ //if backspace is asked for
						input->country[n-1] = 0;
						n-=2;
						printf("\n%s", input->country);
						continue;
					}
					input->country[n] = key;
					printf ("%c", key);
				}
				check = 1;
				break;
			default:
				printf ("\nAn error occurred during importing data");
				return -1;
				break;
		}
		attain_info++;
	} while (key != 27 && key != 3);
	inputEnded: return 0;	
}

int read(const char* iFile) { //reading the file if provided
	FILE* OpenFile;
	OpenFile = fopen(iFile, "r");
	
	if (OpenFile == NULL) { //error check to ensure file opened properly
		printf ("Input file was not opened\n");
		return -1;
	}
		
	char temp[150];
	int linechar;
	while (fgets(temp, 149, OpenFile) != NULL) { //take in line by line
		linechar = 0;
		while (temp[linechar] != '\n')
			linechar++;
		if (linechar == 0) //empty line found
			continue;
		Ppl++; //count up the number of players to have their statistics inputted
	}
	clearerr(OpenFile); //move back to the beginning to now start inputting tne data
	fseek(OpenFile, 0, SEEK_SET);
	
	head = (thePeople) malloc(sizeof(People)); //create one struct to begin with
	thePeople cursor = head;
	for (int in = 0; in < Ppl; in++) {
		if (in) {
			thePeople temp = (thePeople) malloc(sizeof(People));
			cursor->next = temp;
			cursor = temp;
		}
		
		linechar = 0;
		char t;
		cursor->firstName[0] = cursor->midInitial = cursor->lastName[0] = cursor->city[0] = cursor->country[0] = 0;
		cursor->age = 0;
		
		t = getc(OpenFile);
		while (!isalnum(t) && t != EOF && t != '-') //move forward until alphanumeric character seen
			t = getc(OpenFile);
		fseek(OpenFile, -1, SEEK_CUR);
		fscanf(OpenFile, "%19s", cursor->firstName);
		printf ("%s", cursor->firstName);
		
		t = getc(OpenFile);
		while (!isalnum(t) && t != EOF && t != '-') //move forward until alphanumeric character seen
			t = getc(OpenFile);
		fseek(OpenFile, -1, SEEK_CUR);
		fscanf(OpenFile, "%c", &cursor->midInitial);
		printf (" %c", cursor->midInitial);
		
		t = getc(OpenFile);
		while (!isalnum(t) && t != EOF && t != '-') //move forward until alphanumeric character seen
			t = getc(OpenFile);
		fseek(OpenFile, -1, SEEK_CUR);
		fscanf(OpenFile, "%19s", cursor->lastName);
		printf (" %s", cursor->lastName);
		
		t = getc(OpenFile);
		while (!isdigit(t) && t != EOF && t != '-')
			t = getc(OpenFile);
		if (t == '-')
			cursor->age = 0;
		else {
			for (int digits = 0; digits < 3; digits++) {
				cursor->age = 10*cursor->age + (t - 48);
				t = getc(OpenFile);
				if (!isdigit(t))
					break;
			}
		}
		
		t = getc(OpenFile);
		while (!isalnum(t) && t != EOF && t != '-') //move forward until alphanumeric character seen
			t = getc(OpenFile);
		fseek(OpenFile, -1, SEEK_CUR);
		fscanf(OpenFile, "%19s", cursor->city);
		printf (" %s", cursor->city);
		
		t = getc(OpenFile);
		while (!isalnum(t) && t != EOF && t != '-') //move forward until alphanumeric character seen
			t = getc(OpenFile);
		fseek(OpenFile, -1, SEEK_CUR);
		fscanf(OpenFile, "%19s", cursor->country);
		printf (" %s", cursor->country);
	}
	return 0;	
}

