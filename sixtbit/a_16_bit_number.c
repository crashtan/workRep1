/*
 * a_16_bit_number.c
 *
 *  Created on: Jan 16, 2018
 *      Author: Administrator
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int count_no_1s (int copied_Byte);
void to_binary(int input, char* to_string);

int main(void) {
	unsigned int number = 0;
	unsigned short int ones = 0;
	char b_string[9];

	puts("Enter a 16 bit Hex Number and press Enter");

	number=0xAFAD;

	int lowerByte = number&0x00FF;
	int upperByte = number&0xFF00;
	upperByte = upperByte>>8;

	printf("LowerByte is:%x\n", lowerByte);
	to_binary(lowerByte, b_string);
	printf("LowerByte Binary: %s\n", b_string);

	printf("UpperByte is:%x\n", upperByte);
	to_binary(upperByte, b_string);
	printf("UpperByte Binary: %s\n", b_string);

	ones = count_no_1s(lowerByte);
	printf("The no of 1s in LowerByte is: %d\nThe no of 0s in LowerByte is: %d\n",ones,8-ones);

	ones = count_no_1s(upperByte);
	printf("The no of 1s in UpperByte is: %d\nThe no of 0s in UpperByte is: %d\n",ones,8-ones);
	return 0;
}

int count_no_1s (int copied_Byte) {
	unsigned short int test_Byte;
	unsigned short count = 0;
	//XXX1 Mask
	for (int i=0;i<8;i++) {
	test_Byte = copied_Byte&0x1;
	if (!(0x1^test_Byte))
		count++;
	copied_Byte = copied_Byte>>1;
	}

	return count;
}

void to_binary(int input, char* to_string) {
	unsigned short int test_Byte;

	for (int i=7;i>=0;i--) {
		test_Byte = input&0x1;
		if (test_Byte == 0x01)
		//if (!(0x1^test_Byte))
			to_string[i]='1';
		else
			to_string[i]='0';
		input = input>>1;

	}
	to_string[8]='\0';
}
