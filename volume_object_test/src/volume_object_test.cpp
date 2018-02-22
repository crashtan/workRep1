//============================================================================
// Name        : volume_object_test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "BoxVolume.h"
#include <iostream>
using namespace std;
using namespace volumes;

int main() {

	BoxVolume box;

	unsigned int box_volume = box.getVolume();
	cout << "The volume is "<< box_volume << endl;

	box.setVolume(2,3,4);
	box_volume = box.getVolume();
	cout << "The volume is "<< box_volume << endl;

	cout << "Program End" << endl;
	return 0;
}
