/*
 * fibonacci.cpp
 *
 *  Created on: Jan 23, 2018
 *      Author: Administrator
 */
#include <stdio.h>

// RETURNS THE Nth FIBONACCI NUMBER
void fibonacci_number(unsigned int n){
	unsigned int count_value_n = 0;
	unsigned int count_value_n_1 = 0;
	unsigned int count_value_n_2 = 0;
	unsigned int count = 1;

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
		printf("Fibonacci number %d, is %d\n", count, count_value_n);
		count++;
	}
}

int main (void) {
	unsigned int entered_number;

	printf("Enter the no of fibonacci number:\n");
	scanf("%u", &entered_number);
	printf("You entered: %u\n", entered_number);

	fibonacci_number(entered_number);

	return 0;
}

