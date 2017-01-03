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

void print ();
int read ();
int read(const char* iFile);
void swap (thePeople temporary1, thePeople temporary2);
int compare(char* str1, char* str2);
void sort (int selection);
void reverse ();
void writing();

thePeople head; //struct pointer for the first struct, global scope to keep it accessible in all functions
int Ppl = 0;; //global scope integer for how many people exist within the linked list

int main() {
	DataEntering: printf("How would you like to enter the data?\n");
	printf("\t(1) Manually\n \t(2) Through a text file\n");
	
	int choice;
	scanf("%i", &choice);
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
		if (read (givenFile)) {
			printf ("\nAn error occurred when reading the file\n");
			return -1;
		} else 
			printf ("\nData has been read:");
	} else {
		printf ("Sorry wrong choice entered, try again");
		goto DataEntering;
	}
	
	print();
	
	AskOrder: puts("\n\nDo you want to order this data according to a specific field(y/n): ");
	char order = 0;
	scanf (" %c", &order);
	
	if (order == 'y') {
		Ordering: puts("\nAccording to what field would like the data sorted:");
		puts("\n\t(1) First Name \n\t(2) Middle Initial \n\t(3) Last Name \n\t(4) Age \n\t(5) City \n\t(6) Country\n");
		int choice2;
		scanf ("%i", &choice2);
		sort(choice2);
	} else if (order == 'n') {
		printf ("\nData has been kept the same");
		goto nextStep;
	} else if (order == 'q') 
		return -1;
	else {
		puts ("\nWrong input entered, try again");
		goto AskOrder;
	}
	nextStep: print();
	
	AskReverse: puts("\n\nWould you like it sorted in the opposite matter (descending)(y/n): ") ;
	char opposite = 0;
	scanf (" %c", &opposite);
	
	if (opposite == 'y')
		reverse();
	else if (opposite == 'n') {
		printf ("\nData has been kept the same");
		goto lastStep;
	} else {
		puts ("\nWrong input has been entered, try again");
		goto AskReverse;
	}
	
	print();
	
	
	
	lastStep: puts ("\nWould you like this data transfered into a csv file?(y/n)");
	char choice3 = 0;
	scanf(" %c", &choice3);
	if (choice3 == 'y') {
		writing();
	} else if (choice3 == 'n')
		return 0;
	else {
		puts ("An incorrect choice was entered, try again");
		goto lastStep;
	}

	return 0;
}

void print () {
	thePeople toPrint = head;
	for (int reading = 0; reading < Ppl; reading++) {
		printf ("\nPerson %i: %s %c %s %i %s %s", reading+1, toPrint->firstName,\
		toPrint->midInitial, toPrint->lastName, toPrint->age, toPrint->city, toPrint->country);
		toPrint = toPrint->next;
		if (toPrint == NULL)
			break;
	}
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
					newPerson->next = NULL;
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
		while (temp[linechar] != '\n') {
			linechar++;
			if (isalnum(temp[linechar]))
				break;
		}
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
			temp->next = NULL;
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
		
		t = getc(OpenFile);
		while (!isalnum(t) && t != EOF && t != '-') //move forward until alphanumeric character seen
			t = getc(OpenFile);
		fseek(OpenFile, -1, SEEK_CUR);
		fscanf(OpenFile, "%c", &cursor->midInitial);
		
		t = getc(OpenFile);
		while (!isalnum(t) && t != EOF && t != '-') //move forward until alphanumeric character seen
			t = getc(OpenFile);
		fseek(OpenFile, -1, SEEK_CUR);
		fscanf(OpenFile, "%19s", cursor->lastName);
		
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
		
		t = getc(OpenFile);
		while (!isalnum(t) && t != EOF && t != '-') //move forward until alphanumeric character seen
			t = getc(OpenFile);
		fseek(OpenFile, -1, SEEK_CUR);
		fscanf(OpenFile, "%19s", cursor->country);
	}

	return 0;	
}

