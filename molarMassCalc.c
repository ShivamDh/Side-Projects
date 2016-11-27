#include <stdio.h>
#include <stdlib.h>

float calcMM (char* substance, int length);

int main (int argc,char* argv[]) {
	if(argc == 1) { //no command line argumnet for compound
		char compound1[25]; //reasonable to assume no compound over 25 letters will be used
		printf ("Please enter a compound who's molar mass you would like to calculate: ");
		int i = 0;
		compound1[i] = getchar();
		while (compound1[i] != '\0' && compound1[i] != '\n' && i < 25) { //store variables until input ends
			if (!(compound1[i] == 40 || compound1[i] == 41 || (compound1[i] > 47 && compound1[i] < 58) || 
			(compound1[i] > 64 && compound1[i] < 91) || (compound1[i] > 96 && compound1[i] < 123))) {
				printf ("Incorrect characters used to represent a compound"); //checked for invalid characters
				return -1;
			}
			i++; //i = number of characters, last compound[i] stores '\n'
			compound1[i] = getchar(); //update for next while loop
		}
		printf ("%d", i);
		
		float theMM = calcMM(compound1, i);
		if (theMM < 0)
			printf ("An error has occurred, please check the characters used for the formulae");
		else 
			printf ("\nThe molar mass is: %.3f", theMM);
	}
	
	return 0;
}

float calcMM (char* substance, int length) {
	float M = 0;
	
	int i = 0;
	
	for (i; i < length; i++) {
		switch (substance[i]) {
			case 'A': M += 1;
				break;
			case 'B': 
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'e':
							M += 9.0122; //beryllium atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					M += 10.811; //boron atom
				}
				break;
			case 'C':
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'u':
							M += 63.546; //copper atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					M += 12.0101; //carbon atom
				}
				break;
			case 'D': M += 4;
			break;
			case 'E': M += 5;
			break;
			case 'F': 
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'r':
							M += 223; //francium atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					M += 18.998; // fluorine atom
				}
				break;
			case 'G': M += 7;
			break;
			case 'H':
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'e':
							M += 4.0026; //helium atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					M += 1.0079; // hydrogen atom
				}
				break;
			break;
			case 'I': M += 9;
			break;
			case 'J': M += 10;
			break;
			case 'K': M += 11;
			break;
			case 'L': 
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'i':
							M += 6.941;
							break;
						default:
							return -1;
							break;
					}
				}
				break;
			case 'M':
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'g':
							M += 24.305; //magnesium atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					return -1;
				}
				break;
			case 'N': 
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'a':
							M += 22.999;
							break;
						case 'i':
							M += 58.693; // nickel atom
							break;
						case 'e':
							M += 20.18;
							break;
						default:
							return -1;
							break;
					}
				} else {
					M += 14.007; // nitrogen atom
				}
				break;
			case 'O':
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 's':
							M += 190.23; // osmium atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					M += 16; // oxygen atom
				}
				break;
			case 'P': M += 16;
			break;
			case 'Q': M += 17;
			break;
			case 'R': M += 18;
			break;
			case 'S': M += 19;
			break;
			case 'T': M += 20;
			break;
			case 'U': M += 21;
			break;
			case 'V': M += 22;
			break;
			case 'W': M += 23;
			break;
			case 'X': M += 24;
			break;
			case 'Y': M += 25;
			break;
			case 'Z': M += 26;
			break;
			default: printf ("An error has occurred, start over");
			return -1;
			break;
		}
	}
	
	return M;
}