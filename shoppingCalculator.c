#include <stdio.h>
#include <stdlib.h>

int main () {
	float *original_price, total_items_price;
	int item_number, discount_percent, tax_rate;
	
	printf("How many items did you buy: ");
	scanf ("%d", &item_number);
	
	original_price = (float *) malloc(item_number*sizeof(int));
	// Used the heap to reserve space based on user input of how many variables created
	
	printf ("Enter 0 to finish shopping \n");
	
	for (int i = 1; i<=item_number; i++) {
		printf ("Enter the original price of the item number %d: ", i);
		scanf ("%f", &original_price[i]);
		if (original_price[i] == 0)
			break;
		total_items_price += original_price[i];
	}
	// Asked user for input regarding price value and then added it to variable for total price
	
	printf ("Enter the discount rate (%%): ");
	scanf ("%i", &discount_percent);
	
	printf ("Enter the tax rate to be applied (%%): ");
	scanf ("%i", &tax_rate);
	
	total_items_price  *= 1-(((float)discount_percent)/100);
	total_items_price  *= 1+(((float)tax_rate)/100);
	//Applied simple arithemetic steps to calculate total price of the shopping trip
		
	printf ("The final price of the item is: $ %.2f", total_items_price);
	
	return 0;
	
}