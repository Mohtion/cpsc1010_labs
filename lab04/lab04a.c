/*
* lab04a.c
* Author: Mohan Foh
* Lecture, Lab Section: 003, 003
* Lab #: 04
* Submitted on: 9/20/19
*
* Purpose: This program lets the user enter numbers to make a magic square that will be tested to be * actually magic or  *not.
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

int main () {
	//user values
	int one;
	int two;
	int three;
	int four;
	int five;
	int six;
	int seven;
	int eight;
	int nine;
	int big_value;
	//square sums
	int row1;
	int row2;
	int row3;
	int column1;
	int column2;
	int column3;
	int diagonal_se; //diagonal southwest
	int diagonal_sw; //diagonal southeast
	//error count
	int error_count = 0;
	
	printf ( "Enter in the values: " );
	scanf ( "%d %d %d %d %d %d %d %d %d" , &one , &two , &three , &four , &five , &six , &seven , &eight , &nine );
	//The following comments are failed attempts at this program
	//printf ( "%d %d %d %d %d %d %d %d %d" , one , two , three , four , five , six , seven , eight , nine );
	//scanf ( "%d" , &big_value ); Trying a big value and then dividing by smaller and smaller numbers
	//printf ( "%d" , big_value );
	//this block of code inputs the 9 values
	/*scanf ( "%d" , &one ) ;
	printf ( "\b ");
	scanf ( "%d" , &two ) ;
	printf ( "\b ");
	scanf ( "%d" , &three ) ;
	printf ( "\b ");
	scanf ( "%d" , &four ) ;
	printf ( "\b ");
	scanf ( "%d" , &five ) ;
	printf ( "\b ");
	scanf ( "%d" , &six ) ;
	printf ( "\b ");
	scanf ( "%d" , &seven ) ;
	printf ( "\b ");
	scanf ( "%d" , &eight ) ;
	printf ( "\b ");
	scanf ( "%d" , &nine ) ;
	//the above block of code inputs the 9 values */ //This was also a failed attempt
	
	printf ( "\nYou Entered:\n%d %d %d\n%d %d %d\n%d %d %d\n\n" , one, two, three, four, five, six, seven, eight, nine ); //outputs square
	printf ( "Analyzing...\n\n" );
	//Following code checks if all rows, columns and diagonals equal 15
	row1 = one + two + three;
	if ( row1 != 15 ) {
		printf ( "[%d, %d, %d] does not work!\n" , one , two , three );
		error_count++;
	}
	row2 = four + five + six;
	if ( row2 != 15 ) {
		printf ( "[%d, %d, %d] does not work!\n" , four , five , six );
		error_count++;
	}
	row3 = seven + eight + nine;
	if ( row3 != 15 ) {
		printf ( "[%d, %d, %d] does not work!\n" , seven , eight , nine );
		error_count++;
	}
	
	column1 = one + four + seven;
	if ( column1 != 15 ) {
		printf ( "column 1 does not work!\n" );
		error_count++;
	}
	column2 = two + five + eight;
	if ( column2 != 15 ) {
		printf ( "column 2 does not work!\n" );
		error_count++;
	}
	column3 = three + six + nine;
	if ( column3 != 15 ) {
		printf ( "column 3 does not work!\n" );
		error_count++;
	}
	
	diagonal_se = one + five + nine;
	if ( diagonal_se != 15 ) {
		printf ( "Diagonal [%d, %d, %d] does not work!\n" , one , five , nine );
		error_count++;
	}
	diagonal_sw = three + five + seven;
	if ( diagonal_sw != 15 ) {
		printf ( "Diagonal [%d, %d, %d] does not work!\n" , three , five , seven );
		error_count++;
	}
	
	if ( error_count > 0 ){
		printf ( "This is not a magic square!\n\n" );
	}
	
	else if ( error_count == 0 ) {
		printf( "This is a magic square!\n\n" );
	}
}
