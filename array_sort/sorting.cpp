/*
 * sorting.cpp
 *
 *  Created on: Jan 18, 2018
 *      Author: Administrator
 */
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

//DEFINITIONS--------------------------------------------------------------------
#define SIZE 10

//FUNCTIONS-----------------------------------------------------------------------
inline void swap (int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

inline int mid_point (size_t start, size_t end) {
		size_t midpoint_index = (int)((start+end)/2);
	return midpoint_index;
}

int find_min_index(const int* array_name, size_t start, size_t end) {
	size_t min_index = 0 ;
	int min = *(array_name+start);

	for (unsigned int z = start; z < end; z++) {
		if ( *(array_name+z) <= min) {
			min = *(array_name+z);
			min_index = z;
		}
	}
	return min_index;
}

inline void print_array(const int* array_name) {
	for (unsigned int z=0; z<SIZE; ++z) {
		printf("%3d ", *(array_name+z));
	}
	printf("\n");
}

void insertion_sort(int* array, size_t size, size_t start) {

}

//SORTING-----------------------------------------------------------------
void selection_sort(int* array, size_t size) {
	size_t min_index;
	for (unsigned int i=0; i<size-1; i++) {
		min_index = find_min_index(array, i, size);
		//printf("%2d\n",min_index);
		swap ( (array+i), (array+min_index) );
		print_array(array);
	}
}

void bubble_sort(int* array, size_t size) {
	for (unsigned int j=0; j<size-1;j++) {
		for (unsigned int i=0; i<size-1; i++) {
			if ( *(array+i+1)<*(array+i) ) {
				swap( (array+i+1),(array+i) );
			}
			print_array(array);
		}
	}
}

void quick_sort(int* array, const size_t start, const size_t end) {

	size_t midpoint_index = mid_point(start, end);
	size_t new_start = midpoint_index+1;
	size_t new_end = end;

	printf("mid %d, start %d, end %d\n", midpoint_index, start, end);

	//SWAP LEFT AND RIGHT VALUES
	for (unsigned int i=0; i<=end; i++) {
		//UPPER HALF
		for (unsigned int k=midpoint_index+1; k<=end; k++) {
			if (*(array+k)<*(array+midpoint_index) ) {
				swap ( (array+midpoint_index), (array+k) );
				print_array(array);
				break;
			}
		}
		//LOWER HALF
		for (unsigned int j=start; j<midpoint_index; j++) {
			if (*(array+j)>*(array+midpoint_index) ) {
				swap ( (array+midpoint_index), (array+j) );
				print_array(array);
				break;
			}
		}
		//print_array(array);
	}

	//RECURSION + END CONDITIONS
	if (start != end) {
		quick_sort(array, start, midpoint_index); //lower half
	}
	if ( (start != end) ) {
		//printf(" new_start %d new_end %d\n", new_start, new_end);
		quick_sort(array, new_start, new_end); //upper half
	}

}

//MAIN---------------------------------------------------------------------

int main(void) {
		srand(time(NULL));
		int random_array[SIZE];

		if (random_array == NULL) {
			printf("Malformed Array Input: NULL");
			exit(-1);
		}

		//SWAP TEST
		/*
		int a=5, b=2;
		swap(&a, &b);
		printf("%2da,%2db\n",a,b);
		*/

		//FILL ARRAY WITH RANDOM NUMBERS
		for (int z=0; z<SIZE; ++z) {
			int temp = rand()%100;
			random_array[z] = temp;
		}
		print_array(random_array);

		/*
		printf("SELECTION SORT \n");
		selection_sort(random_array, SIZE);
		printf("\n");
		*/

		/*
		printf("BUBBLE SORT \n");
		bubble_sort(random_array, SIZE);
		printf("\n");
		*/

		printf("QUICK SORT \n");
		quick_sort(random_array, 0, SIZE-1);
		print_array(random_array);
		printf("\n");

	return 0;
}


