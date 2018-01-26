/*
 * enum.c
 *
 *  Created on: Jan 25, 2018
 *      Author: Administrator
 */
#include <stdlib.h>
#include <stdio.h>

enum DAYS { Monday, Tuesday, friday=2, Friday=2};

struct first_last_64 {
	unsigned short int a: 16;
	unsigned int  : 32;
	unsigned short int b: 16;
};

int main (void) {

	struct first_last_64 example1;
	enum DAYS dayset;

	printf("size is: %d , %d bits\n", sizeof(dayset) , 8*sizeof(dayset) );
	printf("size is: %d , %d bits\n", sizeof(example1) , 8*sizeof(example1) );

	printf("float test is: %d\n",  33.1461f);
	return 0;
}
