/*
* sorting_algorithms.c
* Author: Mohan Foh
* Lecture, Lab Section: 003, 003
* Lab #: 11
* Submitted on: 11/16/18
*
* Purpose: This program sorts 4 different input files with selection, insertion, bubble, and quicksort.
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
#include <time.h>
#include <stdlib.h>
#include <string.h>

void selectionSort (int in, int numberArray[]);
void insertionSort (int in, int numberArray[]);
void bubbleSort (int in, int numberArray[]);
void quickSort (int low, int high, int numberArray[]);
void writeArrayToFile(int array[], int num, char string[]);

int main () {
	FILE *fPTR;
  float fileChoice = 0;
  int numItems = 0;
  int maxIndex = 0;
  int *numArray;
  char fileName[30];
  char fileSize[10];
  
  //prompt user for the data file they would like to sort. (checks for valid file choice by user)
  while (!(fileChoice == 1 || fileChoice == 2 || fileChoice == 3 || fileChoice == 4)){
		printf ("Welcome to the CPSC 1011 sorting simulator.\n");
		printf ("Which data file would you like to sort?\n");
		printf ("  [1] Small file (10 items)\n");
		printf ("  [2] Medium file (100 items)\n");
		printf ("  [3] Large file (1,000 items)\n");
		printf ("  [4] Jumbo file (10,000 items)\n\n");
  	printf ("Enter your choice:  ");
  	scanf ("%f", &fileChoice);
  	if (!(fileChoice == 1 || fileChoice == 2 || fileChoice == 3 || fileChoice == 4)) {
  		printf ("Please enter an integer, 1-4. Try again.\n");
  	}
  }
  //sets values for respective file choices
  if (fileChoice == 1) {
  	numArray = (int*)malloc(10 * 4);
  	maxIndex = 9;
  	numItems = 10;
  	fPTR = fopen("random.small.input", "r");
  	strcpy(fileSize, "small");
  	//fread (numArray, 4, 10, fPTR);
  }
  else if (fileChoice == 2) {
  	numArray = (int*)malloc(100 * 4);
  	maxIndex = 99;
  	numItems = 100;
  	fPTR = fopen("random.medium.input", "r");
  	strcpy(fileSize, "medium");
  	//fread (numArray, 4, 100, fPTR);
  }
  else if (fileChoice == 3) {
  	numArray = (int*)malloc(1000 * 4);
  	maxIndex = 999;
  	numItems = 1000;
  	fPTR = fopen("random.large.input", "r");
  	strcpy(fileSize, "large");
  	//fread (numArray, 4, 1000, fPTR);
  }
 	else {
  	numArray = (int*)malloc(10000 * 4);
  	maxIndex = 9999;
  	numItems = 10000;
  	fPTR = fopen("random.jumbo.input", "r");
  	strcpy(fileSize, "jumbo");
  	//fread (numArray, 4, 10000, fPTR);
  }
  
  for (int i = 0; i < numItems; i++) {
  	fscanf(fPTR, "%d, ", &numArray[i]);
  }
  clock_t time1 = clock();
  selectionSort (numItems, numArray);
  clock_t time2 = clock();
  double selectionTime = (double)(time2 - time1) / CLOCKS_PER_SEC * 1000;
  rewind(fPTR);  
  time1 = clock();
  insertionSort (numItems, numArray);
  time2 = clock();
  double insertionTime = (double)(time2 - time1) / CLOCKS_PER_SEC * 1000;
  rewind(fPTR);
  
  time1 = clock();
  bubbleSort (numItems, numArray);
  time2 = clock();
  double bubbleTime = (double)(time2 - time1) / CLOCKS_PER_SEC * 1000;
  rewind(fPTR);
  
  time1 = clock();
  quickSort (0, maxIndex, numArray);
  time2 = clock();
 	double quickTime = (double)(time2 - time1) / CLOCKS_PER_SEC * 1000;
  
  //prints out sorts with times
  printf("Sorting with selection sort...done after %.0lfms.\n", selectionTime);
  sprintf(fileName, "sorted.selection.%s.output", fileSize);
  writeArrayToFile(numArray, numItems, fileName);
  printf("Sorting with insertion sort...done after %.0lfms.\n", insertionTime);
  sprintf(fileName, "sorted.insertion.%s.output", fileSize);
  writeArrayToFile(numArray, numItems, fileName);
  printf("Sorting with bubble sort...done (after %.0lfms.) \n", bubbleTime);
  sprintf(fileName, "sorted.bubble.%s.output", fileSize);
  writeArrayToFile(numArray, numItems, fileName);
  printf("Sorting with quick sort...done (after %.0lfms.) \n", quickTime);
  sprintf(fileName, "sorted.quick.%s.output", fileSize);
  writeArrayToFile(numArray, numItems, fileName);
}

//function: sorts array of numbers with a selecton sort
//takes in: the number of elements in the array and array itself
//returns: the time it took to finish the function (in ms)
void selectionSort (int in, int numberArray[]) {
  int i = 0; int j = 0; int temp = 0;
  int index_smallest = 0;
  //ends when i reaches the end of the list
  for (i = 0; i < in; i++){
    index_smallest = i;
    //goes through entire array and moves smallest value to proper position
    for (j = i + 1; j < in; j++){
      if (numberArray[j] < numberArray[index_smallest])
				index_smallest = j;
    }
    //sets index is i as the smallest index
    temp = numberArray[i];
    numberArray[i] = numberArray[index_smallest];
    numberArray[index_smallest] = temp;
  }
}

//function: sorts array of numbers with an insertion sort
//takes in: the number of elements in the array and array itself
//returns: the time it took to finish the function (in ms)
void insertionSort (int in, int numberArray[]) {
  int temp = 0; int i = 0; int j = 0;
  //sets next value as temp, then moves it into the right place until
  //all data values are checked
  for (i = 1; i < in; i++){
    temp = numberArray[i];
    j = i - 1;
    //pushes values larger than index j up
    while (temp < numberArray[j] && j >= 0){
      numberArray[j+1] = numberArray[j];
      j--;
    }
    //puts temporary value in proper position
    numberArray[j+1] = temp;
  }
}

//function: sorts array of numbers with a bubble sort
//takes in: the number of elements in the array and array itself
//returns: the time it took to finish the function (in ms)
void bubbleSort (int in, int numberArray[]) {
  int i = 0; /*int j = 0; int num = 0;*/ int temp = 0;
  //loops for number of items in the array
  for (i = 0; i < in; i++){
  	//goes through the entire array until the second to last one,
  	//because "j + 1" takes care of that value
    for (int j = 0; j < (in - i - 1); j++){
    	//swaps adjeacent values that are in the wrong position
    	//relative to one another
      if (numberArray[j] > numberArray[j+1]){
				temp = numberArray[j];
				numberArray[j] = numberArray[j+1];
				numberArray[j+1] = temp;
      }
    }
  }
}

