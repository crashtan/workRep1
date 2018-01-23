/*
 * casting.cpp
 *
 *  Created on: Jan 18, 2018
 *      Author: Administrator
 */
#include <iostream>
#include <limits>
#include <stdio.h>

void test_array (int* ptr_array) {
	short int small;
	ptr_array[4] = 6;
	printf("TEST: 5th element is %d\n", ptr_array[4]);
	printf("Size of short is %d\n", sizeof(small) );
}

int main (void) {

	int array[10];
	test_array(array);

	long long int test1 = 7000000000;
	int test2 = 65536;
	int test2_0 = 7000000000;
	float test3 = 10.2;
	double test3_1 = 10.2;
	long double test3_2 = 10.2;
	float test3_0 = 10.19999f;
	double test4 = 10.19999L;


	long double result;

	//result = test2_0;
	//result = test1;
	//result = test3/test3_0;
	result = test3_2/test4;

	std::cout.precision(20);
	std::cout << result << std::endl;

	return 0;
}
