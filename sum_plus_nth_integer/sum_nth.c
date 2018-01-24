/*
 * sum_nth.c
 *
 *  Created on: Jan 23, 2018
 *      Author: Administrator
 */

#include <stdio.h>

int main(void) {

	unsigned int nstart = 0;
	unsigned int nstop = 200;
	unsigned int n = 2;
	unsigned int i;
	unsigned int count;


	/* WHILE LOOP */
	printf("WHILE LOOP\n");
	count=1;
	i = nstart;
	printf("Value of i is: %u\n", i);
	while ( (i>=nstart) && (i<nstop-(count*n)) ) {
		i += count*n;
		printf("Value of i is: %u\n", i);
		count++;
	}
	printf("\n");

	/* DO-WHILE LOOP */
	printf("DO-WHILE LOOP\n");
	count=1;
	i = nstart;
	printf("Value of i is: %u\n", i);
	do {
		i += count*n;
		printf("Value of i is: %u\n", i);
		count++;
	} while ( (i>=nstart) && (i<nstop-(count*n)) );
	printf("\n");


	/* FOR LOOP */
	printf("FOR LOOP\n");
	for (i = nstart, count=0; i<nstop; i+=count*n){
		printf("Value of i is: %u\n", i);
		count++;
	}
	printf("\n");

	return 0;
}

