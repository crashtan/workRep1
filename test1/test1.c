/*
 * test1.c
 *
 *  Created on: Jan 16, 2018
 *      Author: Administrator
 */
#include <stdio.h>

int main(void) {
	unsigned char inbyte = 0x0FD;
	unsigned char out1,out2,out3;

	out1 = inbyte%10;
	out2 = (inbyte/10)%10;
	out3 = (inbyte/100)%10;


	printf("%d%d%d\n",out3,out2,out1);


	int a = 7;
	printf("%d",&a);

	return 0;
}

