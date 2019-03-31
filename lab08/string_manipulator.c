/*
* string_manipulator.c
* Author: Mohan Foh
* Lecture, Lab Section: 003, 003
* Lab #: 08
* Submitted on: 10/19/18
*
* Purpose: This program lets the user enter a string and then replace all instances of a character in the string with another character.
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
*
*I had assistance from TA Xiang Li for eliminating the newline
*from the final scanf statement
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removeNewline(char functionString[]);
void makeLowercase ( char functionString[]);
int checkStringChar (char origString[], char oldChar );
int checkCommand (char functionString[]);
void outputNewString (char userString[], char oldChar, char newChar);

int main() {
	//Prompt the user to enter a string (up to 25 characters to be transformed
	char userString[26];
	char commandString[12];
	char oldChar;
	char newChar;
	printf ("Enter a string (up to 25 characters) to be transformed: " );
	fgets(userString, 25, stdin);
	//While "quit" is not the command
	while (strcmp(commandString, "quit") != 0){
		//Ask the user to enter a command (quit or replace all)
		printf ("Enter your command (quit, replace all): ");
		fgets(commandString, 12, stdin);
		//*function*Removes newline character from string
		removeNewline(commandString);
		//*function: boolean*Return true if command string is "quit or "replace all"
		int validCommand = checkCommand (commandString);
		//If the user command is "replace all"
		if (validCommand == 1) {
			//Ask which character the user wants to replace
			printf("Enter the character to replace: ");
			scanf(" %c%*c" , &oldChar);
			//*function*Checks if character to be replaced is in string
			int validChar = checkStringChar (userString, oldChar);
			//if user character is in string
			if (validChar == 1) {
				//Ask what will be put in the replaced character's place
				printf("Enter the new character: ");
				scanf(" %c%*c", &newChar);
				//*function*Replace characters with the user string, output new string
				outputNewString(userString, oldChar, newChar);
			}
		}
	}
}
//*functon: void*Takes out newline character from command string
void removeNewline(char functionString[]){
	//take out newline using String length
	if (functionString[strlen(functionString) - 1] == '\n') {
      		functionString[strlen(functionString) - 1] = '\0';
   	}
	
}
//*function: void*Makes the whole command string lowercase
void makeLowercase ( char functionString[]){
	//takes in: command string
	//outputs: nothing
	//for the string until null character is reached
	for (int i = 0; i <= strlen(functionString); i++) { 
		//check whether character is lowercase
		//if not lowercase character
		if (isupper(functionString[i])) {
			//make lowercase
			functionString[i] = tolower(functionString[i]);
		}
	}
}
//*function: int* Checks whether character to be replaced is in string
int checkStringChar (char origString[], char oldChar ) {
	for (int i = 0; i <= strlen(origString); i++) {
		if (oldChar == origString[i]) {
			return 1;
		}
		//If the character is not in the string
		else if (i == strlen(origString)) {
			//Prompt an error message to the user
			printf("Error, %c is not in the string.\n\n" , oldChar);
			return 0;
		}
	}
	return 0;
}	
//*function: int* Returns true if command string is "quit or "replace all"
int checkCommand (char functionString[]){
	//*function*Make the whole command string lowercase
	makeLowercase(functionString);
	//If string is "quit" or "replace all"
	if (strcmp(functionString, "replace all") == 0) {
		//return true
		return 1;
	}
	//if string is "quit
	else if (strcmp(functionString, "quit") == 0) {
		return 0;
	}
	//If string is not "quit" or "replace all"
	else if (strcmp(functionString, "quit") != 0 && strcmp(functionString, "replace all") != 0) {
		printf("Sorry, that command is invalid. Please type one of the options.\n\n");
		//return false
		return 0;
	}
	return 0;
}
//*function: void* Replaces the characters with the user input one and outputs new string
void outputNewString (char userString[], char oldChar, char newChar) {
	//for the entire length of the string
	for (int i = 0; i < strlen(userString) ; i++)
		//if the chracter is to be replaced
		if (oldChar == userString[i]) {
			userString[i] = newChar;//replace with the user input character
		}
	//Output the new sentence with the replaced characters
	printf("Your new sentence is: %s\n" , userString);
}
