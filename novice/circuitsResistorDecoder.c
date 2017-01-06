#include <stdio.h>

int main() {
	char code1, code2, code3, code4;
	float first_digit, second_digit, multiplier, tolerance;
	
	printf ("Enter the four resistor color codes: ");
	scanf ("%c %c %c %c", &code1, &code2, &code3, &code4);
	
	switch (code1) {
		case 'k': first_digit = 0 ;
		break;
		case 'n': first_digit = 1 ;
		break;
		case 'R': first_digit = 2 ;
		break;
		case 'O': first_digit = 3 ;
		break;
		case 'Y': first_digit = 4 ;
		break;
		case 'G': first_digit = 5 ;
		break;
		case 'B': first_digit = 6 ;
		break;
		case 'V': first_digit = 7 ;
		break;
		case 'y': first_digit = 8 ;
		break;
		case 'W': first_digit = 9 ;
		break;
		default: printf ("Error: Invalid color code entered!");
		return -1;
		break;
	}
	
	switch (code2) {
		case 'k': second_digit = 0 ;
		break;
		case 'n': second_digit = 1 ;
		break;
		case 'R': second_digit = 2 ;
		break;
		case 'O': second_digit = 3 ;
		break;
		case 'Y': second_digit = 4 ;
		break;
		case 'G': second_digit = 5 ;
		break;
		case 'B': second_digit = 6 ;
		break;
		case 'V': second_digit = 7 ;
		break;
		case 'y': second_digit = 8 ;
		break;
		case 'W': second_digit = 9 ;
		break;
		default: printf("Error: Invalid color code entered!");
		return -1;
		break;
	}
	
	switch (code3) {
		case 'k': multiplier = 1 ;
		break;
		case 'n': multiplier = 10 ;
		break;
		case 'R': multiplier = 100 ;
		break;
		case 'O': multiplier = 1000 ;
		break;
		case 'Y': multiplier = 10000 ;
		break;
		case 'G': multiplier = 100000 ;
		break;
		case 'B': multiplier = 1000000 ;
		break;
		case 'V': multiplier = 10000000 ;
		break;
		case 'y': multiplier = 100000000 ;
		break;
		case 'W': multiplier = 1000000000 ;
		break;
		case 'd': multiplier = 0.1 ;
		break;
		case 'S': multiplier = 0.01 ;
		break;
		default: printf("Error: Invalid color code entered!");
		return -1;
		break;
	}
	
	switch (code4) {
		case 'n': tolerance = 0.01 ;
		break;
		case 'R': tolerance = 0.02 ;
		break;
		case 'G': tolerance = 0.005 ;
		break;
		case 'B': tolerance = 0.0025 ;
		break;
		case 'V': tolerance = 0.001 ;
		break;
		case 'y': tolerance = 0.0005 ;
		break;
		case 'd': tolerance = 0.05 ;
		break;
		case 'S': tolerance = 0.1 ;
		break;
		case 'N': tolerance = 0.2;
		break;
		default: printf("Error: Invalid color code entered!");
		return -1;
		break;
	}
	
	float ohms_resistance = ((10*first_digit)+second_digit)*multiplier;
	float ohms_tolerance = ohms_resistance*tolerance;
	
	printf ("The resistance of the resistor is %.0f ohms with +/- %.0f ohms tolerance", ohms_resistance, ohms_tolerance);
	
	return 0;
}
