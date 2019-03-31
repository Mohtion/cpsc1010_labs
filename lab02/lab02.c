/* Lab 2 - Instructions
Mohan Foh

9/4/18

CPSC 1010-003, CPSC 1011-003

This project allows a user to input any number of miles. The program will return the user's input in miles and kilometers.
*/


#include <stdio.h>

int main (void) {

	float kilometers;
	int miles;

	// Read input from the user
	printf("\n");
	printf("Please enter the distance in miles: ");
	scanf("%d", &miles);
	printf("\n");

	// Calculate distance in kilometers from miles
	kilometers = 1.60934 * miles;

	// Print the distances
	printf( "%d" , miles );
	printf(" mile(s) is equal to ");
	printf( "%.2f" , kilometers );
	printf( " kilometer(s)" );
	printf("\n\n");

	return 0;
}
