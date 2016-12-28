#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Person {
	char firstName[20];
	char midInitial;
	char lastName[20];
	int age;
	char city[20];
	char country[20];
	struct Person* next; //the struct pointer for the next item in the list
}People, *thePeople;

int read(const char* iFile);

thePeople head; //struct pointer for the first struct, global scope to keep it accessible in all functions
int Ppl; //global scope integer for how many people exist within the linked list


int main() {
	printf("How would you like to enter the data?\n");
	printf("\t(1) Manually\n \t(2) Through a text file\n");
	
	int choice;
	scanf("%d", &choice);
	if (choice == 1) {
		int key = 65;
		puts ("Press Esc or Ctr+C to exit inputting information\n");
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
					for (int j = 0; j < maxL; j++) {
						key = getch();
						if (key == 27 || key == 3) //escape or CtrC pressed
							goto inputEnded;
						else if (key == 13) { //new line char seen
							input->firstName[j+1] = 0;
							break;
						}
						input->firstName[j] = key;
						printf ("%c", key);
					}
					break;
				case 1: 
					puts("\nEnter the middle initial: ");
					key = getch();
					if (key == 27 || key == 3)
						goto inputEnded;
					printf ("%c", key);
					input->midInitial = key;
					break;
				case 2:
					puts("\nEnter the last name: ");
					key = getch();
						printf ("%c", key);
					for (int k = 0; k < maxL; k++) {
						input->lastName[k] = key;
						key = getch();
						printf ("%c", key);
						if (key == 27 || key == 3) //escape or CtrC pressed
							goto inputEnded;
						else if (key == 13) { //new line char seen
							input->lastName[k+1] = 0;
							break;
						}
					}
					break;
				case 3:  {
					puts ("\nEnter their age: ");
					int numb = 0;
					key = getch();
					for (int l = 0; l < 3; l++) {
						if (!isdigit(key))
							goto inputEnded;
						printf ("%c", key);
						numb = numb*10 + (key-48);
						key = getch();
						if (key == 27 || key == 3) { //escape or CtrC pressed
							goto inputEnded;
							input->age = numb;
						} else if (key == 13) { //new line char seen
							break;
						}
					}
					input->age = numb;
					break; }
				case 4: 
					puts("\nEnter their city: ");
					key = getch();
					printf ("%c", key);
					for (int m = 0; m < maxL; m++) {
						input->city[m] = key;
						key = getch();
						printf ("%c", key);
						if (key == 27 || key == 3) //escape or CtrC pressed
							goto inputEnded;
						else if (key == 13) { //new line char seen
							input->city[m+1] = 0;
							break;
						}
					}
					break;
				case 5:
					puts("\nEnter their country: ");
					key = getch();
					printf ("%c", key);
					for (int n = 0; n < maxL; n++) {
						input->country[n] = key;
						key = getch();
						printf ("%c", key);
						if (key == 27 || key == 3) //escape or CtrC pressed
							goto inputEnded;
						else if (key == 13) { //new line char seen
							input->country[n+1] = 0;
							break;
						}
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
		inputEnded: ;
		thePeople toPrint = head;
		for (int a = 0; a < Ppl; a++) {
			printf ("%s %c %s %i %s %s", toPrint->firstName, toPrint->midInitial, toPrint->lastName, toPrint->age, toPrint->city, toPrint->country);
			toPrint = toPrint->next;
			if (toPrint == NULL)
				break;
		}
	} else if (choice == 2) {
		printf ("Enter the text file with extension (.txt)");
		char givenFile[50];
		scanf ("%s", givenFile);
		printf ("%s", givenFile);
		// read (givenFile);
		
	} else {
		printf ("Sorry wrong choice input entered");
		return -1;
	}
	
	
	
	return 0;
}


int read(const char* iFile) { //reading the file if provided
	
	
	
}
