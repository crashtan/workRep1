/*
 * enum.c
 *
 *  Created on: Jan 25, 2018
 *      Author: Administrator
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum DAYS { Monday, Tuesday, friday=2, Friday=2};

struct first_last_64 {
	unsigned int a: 16;
	//unsigned int  :  0;
	unsigned int b: 16;
};

int main (void) {

	struct first_last_64 example1,example2,example3;
	enum DAYS dayset;
	int comparison = 2;

	example1.a = 0x4141;
	example1.b = 0x4242;

	example2.a = 0x4141;
	example2.b = 0x4242;

	example3.a = 0x4141;
	example3.b = 0x4242;

	FILE *fp;

	if ( (fp = fopen("test.txt", "w+"))== NULL )
		puts("FILE opening error");

	fwrite( &example1, sizeof(example1), 1, fp);
	fprintf(fp,"%c" , '\n');

	fwrite( &example2, sizeof(example2), 1, fp);
	fprintf(fp,"%c" , '\n');

	fwrite( &example3, sizeof(example3), 1, fp);
	fprintf(fp,"%c" , '\n');

	comparison = memcmp(&example1, &example2, sizeof(struct first_last_64));
	printf("comparison value is: %d\n", comparison);

	if (comparison != 0) {
		printf("example1 and example2 are not equal\n");
	}
	if (comparison == 0) {
			printf("example1 and example2 are equal\n");
		}

	printf("size is: %d , %d bits\n", sizeof(dayset) , 8*sizeof(dayset) );
	printf("size is: %d , %d bits\n", sizeof(example1) , 8*sizeof(example1) );

	printf("float test is: %.10lf\n",  33.1460528);
	return 0;
}
