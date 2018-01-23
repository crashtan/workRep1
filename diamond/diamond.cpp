/*
 * diamond.cpp
 *
 *  Created on: Jan 23, 2018
 *      Author: Administrator
 */
#include <stdio.h>
#include <stdlib.h>

//Diamond

void print_diamond(unsigned int no_of_rows) {

//NON FILL ----------------------------------------------------------
	/*
	for (size_t j=0; j<=no_of_rows/2; j++) {
		for (size_t i=0; i<no_of_rows; i++) {
			if ( (i == (no_of_rows/2)-j) )
				printf ("%c", '+');
			else {
				if ( i==(no_of_rows/2)+j )
					printf ("%c", 'X');
				else
					printf("%c", '=');
			}
		}
		printf("%c", '\n');
	}

	for (size_t j=(no_of_rows/2)+2; j<=no_of_rows; j++) {
		for (size_t i=0; i<no_of_rows; i++) {
			if (i == j-(no_of_rows/2)-1 )
				printf ("%c", '+');
			else {
				if ( i == no_of_rows-j+(no_of_rows/2) )
					printf ("%c", 'X');
				else
					printf("%c", '=');
			}
		}
		printf("%c", '\n');
	}*/

//FILL ----------------------------------------------------------------

	for (size_t j=0; j<=no_of_rows/2; j++) {
		for (size_t i=0; i<no_of_rows; i++) {
			if ( (i >= (no_of_rows/2)-j) && ( i <=(no_of_rows/2)+j ))
				printf ("%c", 'X');
			else {
				printf("%c", '=');
			}
		}
		printf("%c", '\n');
	}

	for (size_t j=(no_of_rows/2)+2; j<=no_of_rows; j++) {
		for (size_t i=0; i<no_of_rows; i++) {
			if ( (i >= j-(no_of_rows/2)-1 ) && ( i <= no_of_rows-j+(no_of_rows/2) ) )
				printf ("%c", 'X');
			else {
				printf("%c", '=');
			}
		}
		printf("%c", '\n');
	}
}

int main (void) {

	unsigned int no_of_rows;

	printf("Enter the no of rows of diamond:\n");

	scanf("%u", &no_of_rows);

	print_diamond(no_of_rows);

	return 0;
}
