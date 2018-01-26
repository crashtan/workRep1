/*
 * fibonacci.cpp
 *
 *  Created on: Jan 23, 2018
 *      Author: Administrator
 */
#include <stdio.h>
#include <stdlib.h>

// RETURNS THE Nth FIBONACCI NUMBER
void fibonacci_number(unsigned long int n){
	long long int count_value_n = 0;
	long long int count_value_n_1 = 0;
	long long int count_value_n_2 = 0;
	unsigned long int count = 1;

	while (count <= n) {
		if (count == 1) {
			count_value_n = 1;
			count_value_n_1 = 1;
			count_value_n_2 = 0;
		} else {
			if (count == 2) {
				count_value_n = 1;
				count_value_n_1 = 1;
				count_value_n_2 = 1;
			} else {
				count_value_n = count_value_n_1 + count_value_n_2;
				count_value_n_2 = count_value_n_1;
				count_value_n_1 = count_value_n;
			}
		}
		if (count_value_n<0) {
			printf("! Overflow ! \n");
			exit(0);
		} else {
			printf("Fibonacci number %ld, is %lld\n", count, count_value_n);
			count++;
		}
	}
}

int main (void) {
	unsigned long int entered_number = 1;

	printf("Enter the no of fibonacci number:\n");
	scanf("%ld", &entered_number);

	if (entered_number<1) {
		printf("Entered number is less than 1\n");
		exit(0);
	}

	fibonacci_number(entered_number);

	return 0;
}

