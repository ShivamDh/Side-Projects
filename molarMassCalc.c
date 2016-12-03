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
						case 'g':
							M += 107.868; //silver atom
							break;
						case 'l':
							M += 26.9815; //aluminium atom
							break;
						case 'r':
							M += 39.984; //argon atom
							break;
						case 's':
							M += 74.922; //arsenic atom
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
						case 'r':
							M += 79.904; //bromine atom
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
						case 'd':
							M += 112.411; //cadmium atom
							break;
						case 'o':
							M += 58.933; //cobalt atom
							break;
						case 'l':
							M += 35.453; //chlorine atom
							break;
						case 'r':
							M += 51.996; //chromium atom
							break;
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
			case 'G': 
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'a':
							M += 69.723; // gallium atom
							break;
						case 'e':
							M += 72.64; // germanium atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					return -1;
				}
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
			case 'I': 
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'r':
							M += 114.818; //indium atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					M += 126.905; //iodine atom
				}
			case 'J': M += 10;
			break;
			case 'K':
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'r':
							M += 83.978; //krypton atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					M += 39.098; //potassium atom
				}
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
				} else {
					return -1;
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
						case 'o':
							M += 95.94; //molybdenum atom
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
						case 'b':
							M += 92.906; //niobium atom
							break;
						case 'i':
							M += 58.693; // nickel atom
							break;
						case 'e':
							M += 20.18; //neon atom
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
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'd':
							M += 106.42; // palladium atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					M += 30.9738; // phosphorus atom
				}
				break;
			case 'Q': M += 17;
			break;
			case 'R': 
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'b':
							M += 85.468; //rubidium atom
							break;
						case 'u':
							M += 101.07; //ruthenium atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					return -1;
				}
				break;
			case 'S': 
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'b':
							M += 121.76; // antimony atom
							break;
						case 'c':
							M += 44.956; // scandium atom
							break;
						case 'e':
							M += 78.96; // selenium atom
							break;
						case 'i':
							M += 28.086; // silicon atom
							break;
						case 'n':
							M += 118.71; // tin atom
							break;
						case 'r':
							M += 87.62; // strontium atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					M += 32.065; // sulfur atom
				}
				break;
			case 'T':
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'c':
							M += 98; // technetium atom
							break;
						case 'e':
							M += 127.6; // tellurium atom
							break;
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
			case 'V': M += 50.942; // vanadium atom
			break;
			case 'W': M += 23;
			break;
			case 'X': 
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'a':
							M += 131.293; // xenon atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					return -1;
				}
				break;
			case 'Y': M += 88.906; // yttrium atom
			break;
			case 'Z':
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'n':
							M += 65.409; // zinc atom
							break;
						case 'r':
							M += 91.225; // zirconium atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					return -1;
				}
				break;
			default: printf ("An error has occurred, start over");
				return -1;
				break;
		}
	}
	
	return M;
}