void swap (thePeople person1, thePeople person2) {
	if (person1 == head) { //swapping the head and the 2nd item in the list
		thePeople swap = head->next->next;
		head = head->next;
		head->next = person1;
		person1->next = swap;
	} else { //changing past the head
		thePeople swap = person1->next;
		person1->next = person1->next->next;
		swap->next = person1;
		person2->next = swap;
	}
}

int compare(char* str1, char* str2) {
		int i = 0;
		while (i < 19) { //max string length
			int r1 = str1[i]; //take in ASCII vaues of characters and put them into an integer
			int r2 = str2[i]; 
		
			if (r1 > 96 && r1 < 123) //see if the first integer represents a lowercase letter
				r1 -= 32; //turn it into a capital letter
			if (r2 > 96 && r2 < 123) //see if the second integer represents a lowercase letter
				r2 -= 32; //turn it into a capital letter
		
			if (r1 < r2) //compare the two integers
				return -1;
			if (r1 > r2)
				return 1;
		
			if (r1 == '\0' && r2 == '\0') //if both elements end at the same letter and were common for the rest of the characters, they are same names
				return 0;
			if (r1 == '\0') //if first one was equal and shorter, it should be ahead
				return -1;
			if (r2 == '\0') //if second one was equal and shorter, it should be ahead
				return 1;
			i++;
		}
	return 0;
}

void sort (int selection) {
	switch (selection){
		case 1: 
			for (int loops = 0; loops < Ppl-1; loops++) {
				for (int iter = 0; iter < Ppl-1-loops; iter++) {
					thePeople temporary1 = head;
					thePeople temporary2;
					for (int list = 0; list < iter; list++) {
						if (list == (iter - 1)) //remember the item before the current item in case of swap
							temporary2 = temporary1;
						temporary1 = temporary1->next;
					}
					if (compare(temporary1->firstName, temporary1->next->firstName) > 0)
						swap (temporary1, temporary2);
					else if (compare(temporary1->firstName, temporary1->next->firstName) == 0) {
						if (temporary1->midInitial > temporary1->next->midInitial)
							swap(temporary1, temporary2);
						else if (temporary1->midInitial == temporary1->next->midInitial) {
							if (compare(temporary1->lastName, temporary1->next->lastName) > 0)
								swap(temporary1, temporary2);
						}
					}
				}
			}
			break;
		case 2: 
			for (int loops = 0; loops < Ppl-1; loops++) {
				for (int iter = 0; iter < Ppl-1-loops; iter++) {
					thePeople temporary1 = head;
					thePeople temporary2;
					for (int list = 0; list < iter; list++) {
						if (list == (iter - 1)) //remember the item before the current item in case of swap
							temporary2 = temporary1;
						temporary1 = temporary1->next;
					}
					if (temporary1->midInitial > temporary1->next->midInitial)
						swap (temporary1, temporary2);
					else if (temporary1->midInitial == temporary1->next->midInitial) {
						if (compare(temporary1->firstName, temporary1->next->firstName) > 0)
							swap(temporary1, temporary2);
						else if (compare(temporary1->firstName, temporary1->next->firstName) == 0) {
							if (compare(temporary1->lastName, temporary1->next->lastName) > 0)
								swap(temporary1, temporary2);
						}
					}
				}
			}
			break;
		case 3: 
			for (int loops = 0; loops < Ppl-1; loops++) {
				for (int iter = 0; iter < Ppl-1-loops; iter++) {
					thePeople temporary1 = head;
					thePeople temporary2;
					for (int list = 0; list < iter; list++) {
						if (list == (iter - 1)) //remember the item before the current item in case of swap
							temporary2 = temporary1;
						temporary1 = temporary1->next;
					}
					if (compare(temporary1->lastName, temporary1->next->lastName) > 0)
						swap (temporary1, temporary2);
					else if (compare(temporary1->lastName, temporary1->next->lastName) == 0) {
						if (compare(temporary1->firstName, temporary1->next->firstName) > 0)
								swap(temporary1, temporary2);
						else if (compare(temporary1->firstName, temporary1->next->firstName) == 0) {
							if (temporary1->midInitial > temporary1->next->midInitial)
								swap(temporary1, temporary2);	
						}
					}
				}
			}
			break;
		case 4: 
			for (int sets = 0; sets < Ppl-1; sets++) {
				for (int reps = 0; reps < Ppl-1-sets; reps++){
					thePeople temporary1 = head;
					thePeople temporary2;
					for (int list = 0; list < reps; list++) {
						if (list == (reps - 1)) //remember the item before the current item in case of swap
							temporary2 = temporary1;
						temporary1 = temporary1->next;
					}
					if (temporary1->age > temporary1->next->age)
						swap(temporary1, temporary2);
				}
			}
			break;
		case 5: 
			for (int loops = 0; loops < Ppl-1; loops++) {
				for (int iter = 0; iter < Ppl-1-loops; iter++) {
					thePeople temporary1 = head;
					thePeople temporary2;
					for (int list = 0; list < iter; list++) {
						if (list == (iter - 1)) //remember the item before the current item in case of swap
							temporary2 = temporary1;
						temporary1 = temporary1->next;
					}
					if (compare(temporary1->city, temporary1->next->city) > 0)
						swap (temporary1, temporary2);
					else if (compare(temporary1->city, temporary1->next->city) == 0) {
						if (compare(temporary1->country, temporary1->next->country) > 0)
							swap(temporary1, temporary2);
					}
				}
			}
			break;
		case 6: 
			for (int loops = 0; loops < Ppl-1; loops++) {
				for (int iter = 0; iter < Ppl-1-loops; iter++) {
					thePeople temporary1 = head;
					thePeople temporary2;
					for (int list = 0; list < iter; list++) {
						if (list == (iter - 1)) //remember the item before the current item in case of swap
							temporary2 = temporary1;
						temporary1 = temporary1->next;
					}
					if (compare(temporary1->country, temporary1->next->country) > 0)
						swap (temporary1, temporary2);
					else if (compare(temporary1->country, temporary1->next->country) == 0) {
						if (compare(temporary1->city, temporary1->next->city) > 0)
							swap(temporary1, temporary2);
					}
				}
			}
			break;
		default:
			puts ("\nSorry wrong choice entered, try again\n");
			return;
	}
}

