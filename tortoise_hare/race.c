/*
 * race.c
 *
 *  Created on: Jan 22, 2018
 *      Author: Administrator
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

size_t get_time(void) {
	size_t current_time = (time(0));
	return current_time;
}

/*---------------------------------------------- RANDOM ------------------------------*/
 size_t roll(void) {
	size_t random_number = (rand()%10) + 1;
	//printf("%u\n", result);
	return random_number;
}

/*---------------------------------------------- PRINT ------------------------------*/

void print_position(const short int hare_position, const short int tortoise_position) {
	size_t flag_hit = 0;
	for (short int range=1; range<=70; range++) {
		if( (range==hare_position) && (hare_position==tortoise_position) ) {
			printf("@");
			flag_hit = 1;
		}
		else {
			if (range==hare_position)
				printf("H");
			else {
				if (range==tortoise_position)
					printf("T");
				else
					printf("-");
			}
		}
	}
	if (flag_hit == 1)
		printf(" OUCH!!! Same Position\n");
	else
		printf("\n");
}

/*------------------------------------------UPDATE FUNCTIONS ------------------------------*/

void move(short int *position, short int spaces) {
	*position = *position + spaces;
	if (*position < 1)
		*position = 1;
	if (*position > 70)
		*position = 70;
}

void hare_moves (size_t (*roll)(void), short int *position ) {
	size_t result = (size_t)roll;
	switch (result) {
		//SLEEP
		case 1:
		case 2:
			//Do nothing
			break;
		//BIG HOP - 9 Squares to right
		case 3:
		case 4:
			move(position, 9);
			break;
		//BIG SLIP - 12 Squares to left
		case 5:
			move(position, -12);
			break;
		//SMALL HOP - 1 Square to right
		case 6:
		case 7:
		case 8:
			move(position, 1);
			break;
		//SMALL SLIP - 2 Squares to left
		case 9:
		case 10:
			move(position, -2);
			break;
		//END
		default:
			break;
	}

}

void tortoise_moves (size_t (*roll)(void), short int *position ) {
	size_t result = (size_t)roll;
	switch (result) {
		//FAST PLOD - 3 Squares Right
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			move(position, 3);
			break;
		//SLIP - 6 Squares to left
		case 6:
		case 7:
			move(position, -6);
			break;
		//SLOW PLOD - 1 Square to right
		case 8:
		case 9:
		case 10:
			move(position, 1);
			break;
		//END
		default:
			break;
	}
}

void on_tick (short int *hare_position, short int *tortoise_position ) {
	//run program
	hare_moves( roll(), hare_position);
	tortoise_moves( roll(), tortoise_position);
	//End tick
}

/*----------------------------------------------- MAIN ------------------------------*/
int main (void) {


	//Initialize Variables
	time_t time_start = get_time();
	time_t counter = 0;

	srand(time(0));
	size_t count = 0;
	short int hare_position = 1;
	short int tortoise_position = 1;

	short int flag = 0;

	on_tick(&hare_position, &tortoise_position);
	//Win Condition
	while ( (hare_position != 70) && (tortoise_position != 70) ) {
		time_t time_now = get_time();

		//Get 1 second tick
		counter = (time_now%time_start);
		//printf("Time now is: %u\n", (time_now%time_start) );
		//printf("count is: %u\n", count);

		if (counter>count || flag==0) {
			flag = 1;
			//printf("count is: %u\n", count);
			on_tick(&hare_position, &tortoise_position);
			//print update
			print_position(hare_position, tortoise_position);
			count++;
		}
	}


	if ( (hare_position == 70) && (tortoise_position == 70) ) {
		printf("Its a TIE !!!\n");
	}
	else {
		if (hare_position == 70)
			printf("Hare WINS !!!\n");
		if (tortoise_position == 70)
			printf("Tortoise WINS !!!\n");

	}

	return 0;
}


