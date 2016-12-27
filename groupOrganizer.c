#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Person {
	char firstName[20];
	char midInitial;
	char lastName[20];
	int age;
	char city[20];
	char country[20];
	struct Person* next; //the struct pointer for the next item in the list
}People, *thePeople;

thePeople head; //struct pointer for the first struct, global scope to keep it accessible in all functions
int Ppl; //global scope integer for how many people exist within the linked list


int main() {
	printf("How would you like to enter the data?\n");
	printf("\t(1) Manually\n \t(2) Through a text file\n");
	
	int choice;
	scanf("%d", &choice);
	if (choice == 1) {
		int key;
		key = getch();
		puts ("Press Esc or Ctr+C to exit inputting information\n");
		int attain_info = 0;
		thePeople input = head;
		input = (thePeople) malloc(sizeof(People)); //create one struct to begin with

		int check = 0; //a checker to know that every time a new person is made, new memory is used
		int maxL = 19; //the max length of any of the strings
		while (key != 27 && key != 3) {
			attain_info = attain_info % 6; //asking for the right information in the right order
			switch (attain_info) {
				case 0: 
					if(check){
						Ppl++;
						thePeople newPerson = (thePeople) malloc(sizeof(People));
						input->next = newPerson;
						input = newPerson;
						free(newPerson);
					}
					printf("Person %d\n", Ppl+1);
					puts ("Enter the first name: ");
					scanf ("%s", input->firstName);
					break;
				case 1: 
					puts("\nEnter the middle initial: ");
					key = getch();
					if (key == 27 || key == 3)
						
					scanf (" %c", &input->midInitial);
					break;
				case 2:
					puts("\nEnter the last name: ");
					scanf ("%s", input->lastName);
					break;
				case 3: 
					puts ("\nEnter their age: ");
					scanf ("%i", &input->age);
					break;
				case 4: 
					puts("\nEnter their city: ");
					scanf ("%c", input->city);
					break;
				case 5:
					puts("\nEnter their country: ");
					scanf ("%s", input->country);
					check = 1;
					break;
				default:
					printf ("\nAn error occurred during importing data");
					return -1;
					break;
			}
			attain_info++;
		}
		inputEnded: thePeople toPrint = head;
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