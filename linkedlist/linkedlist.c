/*
 * linkedlist.c
 *
 *  Created on: Jan 26, 2018
 *      Author: Administrator
 */
// INCLUDES =========================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DEFINITIONS AND VARIABLES ========================================================================

#define STRING_SIZE 11

typedef struct linkedlist LinkedList;

LinkedList* nodePtr = NULL;

typedef struct linkedlist {
	char* string[STRING_SIZE];
	LinkedList* nodePtr;
} LinkedList;

// LIST SIZE ========================================================================================

unsigned int list_size(LinkedList* const list_start_address) {
	unsigned int size = 0;
	LinkedList* current_node = list_start_address;

	if (list_start_address == NULL) {
		printf("\nSize is: %d\n", size);
		return 0;
	}
	else {
		for (size = 0; current_node!=NULL; size++) {
			current_node = current_node->nodePtr;
		}
		printf("Size is: %d\n", size);
		return size;
	}
}

// GET ADDRESS ======================================================================================

LinkedList* get_address(const unsigned int location, LinkedList* const list_start_address) {
	LinkedList* return_address;
	LinkedList* current_node = list_start_address;

	unsigned int size = list_size (list_start_address);
	unsigned int location_copy = location;

	if (location_copy > size)
		location_copy = size;

	if (location_copy>size-1) {
		printf("Address for location %d is: NULL\n", location_copy);
		return NULL;
	} else {
		for (unsigned int i=0; i<=location_copy; i++) {
				return_address = current_node;
				current_node = current_node->nodePtr;
		}
		printf("Non Null Address for location %d is: %d\n", location_copy, return_address);
	}
	return return_address;
}

// ADD NODE =========================================================================================

void addNode(unsigned int location, char* string, LinkedList** list_start_address) {
	LinkedList* new_node_ptr = malloc(sizeof(LinkedList));
	unsigned int location_copy = location;
	unsigned int size = list_size (*list_start_address);

	if (location_copy > size)
		location_copy = size;

	if (location_copy == 0) {
		*new_node_ptr->string = string;
		new_node_ptr->nodePtr = NULL;
		*list_start_address = new_node_ptr;
	}
	else {
		LinkedList* previous_node = get_address(location_copy-1, *list_start_address);
		LinkedList* next_node = previous_node->nodePtr;

		*new_node_ptr->string = string;
		new_node_ptr->nodePtr = next_node;

		previous_node->nodePtr = new_node_ptr;
	}
	printf("----------- NEW NODE ADDED at location %d and address %d of value %s -----------\n", location_copy, new_node_ptr, *new_node_ptr->string);

}

// DELETE NODE =======================================================================================
void deleteNode(unsigned int location, LinkedList** list_start_address){

	unsigned int size = list_size (*list_start_address);
	unsigned int location_copy = location;

	if (location_copy > size)
		location_copy = size;

	if (location_copy == 0) {
		LinkedList* current_node = get_address(location_copy, *list_start_address);
		*list_start_address = current_node->nodePtr;
		free(current_node);
	}
	else {
		LinkedList* previous_node = get_address(location_copy-1, *list_start_address);
		LinkedList* current_node = previous_node->nodePtr;
		LinkedList* next_node = current_node->nodePtr;

		free(current_node);
		previous_node->nodePtr = next_node;
	}
	printf("\n========================================= Node %d DELETED ===============================\n", location_copy);
}

// CHECK IF EMPTY NODE ================================================================================

unsigned int isEmptyNode(unsigned int location, LinkedList* const list_start_address) {

	LinkedList* current_node = get_address(location, list_start_address);
	if ( (current_node->string==NULL) || !strcmp(*current_node->string, "") ){
		printf("String Location %d is empty!\n", location);
		return 0;
	} else {
		printf("String Location %d is NOT empty!\n", location);
		return 1;
	}
}

// DISPLAY ALL NODES ==================================================================================

void printNodes(LinkedList* list_start_address) {
	unsigned int size = list_size(list_start_address);
	LinkedList* current_node = list_start_address;

	if (list_start_address!=NULL) {
		for (unsigned int i = 0; i<size; i++ ) {
			printf("%s\n", *current_node->string );
			printf("Next Address is: %d\n", current_node->nodePtr);
			current_node=current_node->nodePtr;
		}
	}
	else
		printf("End of nodes.\n");
}

// MAIN FUNCTION ======================================================================================

int main(void) {

	//Initialization
	LinkedList* list1 = NULL;

	addNode(0, "Test A", &list1);
	addNode(1, "Test B", &list1);
	addNode(2, "Test C", &list1);
	addNode(3, "Test D", &list1);
	addNode(4, "TEST E", &list1);
	addNode(5, "", &list1);
	addNode(10, "TEST F", &list1);

	puts("\n======================================== ALL NODES ADDED =============================================");
	printNodes(list1);
	deleteNode(0, &list1);
	printNodes(list1);
	deleteNode(1, &list1);
	printNodes(list1);

	puts("\n======================================== CHECK IF EMPTY =============================================");
	isEmptyNode(3, list1);
	isEmptyNode(1, list1);

	return 0;
}

// END =========================================================================================
