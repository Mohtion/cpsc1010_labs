/*
* rockpaperscissors.c
* Author: Mohan Foh
* Lecture, Lab Section: 003, 003
* Lab #: 05
* Submitted on: 9/27/18
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
#include <stdlib.h>
#include <time.h>

int main () {
	int user_matches;
	int game_count = 0;
	char user_character;
	int user_choice;
	int computer_choice;
	int game_outcome;
	int user_score = 0;
	int computer_score = 0;
	int ties = 0;
	//creates random number that modulus operator will be used on
	srand ( (int)time(0) );
	
	printf ( "Starting the CPSC 1011 Rock, Paper, Scissors Game!\n\n" );
	printf ( "Enter the number of matches to play: " );
	scanf ( " %d" , &user_matches );
	while ( game_count < user_matches) {
		game_count++;
		printf ( "\n\tMatch %d: Enter R for rock, P for paper, or S for scissors: " , game_count);
		scanf ( " %c" , &user_character );
		//The block below is computations
		switch ( user_character ) {
			case 'R':
				user_choice = 0;
				break;
			case 'P':
				user_choice = 1;
				break;
			case 'S':
				user_choice = 2;
				break;
			default:
				printf ( "\tYou entered an invalid character. Try again.\n\n" );
				game_count -= 1;
				
		}
		//if user enters a valid value
		if ( user_character == 'R' || user_character == 'P' || user_character == 'S' ) { 
			//computer choice can be 0, 1, or 2
			//0 = rock, 1 = paper, 2 = scissors
			computer_choice = rand () % 3 ;	
							
			game_outcome = user_choice - computer_choice ;
			/* 
				game_outcome value meaning
				0 	= tie
				-1 	= loss
				2	= loss
				-2	= win
				1	= win
			*/
			//The block above is computations
			printf ( "\tThe computer chose " );
			//outputs what computer chose depending on random number
			switch ( computer_choice ) { 
				case 0:
					printf ( "rock. " );
					break;
				case 1:
					printf ( "paper. " );
					break;
				case 2:
					printf ( "scissors. " );
					break;
			}
			//game outcomes
			if ( game_outcome == 0 ) {
				printf ( "You tied.\n" );
				ties++;
			}
			else if ( game_outcome == -1 || game_outcome == 2 ) {
				printf ( "You lose.\n" );
				computer_score++;
			}
			//The only other possible values are 1 and -2, resulting in wins
			else {
				printf ( "You win!\n" );
				user_score++;
			}
			//gives user the score
			printf ( "\tScores:  You-%d  Computer-%d  Ties-%d\n" , user_score , computer_score , ties );
		}
	
	}
	
	printf ( "\nThe game of %d matches is complete. The final scores are:\n" , user_matches );
	printf ( "You:\t\t%d \nComputer:\t%d \nTies:\t\t%d\n" , user_score , computer_score , ties );
}
