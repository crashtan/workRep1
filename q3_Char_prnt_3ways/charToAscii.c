/*
 * charToAscii.c
 *
 *  Created on: Jan 23, 2018
 *      Author: Administrator
 */

#include <stdio.h>

int main(void) {

	const char* text_1 = "AAA";
	const char* text_2 = "BBB";
	const char* text_3 = "CCC";

	/* WHILE LOOP */
	printf("WHILE LOOP\n");
	printf("Text to ASCII is:");
	while ( *text_1!='\0' ) {
		printf("%X", (int)*text_1 );
		text_1++;
	}
	printf("\n");

	/* DO-WHILE LOOP */
	printf("DO-WHILE LOOP\n");
	printf("Text to ASCII is:");
	do {
		printf("%X", (int)*text_2 );
		text_2++;
	} while ( *text_2!='\0' );
	printf("\n");


	/* FOR LOOP */
	printf("FOR LOOP\n");
	printf("Text to ASCII is:");
	for (; *text_3!='\0'; text_3++){
		printf("%X", (int)*text_3 );
	}
	printf("\n");

	/* PADDING TEST FORMATTING
	int n = 8;
	printf("%*.*d\n", n, 3, 1234);
	*/

	return 0;
}

