/*
 * a_16_bit_number.c
 *
 *  Created on: Jan 16, 2018
 *      Author: Administrator
 */


#include <stdio.h>

int main(void) {
	unsigned short int number;
	//printf("Enter a 16 bit Hex Number:\n");
	//scanf("%d", &number);

	number=0xFFFD;

	int lowerByte = number&0x00FF;
	int upperByte = number&0xFF00;
	upperByte = upperByte>>4;

	printf("LowerByte is:%d\n", lowerByte);
	printf("UpperByte is:%d\n", upperByte);



	return 0;
}
