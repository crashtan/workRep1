/*
 * a_16_bit_number.cpp
 *
 *  Created on: Jan 17, 2018
 *      Author: Administrator
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

char to_binary(char input, char* to_string);

inline void test_print (const char* array) {
	for (char i=0;i<7;i++)
		printf("%c",*(array+i));
	printf("\n");
}

int main(void) {
	while (true) {
		unsigned int number;
		unsigned char ones = 0;
		char b_string[9];


		ENTER:
		cout << "Enter a 16 bit Hex Number and press Enter:";
		cin >> hex >> number;

		//FFFFF for exit
		if (number==0xFFFFF)
			break;
		else if (number>0xFFFF) goto ENTER;

		printf("Entered number is: %x\n\n", number);

		//Casting to char
		unsigned char lowerByte = (char) number;
		unsigned char upperByte = (char) ((number&0xFF00)>>8);  //get upper byte

		//LowerByte output
		printf("LowerByte is:%x\n", lowerByte);
		ones = to_binary(lowerByte, b_string);
		printf("LowerByte Binary:");
		test_print(b_string);
		printf("The no of 1s in LowerByte is: %u\nThe no of 0s in LowerByte is: %u\n\n",ones,8-ones);

		//Upper Byte output
		printf("UpperByte is:%x\n", upperByte);
		ones = to_binary(upperByte, b_string);
		printf("UpperByte Binary:");
		test_print(b_string);
		printf("The no of 1s in UpperByte is: %u\nThe no of 0s in UpperByte is: %u\n\n",ones,8-ones);
	}
	//END
	return 0;
}

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
	to_string[8] = '\0';
	return count;
}


