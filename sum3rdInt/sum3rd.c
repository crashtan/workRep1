/*
 * sum3rd.c
 *
 *  Created on: Jan 23, 2018
 *      Author: Administrator
 */

#include <stdio.h>

int main(void) {


	unsigned int i;


	/* WHILE LOOP */
	printf("WHILE LOOP\n");
	i = 2;
	printf("Value of i is: %u\n", i);
	while ( (i>=2) && (i<97) ) {
		i += 3;
		printf("Value of i is: %u\n", i);
	}
	printf("\n");

	/* DO-WHILE LOOP */
	printf("DO-WHILE LOOP\n");
	i = 2;
	printf("Value of i is: %u\n", i);
	do {
		i += 3;
		printf("Value of i is: %u\n", i);
	} while ( (i>=2) && (i<97) );
	printf("\n");


	/* FOR LOOP */
	printf("FOR LOOP\n");
	i = 2;
	for (i = 2; i<100; i+=3){
		printf("Value of i is: %u\n", i);
	}
	printf("\n");

	return 0;
}

