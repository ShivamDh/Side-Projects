#include <stdio.h>
#include <stdlib.h>

float M = 0;
float calcMM (char* substance, int length, int start);
int subscript (char* substance, int position);

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
		
		float theMM = calcMM(compound1, i, 0);
		if (theMM < 0)
			printf ("An error has occurred, please check the characters used for the formulae");
		else 
			printf ("\nThe molar mass is: %.3f", theMM);
	}
	
	return 0;
}

int subscript (char* substance, int position) { //new function used to find numeric subscripts
	int number1 = substance[position];
	if (number1 < 48 || number1 > 57)
		return -1;
	number1 -= 48;
	if (substance[position+1] > 47 && substance[position+1] < 58) {
		int number2 = substance[position+1];
		number2 -= 48;
		number1 *= 10;
		number1 += number2;
	}
	
	return number1;
}

float calcMM (char* substance, int length, int start) {
	
	int i = start;
	
	float bracketMM = 0; float tempMM = 0; int multiple;
	for (i; i < start+length; i++) {
		switch (substance[i]) {
			case '1':
			case '2':
			case '3':
			case '4':
			case '5': //cases for any subscript between 1 - 99 
			case '6':
			case '7':
			case '8':
			case '9':
				tempMM = M;
				if (substance[i-1] > 96 && substance[i-1] < 123) {
					calcMM (substance, 2, i-2);
				} else {
					calcMM (substance, 1, i-1);
				}
				tempMM = M - tempMM;
			
				multiple = subscript (substance, i); //find subscript after element name
				if (multiple < 1)
					return -1;
				M = M + (multiple-2)*tempMM;
				//2 less than subscript because function has gone through masses twice already
				break;
			case '(':
				bracketMM = M;
				break;
			case ')':
				bracketMM = M - bracketMM;
				if (substance[i+1] > 48 && substance[i+1] < 58) {
					i++;
					multiple = subscript(substance, i); //find the subscript after brackets
					if (multiple < 1)
						return -1;
					M = M + (multiple-1)*bracketMM; //1 less since function went through masses already
					break;
				} else
					return -1;
				break;
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
						case 't':
							M += 209; //astatine atom
							break;
						case 'u':
							M += 196.967; //gold atom
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
						case 'a':
							M += 137.327; //barium atom
							break;
						case 'e':
							M += 9.0122; //beryllium atom
							break;
						case 'i':
							M += 208.98; //bismuth atom
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
						case 'e':
							M += 140.116; //cerium atom
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
						case 's':
							M += 132.905; //cesium atom
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
			case 'D': 
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'y':
							M += 162.50; // dysprosium atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					return -1;
				}
				break;
			case 'E': 
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'u':
							M += 151.964; // europium atom
							break;
						case 'r':
							M += 167.259; // erbium atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					return -1;
				}
				break;
			case 'F': 
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'e':
							M += 55.845; //iron atom
							break;
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
			case 'G': 
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'a':
							M += 69.723; // gallium atom
							break;
						case 'd':
							M += 157.25; // gadolinium atom
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
						case 'f':
							M += 178.49; //hafnium atom
							break;
						case 'g':
							M += 200.59; // mercury atom
							break;
						case 'o':
							M += 164.93; //holium atom
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
						case 'n':
							M += 114.818; //indium atom
							break;
						case 'r':
							M += 192.217; //iridum atom
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
						case 'a':
							M += 138.906; //lanthanum atom
							break;
						case 'i':
							M += 6.941; //lithium atom
							break;
						case 'u':
							M += 174.967; //lutetium atom
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
						case 'd':
							M += 144.24; //neodymium atom
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
			case 'P': 
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'b':
							M += 207.2; //lead atom
							break;
						case 'd':
							M += 106.42; // palladium atom
							break;
						case 'm':
							M += 145; // promethium atom
							break;
						case 'o':
							M += 209; //polonium atom
							break;
						case 'r':
							M += 140.908; // praseodymium atom
							break;
						case 't':
							M += 195.078; //platinum atom
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
						case 'a':
							M += 226; //radium atom
							break;
						case 'b':
							M += 85.468; //rubidium atom
							break;
						case 'e':
							M += 186.207; //rhenium atom
							break;
						case 'n':
							M += 222; //radon atom
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
						case 'm':
							M += 150.36; // samarium atom
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
						case 'a':
							M += 180.948; // tantulum atom
							break;
						case 'b':
							M += 158.925; // terbium atom
							break;
						case 'c':
							M += 98; // technetium atom
							break;
						case 'e':
							M += 127.6; // tellurium atom
							break;
						case 'i':
							M += 47.867; // titanium atom
							break;
						case 'm':
							M += 168.934; // thulium atom
							break;
						case 'l':
							M += 204.383; //thallium atom
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
			case 'W': M += 183.84; //tungsten atom
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
			case 'Y': 
				if (substance[i+1] > 96 && substance[i+1] < 123) {
					i++;
					switch (substance[i]) {
						case 'b':
							M += 173.04; // ytterbium atom
							break;
						default:
							return -1;
							break;
					}
				} else {
					M += 88.906; // yttrium atom
				}
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
			default: 
				return -1;
				break;
		}
	}
	
	return M;
}