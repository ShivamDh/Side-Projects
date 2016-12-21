#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void wordCount (char* fileIn, char* fileOut, int argNum, char** argStr);

int main (int argc, char** argv) { //meant to take in the input file through command line argument
	if (argc < 2) { //Ensure at least 2 commmand line arguments
		printf ("Did not enter the filename\n");
		return -1;
	}
	
	int count = 0;
	while (argv[1][count] != '\0') //this will  find the length of input file
		count++;
	
	printf ("%s   %d", argv[1], count);
	
	char in2[count+1];
	int g = 0;
	for (g; g < count; g++) {
		in2[g] = argv[1][g]; //transfer file name into a char array easier to work with on its own
	}
	in2[g] = 0; //end string
	
	int count2 = 0;
	while (argv[1][count2] != '.' && count2 < count)
		count2++; //used to check if file extension has been added, usually with a dot
	
	bool endingcheck = false;
	
	printf ("%s", in2);
	
	if (count2 == count) { //if total length of file equalled length till a dot was reached, meant no file extension seen
		char in1[count+4]; //new array where file extension will be added to input file
		for (int n = 0; n < count; n++) 
			in1[n] = in2[n]; 
		
		in1[count] = '.'; //add file extension 
		in1[count+1] = 't';
		in1[count+2] = 'x';
		in1[count+3] = 't';
		in1[count+4] = '\0';
		
		char out1[count+5]; //create an array to store output file name with extension
		int alp = 0;
		for (alp; alp < count; alp++) 
			out1[alp] = argv[1][alp];
		
		out1[alp] = '.'; //add extension .anl for analyzed file
		out1[alp+1] = 'a';
		out1[alp+2] = 'n';
		out1[alp+3] = 'l';
		out1[alp+4] = '\0';
		
		wordCount (in1, out1, argc, argv); //call function for analysis now that correct in and out files have been created
	} else { //if a dot was found on command line argument (maeaning a file extension exists)
		if (argv[1][count2] != '.') // check for .txt extension
			endingcheck = true;
		if (argv[1][count2+1] != 't')
			endingcheck = true;
		if (argv[1][count2+2] != 'x')
			endingcheck = true;
		if (argv[1][count2+3] != 't')
			endingcheck = true;
		if (endingcheck) { //if file extension wasn't .txt
			printf ("Invalid file extension was provided");
			return -1;
		}
		
		char out2[count+1]; //create out file
		int jk = 0;
		for (jk; jk < count-4; jk++) {
			out2[jk] = in2[jk]; //copy only the file name, not extension
		}
		
		out2[jk] = '.'; //add the .anl file extension
		out2[jk+1] = 'a';
		out2[jk+2] = 'n';
		out2[jk+3] = 'l';
		out2[jk+4] = '\0';
		
		wordCount (in2, out2, argc, argv); //call fulction for the analysis of the file
	}
	
	return 0;
	
}

void wordCount (char* fileIn, char* fileOut, int argNum, char** argStr) {
	
}