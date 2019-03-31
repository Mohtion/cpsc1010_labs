/*
* flags_revised.c
* Author: Mohan Foh
* Lecture, Lab Section: 003, 003
* Lab #: 09
* Submitted on: 10/26/18
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

typedef struct pixel_struct {
	int r;
	int g;
	int b;
} pixel;

typedef struct image_struct {
	int width;
	int height;
	int country_code;
} image;

image calculate_height (double width, int country_code);
void make_pixel (pixel pixelInfo);
void make_ppm_header (image imageInfo);
void make_ppm_image (int country_code, int width);
pixel get_color (int column, int row, image imageInfo);



int main()
{
	double width = 0, country_code = 0;
	int floored_width = 1;
	//loops if country code is invalid
	while (!(country_code == 1 || country_code == 2 || country_code == 3 || country_code == 4)) {
		//prompt user to enter country_code of chosen flag
		fprintf ( stderr, "What country's flag do you want to create? " );
		fscanf(stdin, "%lf", &country_code);
		if (!(country_code == 1 || country_code == 2 || country_code == 3 || country_code == 4)) {
			fprintf ( stderr, "The code has to be a 1, 2, 3, or 4. Please try again.\n\n" ) ;
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
//Calculates the height with proper rounding.
//Hoist to fly ratio depends on flag
image calculate_height (double width, int country_code ) {
	double calculated_height = 0;
	int floored_height = 0;
	//struct image has width, height, and country code
	image imageStruct;
	imageStruct.width = width;
	imageStruct.height = 0;
	imageStruct.country_code = country_code;
	switch  (country_code) {
		//if country code 1, calculate poland height
		case 1:
			imageStruct.country_code = 1;
			calculated_height = width * 5 / 8 ;
			floored_height = calculated_height;	
			if (calculated_height - floored_height < .5) {
				imageStruct.height = floored_height;
			}
			else if (calculated_height - floored_height >= .5) {
				imageStruct.height = floored_height + 1;
			}
			//return poland image struct
			return imageStruct;
			break;
		//if country code 2, calculate netherlands height
		case 2:
			imageStruct.country_code = 2;
			calculated_height = width * 2 / 3 ;
			floored_height = calculated_height;
			if (calculated_height - floored_height < .5) {
				imageStruct.height = floored_height;
			}
			else if (calculated_height - floored_height >= .5) {
				imageStruct.height = floored_height + 1;
			}
			//return netherlands image struct
			return imageStruct;
			break;
		//if country code 3, calculate italy height
		case 3:
			imageStruct.country_code = 3;
			calculated_height = width * 2 / 3 ;
			floored_height = calculated_height;
			if (calculated_height - floored_height < .5) {
				imageStruct.height = floored_height;
			}
			else if (calculated_height - floored_height >= .5) {
				imageStruct.height = floored_height + 1;
			}
			//return italy image struct
			return imageStruct;
			break;
		//if country code 4, calculate Benin height
		case 4:
			imageStruct.country_code = 4;
			calculated_height = width * 2 / 3 ;
			floored_height = calculated_height;
			if (calculated_height - floored_height < .5) {
				imageStruct.height = floored_height;
			}
			else if (calculated_height - floored_height >= .5) {
				imageStruct.height = floored_height + 1;
			}
			//return benin image struct
			return imageStruct;
			break;
		default:
			printf ("error: A bad country code went into the calculate height function.\n");
			return imageStruct;	
	}
}

// Creates a pixel with the colors you tell it to use when you call it
// To call it, just do something like make_pixel(244, 244, 244);
void make_pixel (pixel pixelInfo){
	//take in pixel struct, print pixel
	fprintf(stdout, "%c%c%c", pixelInfo.r, pixelInfo.g, pixelInfo.b);
}

// Creates a header with the desired width and height when you call it
void make_ppm_header (image imageInfo){
	fprintf(stdout, "P6\n");
	fprintf(stdout, "%d %d %d\n", imageInfo.width, imageInfo.height, 255);
}

//gets color depending on pixel location
pixel get_color (int column, int row, image imageInfo){
	pixel pixelInfo;
	switch (imageInfo.country_code){
		//if country_code is 1 (poland)
		case 1:
	    		//Make the top half of the flag white
			if ( row < imageInfo.height / 2 ) {
				// red, 255
				pixelInfo.r = 255;
				// blue, 255
				pixelInfo.g = 255;
				// green, 255
				pixelInfo.b = 255;
				return pixelInfo;
			}
	   		//Make the bottom half red./a.
			else if ( row >= imageInfo.height / 2 ) {
				// red, 255
				pixelInfo.r = 255;
				// blue, 0
				pixelInfo.g = 0;
				// green, 0
				pixelInfo.b = 0;
				return pixelInfo;
			}
			break;
		//if country_code is 2 (netherlands)
		case 2:
			//Make the top third red
			if (row < imageInfo.height / 3) {
				pixelInfo.r = 174;
				pixelInfo.g = 28;
				pixelInfo.b = 40;
				return pixelInfo;
			}
			//Make the middle white
			else if (row < (imageInfo.height / 3 * 2)) {
				pixelInfo.r = 255;
				pixelInfo.g = 255;
				pixelInfo.b = 255;
				return pixelInfo;
			}
			//Make the bottom third blue
			else if (row >= (imageInfo.height / 3 * 2)) {
				pixelInfo.r = 33;
				pixelInfo.g = 70;
				pixelInfo.b = 139;
				return pixelInfo;
			}
			break;
		//if country_code is 3 (italy)
		case 3:
			//Make the first third green
			if (column < imageInfo.width / 3) {
				pixelInfo.r = 0;
				pixelInfo.g = 140;
				pixelInfo.b = 69;
				return pixelInfo;
			}
			//Make the middle white
			else if (column < imageInfo.width / 3 * 2) {
				pixelInfo.r = 244;
				pixelInfo.g = 245;
				pixelInfo.b = 240;
				return pixelInfo;
			}
			//Make the last third red
			else if (column >= (imageInfo.width / 3 * 2)){
				pixelInfo.r = 205;
				pixelInfo.g = 33;
				pixelInfo.b = 42;
				return pixelInfo;
			}
			break;
		//if country_code is 4 (benin)
		case 4:
			//make gr
			if (column < imageInfo.width * 6 / 15) {
				pixelInfo.r = 0;
				pixelInfo.g = 170;
				pixelInfo.b = 0;
				return pixelInfo;
			}
			//make yellow 
			else if (column >= imageInfo.width * 6 / 15 && row < imageInfo.height / 2) {
				pixelInfo.r = 255;
				pixelInfo.g = 255;
				pixelInfo.b = 0;
				return pixelInfo;
			}
			//make red	
			else if (column >= imageInfo.width * 6 / 15 && row >= imageInfo.height / 2) {
				pixelInfo.r = 255;
				pixelInfo.g = 0;
				pixelInfo.b = 0;
				return pixelInfo;
			}		
	}
	return pixelInfo;
}
// Creates a complete ppm image when you call it
void make_ppm_image (int country_code, int width){
	//calculate height using calculate_height function and put it in image struct
	image imageInfo = calculate_height (width, country_code);
	//make_ppm_header takes in one image struct and outputs header
	make_ppm_header (imageInfo);
	//for number of rows in image
	for (int row = 0; row <= imageInfo.height; row++) {
		//for number of columns in a row
		for (int column = 0; column < imageInfo.width; column++) {
			//get_color takes in column, row, and country_code. returns pixel struct
			pixel pixelInfo = get_color ( column, row, imageInfo);
			//make_pixel takes in pixel struct and outputs the pixel rgb
			make_pixel (pixelInfo);
		}
	}
}
