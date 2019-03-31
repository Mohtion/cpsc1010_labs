/*
* binaryconverter.c
* Author: Mohan Foh
* Lecture, Lab Section: 003, 003
* Lab #: 06
* Submitted on: 10/4/18
*
* Purpose: This program lets the user enter numbers to make a magic square that will be tested to be *actually magic or  *not.
*
* Academic Honesty Declaration:
* The following code represents my own work and I have neither received
*nor given assistance that violates the collaboration policy posted with
*this assignment. I have not copied or modified code from any other source
*other than the lab assignment, course textbook, or course lecture slides.
*Any unauthorized collaboration or use of materials not permitted will be
*subjected to academic integrity policies of Clemson University and CPSC
*1010/1011.
*
* I acknowledge that this lab assignment is based upon an assignment
*created by Clemson University and that any publishing or posting of this
*code is prohibited unless I receive written permission from Clemson
*University.
*/
#include <stdio.h>

int main (){
	float user_value;
	int integer;
	int binary_value;
	int binary_digits = 0;
	int max_digits;
	int print_digits;
	
	printf ( "Starting the CPSC 1011 Decimal to Binary Converter!\n\n" );
	while (!feof(stdin)) {
		printf ( "Please enter a positive whole number (or EOF to quit): " );
		scanf ( " %f" , &user_value );
		
		integer = user_value;
		if (feof(stdin)) {
			printf ( "\n\n\tThank you for using the CPSC 1011 Decimal to Binary Generator. Goodbye!\n\n" );
		}
		//if user user_value is not positive or an integer
		else if ( user_value <= 0 || user_value - integer != 0 ) {
			printf ( "\n\tSorry, that was not a positive whole number.\n\n" );
		}
		//if user_value is a positive integer
		else {
			integer = user_value;
			binary_digits = 0;
			//figuring out the number of binary digits
			while ( integer >  0 ) {
				integer /= 2;
				binary_digits++;
			}
			//array for finding binary digits
			int print_digits[ binary_digits ];
			//being cautious of overloading the array
			binary_digits--;
			max_digits = binary_digits;
			integer = user_value;
			printf ( "\n\t%d (base-10) is equivalent to " , integer );
			for ( binary_digits ; binary_digits >= 0 ; binary_digits-- ) {
				binary_value = integer % 2;
				integer /= 2;
				print_digits[ binary_digits ] = binary_value;
			} 
			//prints out each binary digit
			for ( binary_digits = 0 ; binary_digits <= max_digits ; binary_digits++ ) {
				printf ( "%d" , print_digits [ binary_digits ] );
			}
			printf ( " (base-2)!\n\n" );
		}
		
	}
}