//function: sorts array of numbers with a quick sort
//takes in: the smallest and highest position in the array and array itself
//returns: the time it took to finish the function (in ms)
void quickSort (int low, int high, int numberArray[]) {
  int pivot = 0;
  int i = 0;
  int j = 0;
  int temp = 0;
  //if the location of the first number is less than the location of the last
  if (low < high){
    pivot = low;
    i = low;
    j = high;
    //done when i and j are equal and values are divided around pivot
    while (i < j){
      //done when number found lower in position than pivot, but not
      //supposed to be
      while (numberArray[i] <= numberArray[pivot] && i <= high){
				i++;
      }
      //done when number found higher in position than pivot, but not
      //supposed to be
      while (numberArray[j] > numberArray[pivot] && j >=low){
				j--;
      }
      //if wrong lower number position is less than wrong higher number
      //position
      if (i < j) {
				//swaps two numbers
				temp = numberArray[i];
				numberArray[i] = numberArray[j];
				numberArray[j] = temp;
      }
    }
    //swapping the number j and the pivot  
    temp = numberArray[j];
    numberArray[j] = numberArray[pivot];
    numberArray[pivot] = temp;
    //does quicksort on lower values and higher values recursively
    quickSort(low, j-1, numberArray);
    quickSort(j+1, high, numberArray);
  }
}

//function: writes array to "rand" file
//takes in: a number array and number of elements in array
//returns: nothing
void writeArrayToFile(int array[], int num, char string[]) {
	FILE * pFile;
	pFile = fopen(string , "w+");
	if (pFile == NULL) perror ("Error opening file");
	else {
		int i;
		for(i = 0; i < num; i++) {
			fprintf(pFile, "%d, ", array[i]);
		}
		fclose (pFile);
	}
	return;
}
