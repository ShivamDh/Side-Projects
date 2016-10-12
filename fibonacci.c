#include <stdio.h>

int main () {
	int n, Fn;
	
	printf ("Please input an index for which a Fibonacci number will be calculated: ");
	scanf ("%i", &n);
	
	if (n<0)
		printf ("Sorry, the number you printed does not have a Fibonacci number associated with it");
	
	if (n==0) {
		Fn = 0;
	} else if (n==1) {
		Fn = 1;
	} else {
		int temp_variable = 1;
		int Fn_minus1 = 0, F_temp = 1;
		int F_new;
		
		while (temp_variable != n) {
			temp_variable++;
			F_new = F_temp + Fn_minus1;
			Fn_minus1 = F_temp;
			F_temp = F_new;
		}
		Fn = F_new;
	}
	
	printf ("The Fibonacci number for %i is %i", n, Fn);	
	
	return 0;
}