void reverse () {//copies over all the struct pointers into an array and then reverses the list order
	thePeople* copied;
	copied = (thePeople*) malloc(Ppl*sizeof(thePeople)); //create array of struct pointers on heap

	thePeople organize = head;
	int items = 0;
	
	while (organize != NULL) {
		copied[items] = organize;
		organize = organize->next;
		items++;
		if (items > Ppl) {
			printf ("\nAn error occured during the reverse function");
			return;
		}
	}
	
	head = copied[Ppl-1];//last item in the struct becomes head
	thePeople reverser = head; //new temp struct pointer used to traverse list and change order
	
	for (int a = 0; a < Ppl-1; a++) {
		reverser->next = copied[Ppl-2-a]; //start reversing order
		reverser = reverser->next;
	}
	reverser->next = NULL; //originally the head of the list, now the end of the list
}

void writing () {
	FILE* writeFile;
	writeFile = fopen("groupOrganizer.csv", "w");
	
	thePeople exporting = head;
	for (int writing = 0; writing < Ppl; writing++) {
		fprintf (writeFile, "Person %i: ,%s ,%c ,%s ,%i ,%s ,%s\n", writing+1, exporting->firstName,\
		exporting->midInitial, exporting->lastName, exporting->age, exporting->city, exporting->country);
		exporting = exporting->next;
		if (exporting == NULL)
			break;
	}
	
	fclose(writeFile);
}