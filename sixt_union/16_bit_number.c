/*
 * 16_bit_number.c
 *
 *  Created on: Jan 25, 2018
 *      Author: Administrator
 */
#include <stdio.h>

union sixteenbit {
	unsigned char a;
	unsigned short int b;
} number;

char to_binary(char input, char* to_string) {
	unsigned char test_Byte;
	unsigned char count = 0;

	for (char i=7;i>=0;i--) {
		test_Byte = input&0x1;
		if (test_Byte==1) {
			to_string[i]='1';
			count++;
		}
		else
			to_string[i]='0';
		input = input>>1;
	}
	to_string[8]='\0';
	return count;
}

int main (void) {
	number.b = 0xAFAD;

	printf("Lower number is: %X\n", number.a);
	printf("Upper number is: %X\n", (number.b>>8) );

	char string[9];
	char counted_ones_lower = to_binary( (char)(number.a) , string);
	printf("Lower Binary is: %s\n", string);
	char counted_ones_upper = to_binary( (char)(number.b>>8) , string);
	printf("Upper Binary is: %s\n", string);
	return 0;
}

