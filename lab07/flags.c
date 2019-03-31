/*
* flags.c
* Author: Mohan Foh
* Lecture, Lab Section: 003, 003
* Lab #: 07
* Submitted on: 10/11/18
*
* Purpose: This program prints out the flags of Poland, the Netherlands, and Italy.
* The flag is then printed out in a ppm file according to the width that the user entered.
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

int calculate_height ( double hoist, double fly, double width );
void make_pixel (int r, int g, int b);
void make_ppm_header (int width, int height);
void make_ppm_image (int country_code, int width);

int main()
{
	double width = 0, country_code = 0;
	int floored_width = 1;
	//loops if country code is invalid
	while (!(country_code == 1 || country_code == 2 || country_code == 3)) {
		/*
		prompt user to enter country_code of chosen flag
		this should look really similar to the line down below
		*/
		fprintf ( stderr, "What country's flag do you want to create? " );
		fscanf(stdin, "%lf", &country_code);
		if (!(country_code == 1 || country_code == 2 || country_code == 3)) {
			fprintf ( stderr, "The code has to be a 1, 2, or 3. Please try again.\n\n" ) ;
		}	
	}
	//loops if width is invalid (not a positive integer)
	while (width <= 0 || floored_width - width != 0) {
		fprintf(stderr, "What width (in pixels) do you want it to be? ");
		fscanf(stdin, "%lf", &width);
		floored_width = width;
		if (width <= 0 || floored_width - width != 0) {
			fprintf ( stderr, "The width has to be a positive integer. Please try again.\n\n" ) ;
		}
	}
	fprintf(stderr, "\nMaking country %.0lf's flag with width %.0lf pixels...\n", country_code, width);
	// Write the image data
	make_ppm_image(country_code, width);
	fprintf(stderr, "Done!\n\n" );
	return(0);
}
//Calculates the height with proper rounding. The hoist is the height and fly is the width.
//Hoist to fly ratio depends on flag
int calculate_height ( double hoist, double fly, double width ) {
	double calculated_height = width * hoist / fly ;
	int floored_height = calculated_height;
	if (calculated_height - floored_height < .5) {
		return floored_height;
	}
	else if (calculated_height - floored_height >= .5) {
		return floored_height + 1;
	}
}
// Creates a pixel with the colors you tell it to use when you call it
// To call it, just do something like make_pixel(244, 244, 244);
void make_pixel (int r, int g, int b){
	fprintf(stdout, "%c%c%c", r, g, b);
}
// Creates a header with the desired width and height when you call it
void make_ppm_header (int width, int height){
	fprintf(stdout, "P6\n");
	fprintf(stdout, "%d %d %d\n", width, height, 255);
}
// Creates a complete ppm image when you call it
void make_ppm_image (int country_code, int width){
	/*
	todo
	Write your logic to print out the pixel data here for each flag
	First, make an if-else or switch depending on the country
	Second, use nested for loops to iterate through
	Then, determine which flag you are creating
	Then, use modulus to find where you are
	Next, use make_pixel() to write the pixel
	- you can use this like you would any other function.
	- just pass in the values you want for r, g, and b
	*/
	int height = 0;
	//make Poland flag
	switch (country_code) {
		case 1: 
			//calculate height
			height = calculate_height ( 5 , 8 , width );
			//Make header file using height and width
			make_ppm_header(width, height);
	    		//Make the top half of the flag white
			for ( int row = 0 ; row < height / 2 ; row++ ) {
				//Make pixels white until end of line is reached
				for ( int column = 0 ; column < width ; column++ ) {
					make_pixel ( 255 , 255 , 255 );
					//fprintf( stdout, " " ); 
				}
			}
	   		//Make the bottom half red./a.
			for ( int row = 0 ; row < (height - height / 2) ; row++ ) {
				//Make pixels red until end of line is reached
				for ( int column = 0 ; column < width ; column++ ) {
					make_pixel ( 255 , 0 , 0 );
				}
			}
			break;
		//make Netherlands flag
		case 2:
			//Calculate the height of the Dutch flag
			height = calculate_height ( 2 , 3 , width );
			//Make header file using height and width
			make_ppm_header(width, height);
			//Make the top third red
			for (int row = 0 ; row < height / 3 ; row++) {
				//Make pixels red until end of line is reached
				for (int column = 0 ; column < width ; column++) {
					make_pixel ( 174 , 28 , 40 );
					//make_pixel ( 174, 28, 40);
				}
			}
			//Make the middle white
			for (int row = 0 ; row < height / 3 ; row++) {
				//Make pixels white until end of line is reached
				for (int column = 0 ; column < width ; column++) {
					make_pixel ( 255, 255, 255);
				}
			}
			//Make the bottom third blue
			for (int row = 0 ; row < height / 3 + height % 3 ; row++) {
				//Make pixels blue until end of line is reached
				for (int column = 0 ; column < width ; column++) {
					make_pixel ( 33 , 70 , 139);
					//make_pixel ( 33, 70, 139);
				}
			}
			break;
	
		//make Italian flag
		case 3:
			//Calculate the height of the Italian flag
			height = calculate_height ( 2 , 3 , width );
			//Make header file using height and width
			make_ppm_header(width, height);
			//Make lines of the flag until the height is filled
			for (int row = 0 ; row < height ; row++) {
				//The 1st third of the line is red
				for (int column = 0 ; column < width / 3 ; column++) {
					make_pixel ( 0 , 140 , 69 );
				}
				//The 2nd third of the line is white
				for (int column = 0 ; column < width / 3 ; column++) {
					make_pixel ( 244 , 245 , 240 );
				}
				//The 3rd third of the line is green
				for (int column = 0 ; column < width / 3 + width % 3 ; column++) {
					make_pixel ( 205 , 33 , 42 );
				} 
			}
			break;
	}
 
}
