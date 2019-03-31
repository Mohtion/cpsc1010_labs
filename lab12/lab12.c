/*
* lab12.c
* Author: Mohan Foh
* Lecture, Lab Section: 003, 003
* Lab #: 12
* Submitted on: 11/29/18
*
* Purpose: This program takes in command line arguments for a certain range of numbers and determines whether any numbers in that range are perfect.
*
* Academic Honesty Declaration:
*The following code represents my own work and I have neither received
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
#include <string.h>

typedef struct {
	int lineNum;
	int numSum;
	char numStatus[10];
} numStruct;

int calculateDivisors (int currentNum) {
	int sum = 0;
	//for 1 to whatever the current number is -1
	for (int i = 1; i < currentNum ; i++) {
		//if the current number divided by loop number is an integer
		if ((double)currentNum / (double)i == currentNum / i && currentNum > 1) {
			//add loop number to overall sum
			sum = sum + i;
		}
	}
	//return sum of those factors
	return sum;
}

int main(int argc, char *argv[]) {
	if (argc == 1)  {
			printf ("Invalid input, proper form is:\n\n");
			printf ("./a.out low high {character}\n\n");
			printf ("Example: \"./a.out 15 19 '|'\"\n\nNote: low must be an integer higher than 1\nNote: high must be an integer equal to or higher than low\nTip: It helps to only put one character\n");
			printf("Please try again.\n");
			return 0;
		}
	//converts the first two arguments to ints.
	int low = atoi(argv[1]);
	int high = atoi(argv[2]);
	//if input is invalid
	if (low <= 1|| high < low || (double)low != low)  {
		printf ("Invalid input, proper form is:\n\n");
		printf ("./a.out low high {character}\n\n");
		printf ("Example: \"./a.out 15 19 '|'\"\n\nNote: low must be an integer higher than 1\nNote: high must be an integer equal to or higher than low\nTip: It helps to only put one character\n");
		printf("Please try again.\n");
		return 0;
	}
	//allocate memory for number of structs
	numStruct *numArray = (numStruct*)malloc(sizeof(numStruct) * (high - low + 1));
	//determine whether each number between low and high value(inclusive) are perfect numbers
	for (int i = low; i <= high; i++) {
		numArray[i - low].lineNum = i;
		//calculate sum of divisors
		numArray[i - low].numSum = calculateDivisors(numArray[i - low].lineNum);
		
		//if the sum of those factors is equal to the original number, then it's perfect
		if (numArray[i - low].numSum == numArray[i - low].lineNum) {
			strcpy(numArray[i - low].numStatus, "Perfect");
			//print that out
			printf("%4d is %s\t\t", numArray[i - low].lineNum, numArray[i - low].numStatus);
			//give sum
			for (int j = 0; j < numArray[i - low].numSum; j++) {
				//print out third argument for number of sum
				printf("%s", argv[3]);
			}
			printf("\n");
		}
		//else if deficient
		else if (numArray[i - low].numSum < numArray[i - low].lineNum) {
			strcpy(numArray[i - low].numStatus, "Deficient");
			//print that out
			printf("%4d is %s\t", numArray[i - low].lineNum, numArray[i - low].numStatus);
			//give sum
			for (int j = 0; j < numArray[i - low].numSum; j++) {
				//print out third argument for number of sum
				printf("%s", argv[3]);
			}
			printf("\n");
		}
		//else if abundant
		else {
			strcpy(numArray[i - low].numStatus, "Abundant");
			//print that out
			printf("%4d is %s\t", numArray[i - low].lineNum, numArray[i - low].numStatus);
			//give sum
			for (int j = 0; j < numArray[i - low].numSum; j++) {
				//print out third argument for number of sum
				printf("%s", argv[3]);
			}
			printf("\n");
		}
	}
}

