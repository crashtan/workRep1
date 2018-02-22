/*
 * BoxVolume.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: Administrator
 */

#include "BoxVolume.h"

namespace volumes {

BoxVolume::BoxVolume(int a, int b, int c) {
	// TODO Auto-generated constructor stub
	this->height = a;
	this->width = b;
	this->base= c;
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
}

} /* namespace volumes */
