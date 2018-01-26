/*
 * sine.c
 *
 *  Created on: Jan 25, 2018
 *      Author: Administrator
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double normalization (double unnormalized) {
	if (unnormalized == 0) {
		return 0;
	} else {
		if (unnormalized > 0) {
			while (unnormalized > 2*M_PI )
				unnormalized -= (2*M_PI);
			}
		else {
			while (unnormalized < -2*M_PI ) {
				unnormalized += (2*M_PI);
				//printf("Normalized radians is: %lf\n", unnormalized);
			}
		}
	return unnormalized;
	}
}

unsigned long long int factorial(size_t n) {
	if (n<=1)
		return 1;
	else
		return n*factorial(n-1);
}

double sine_taylor_series(double radians, int n) {
	//PARTIAL SUMS FOR SINE TAYLOR SERIES
	double partial_sum = pow(radians, (2*n+1)) / factorial(2*n+1) ;
	//EVEN OR ODD
	if (n%2==0) {
		printf("Partial Sum %2d is: %+24.20lf\n", n, partial_sum);
		return partial_sum;
	} else {
		printf("Partial Sum %2d is: %+24.20lf\n", n, -partial_sum);
		return -partial_sum;
	}
}


double calc_sine(double radians, size_t no_of_terms, double accuracy) {
	//TAYLOR SERIES APPROXIMATION
	double answer = 0;
	double partial_sum = 0;
	for(size_t i=0; i<=no_of_terms; i++ ) {
		partial_sum = sine_taylor_series(radians, i);
		answer += partial_sum;
		if ( (fabs(partial_sum)<accuracy) && (accuracy > 0) ) {
			printf("Set Accuracy Reached: ");
			break;
		}
		if (accuracy == 0){}
	}
	printf("Accuracy %.10lf\n", accuracy);
	return answer;
}


int main (void) {

	//IN RADIANS
	double radians = -34.1521;
	int no_of_terms = 10;
	double result;
	double accuracy = 0;


	printf("Enter Value in radians to calculate sine of:");
	scanf("%lf", &radians);
	printf("Enter no of terms:");
	scanf("%d", &no_of_terms);
	printf("Enter accuracy, Enter 0 for max accuracy terms:");
	scanf("%lf", &accuracy);

	abs(no_of_terms);
	abs(accuracy);

	//FACTORIAL TEST
	//printf("factorial is: %d\n", factorial(8) );

	//NORMALIZATION FUNCTION
	double normalized_radians = normalization(radians);

	printf("Radians is: %lf\n", radians);
	printf("Normalized radians is: %lf\n", normalized_radians);
	printf("No of terms is: %d\n", no_of_terms);

	result = calc_sine(normalized_radians, no_of_terms, accuracy);
	printf("Sin(X), where X in radians is: %.*lf\n", no_of_terms, result);

	return 0;
}
