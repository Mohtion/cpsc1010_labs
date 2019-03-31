/*
* lab03b.c
* Author: Mohan Foh
* Lecture, Lab Section: 003, 003
* Lab #: 03
* Submitted on: 9/13/28
*
* Purpose: 1 or 2 sentences stating what the program does.
*
* Academic Honesty Declaration:
* The following code represents my own work and I have neither received
nor
* given assistance that violates the collaboration policy posted with this
assignment.
* I have not copied or modified code from any other source other than the
lab
* assignment, course textbook, or course lecture slides. Any unauthorized
* collaboration or use of materials not permitted will be subjected to
academic
* integrity policies of Clemson University and CPSC 1010/1011.
* I acknowledge that this lab assignment is based upon an assignment
created by
* Clemson University and that any publishing or posting of this code is
* prohibited unless I receive written permission from Clemson University.
*/

#include <stdio.h>

int main () {
	int hours;
	float hourly_rate;
	float gross_pay;
	float net_pay;
	float federal_tax;
		/*	Over-	But not Over-			of excess over
			71	254	0.00 plus 10%		71
			254	815	18.30 plus 12%		254
			815	1658	85.62 plus 22%		815
			1658	3100	271.08 plus 32%		1658
			3100	3917	617.16 plus 32% 	3100
			3917	9687	878.60 plus 35%		3917
			9687		2898.10 plus 37%	9687
		*/
		
	float state_tax;
		/*	Over-	But not Over-			of excess over
			0	44	0.00 plus 1.4%		0
			44	88	0.62 plus 3%		44
			88	132	1.94 plus 4%		88
			132	176	3.70 plus 5%		132
			176	220	5.90 plus 6% 		176
			220		8.54 plus 7%		220
		*/
	float FICA_tax; //The social security tax 6.2% of gross pay
	float medicare_tax; // 1.45% of gross pay
	
	printf ("Welcome! Let's see how much you can get paid. \n\n");

	while (hours >= 0) {
		printf ("Hours per Week:\t");
		scanf ( "%d" , &hours );
		printf ( "Hourly Rate:\t$" );
		scanf ( "%f" , &hourly_rate );
		gross_pay = hours * hourly_rate;
		printf ( "Gross Pay:\t$%.2f\n" , gross_pay );
	
		//The block of code below determines value of federal tax
		if ( gross_pay < 71)
			federal_tax = gross_pay * 0.1 ;
		else if( gross_pay > 71 && gross_pay <= 254 )
			federal_tax = ((gross_pay - 71) * 0.1);
		else if( gross_pay > 254 && gross_pay <= 815 )
			federal_tax = ((gross_pay - 254) * 0.12) + 18.3;
		else if( gross_pay > 815 && gross_pay <= 1658 )
			federal_tax = ((gross_pay - 815) * 0.22) + 85.62;
		else if( gross_pay > 1658 && gross_pay <= 3100 )
			federal_tax = ((gross_pay - 1658) * 0.24) + 271.08;
		else if( gross_pay > 3100 && gross_pay <= 3917 )
			federal_tax = ((gross_pay - 3100) * 0.32) + 617.16;
		else if( gross_pay > 3917 && gross_pay <= 9687 )
			federal_tax = ((gross_pay - 3917) * 0.35) + 878.6;
		else
			federal_tax = ((gross_pay - 9687) * 0.37) + 2898.1;	
		//The block of code above determines value of federal tax
	
		//The block of code below determines value of state tax
		if ( gross_pay < 44)
			state_tax = gross_pay * 0.014;
		else if( gross_pay > 44 && gross_pay <= 88 )
			state_tax = ((gross_pay - 44) * 0.03) + 0.62 ;
		else if( gross_pay > 88 && gross_pay <= 132)
			state_tax = ((gross_pay - 88) * 0.04) + 1.94 ;
		else if( gross_pay > 132 && gross_pay <= 176)
			state_tax = ((gross_pay - 132) * 0.05) + 3.70 ;
		else if( gross_pay > 176 && gross_pay <= 220)
			state_tax = ((gross_pay - 176) * 0.06) + 5.90 ;
		else
			state_tax = ((gross_pay - 220) * 0.07) + 8.54;	
		//The block of code above determines value of state tax
	
	
		FICA_tax = 0.062 * gross_pay; //calculates social security tax
		medicare_tax = 0.0145 * gross_pay; // calculates medicare tax
		
		net_pay = gross_pay - (federal_tax + state_tax + FICA_tax + medicare_tax) ; // calculates net pay
		
		printf ( "Net Pay:\t$%.2f\n\n" , net_pay );
		printf ( "Deductions\n" );
		printf ( "Federal:\t$%.2f\n" , federal_tax );
		printf ( "State:\t\t$%.2f\n" , state_tax );
		printf ( "FICA:\t\t$%.2f\n" , FICA_tax );
		printf ( "Medicare:\t$%.2f\n\n\n" , medicare_tax );
	
	}

}
