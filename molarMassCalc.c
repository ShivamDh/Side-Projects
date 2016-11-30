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
			case 'A': 
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'l':
							M += 26.9815; //aluminium atom
							break;
						case 'r':
							M += 39.984; //argon atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					return -1;
				}
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
						case 'a':
							M += 40.078; //calcium atom
							break;
						case 'l':
							M += 35.453; //chlorine atom
							break;
						case 'o':
							M += 58.933; //cobalt atom
							break;
						case 'r':
							M += 51.996; //chromium atom
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
						case 'e':
							M += 55.845; //iron atom
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
			case 'K': M += 39.098; //potassium
			break;
			case 'L': 
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'i':
							M += 6.941; //lithium atom
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
						case 'n':
							M += 54.938; //manganese atom
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
							M += 22.999; //sodium atom
							break;
						case 'e':
							M += 20.18; //neon atom
							break;
						case 'i':
							M += 58.693; // nickel atom
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
				M += 16; // oxygen atom
				break;
			case 'P': 
				M += 30.9738; // phosphorus atom
				break;
			case 'Q': M += 17;
			break;
			case 'R': M += 18;
			break;
			case 'S': 
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'c':
							M += 44.956; // scandium atom
							break;
						case 'i':
							M += 28.086; // silicon atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					M += 32.065; // sulfur atom
				}
				break;
			case 'T' 
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'i':
							M += 47.867; // titanium atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					return -1;
				}
				break;
			case 'U': M += 21;
			break;
			case 'V': M += 50.492; //vanadium atom
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