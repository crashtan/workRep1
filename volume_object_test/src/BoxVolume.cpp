/*
 * BoxVolume.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: Administrator
 */

#include "BoxVolume.h"
#include <iostream>
using namespace std;

namespace volumes {

	unsigned int BoxVolume::count = 0;

	BoxVolume::BoxVolume(int a, int b, int c) {
		// TODO Auto-generated constructor stub
		this->height = a;
		this->width = b;
		this->base= c;

		count++;
		cout << "BoxVolume " << count <<" is born" << endl;
	}

	void BoxVolume::setVolume(int a, int b, int c) {
		this->height = a;
		this->width = b;
		this->base= c;
	}

	unsigned int BoxVolume::getVolume() {
		return height*width*base;
	}

	BoxVolume::~BoxVolume() {
		// TODO Auto-generated destructor stub
		cout << "A BoxVolume died" << endl;
		cout << "No of boxes are " << --count <<"."<< endl;
	}

} /* namespace volumes */
