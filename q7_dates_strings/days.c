/*
 * days.c
 *
 *  Created on: Jan 25, 2018
 *      Author: Administrator
 */

#define BASE_DAY 	1
#define BASE_MONTH 	1
#define BASE_YEAR 	80

#include <stdio.h>
#include <stdlib.h>

int main (void) {

	int day = 0;
	int month = 0;
	int year = 0;

	unsigned int day_sum = 0;


	printf("Enter Date of format mm-dd-yy: ");
	scanf("%2d-%2d-%2d", &month, &day, &year);
	printf("Entered Date is: %d-%d-%d\n", month, day, year);

	int calc_year = year-BASE_YEAR;

	if (day>31 || day<1) {
		printf("Malformed Day Entered\n");
		exit(0);
		}

	if (month>12 || month<1) {
		printf("Malformed Month Entered\n");
		exit(0);
	}

	if (year < 80) {
		printf("Year Entered is less than 1980\n");
		exit(0);
	}


	if (calc_year<20) {

		abs(year);
		abs(month);
		abs(day);

		// a.
		day_sum = (int)(30.42*(month-1))+day;

		// b.
		if (month == 2)
			day_sum++;
		// c.
		if (month > 2 && month <8)
			day_sum--;

		if (calc_year%4==0) {
			// d.
			if (month>2)
				day_sum++;
		} else {
			// e.
			day_sum += 1461*(int)(calc_year/4);

			//f.
			day_sum += (365*(calc_year%4))+1;
		}
	} else {
		printf("Date is greater than 12-12-1999\n");
	}

	printf("Total days since 01-01-1980 is: %d\n", day_sum);

	return 0;
}
