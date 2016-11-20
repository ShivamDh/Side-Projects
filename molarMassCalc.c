#include <stdio.h>
#include <stdlib.h>

int main (int argc,char* argv[]) {
	if(argc == 1) { //no command line argumnet for compound
		char compound1[25]; //reasonable to assume no compound over 25 letters will be used
		printf ("Please enter a compound who's molar mass you would like to calculate: ");
		int i = 0;
		compound1[i] = getchar();
		while (compound1[i] != '\0' && compound1[i] != '\n' && i < 25) {
			i++;
		}
		printf ("%c", compound1[0]);
	}
	
	return 0;
}