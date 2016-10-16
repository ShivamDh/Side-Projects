#include <stdio.h>

int main() {
	char text[100];
	printf ("Please input a phrase: ");
	gets (text);
	
	int start;
	int finish;
	
	printf ("Input starting index of the phrase (first character = 1): ");
	scanf ("%i", &start);
	
	printf ("Input the finishing index of the phrase: ");
	scanf ("%i", &finish);
	
	if (start<0 || finish <1 || start>= finish)
		printf ("Sorry, invalid combination of start and end indices");
	
	printf ("The extracted word is: ");
	
	for (int i = start-1; i < finish; i++)
		printf ("%c", text[i]);
	
	return 0;
}