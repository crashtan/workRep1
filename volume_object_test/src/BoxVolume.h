/*
 * BoxVolume.h
 *
 *  Created on: Feb 22, 2018
 *      Author: Administrator
 */

#ifndef BOXVOLUME_H_
#define BOXVOLUME_H_

namespace volumes {

class BoxVolume {
public:
	BoxVolume(int a=1, int b=1, int c=1);

	virtual ~BoxVolume();
	void setVolume(int a, int b, int c);
	unsigned int getVolume();
private:
	unsigned int height;
	unsigned int width;
	unsigned int base;
};

} /* namespace volumes */

#endif /* BOXVOLUME_H_ */
