/*
 * pyramid.c
 *
 *  Created on: Jan 25, 2018
 *      Author: Administrator
 */
#include <stdio.h>
#include <stdlib.h>

enum FLAG {ZERO, ONE};

void print_pyramid (const int *size) {

	enum FLAG flag;
	int start_num;

	for (size_t j = 1; j<=*size; j++) {
		flag=ZERO;
		start_num=j;

		for (size_t i = 1; i<=*size-j; i++) {
			printf(" ");
		}

		for (size_t k=1; k<=(2*j-1); k++) {

			if(flag==ZERO) {
				printf("%d",start_num%10);
				start_num++;
			}
			else {
				start_num--;
				printf("%d",start_num%10);
			}
			if (k==j) {
				start_num--;
				flag=ONE;
			}
		}
	printf("\n");
	}
}

int main (void) {

	int size = 20;


	printf("Enter pyramid size:\n");
	scanf("%d", &size);

	while (size<=0) {
		printf("Enter pyramid size > 0\n:");
		scanf("%d", &size);
	}

	print_pyramid(&size);

	return 0;
}
