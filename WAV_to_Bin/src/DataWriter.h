/*
 * DataWrite.h
 *
 *  Created on: Mar 26, 2018
 *      Author: Administrator
 */

#ifndef DATAWRITER_H_
#define DATAWRITER_H_

#include "header.h"
#include "footer.h"
#include <cstdint>
using namespace std;

const uint8_t HEADER_SIZE = 44;

class DataWriter {
	private:
		string wavFile;
		string binFile;
		string txtFile;
	public:
		DataWriter(string file_location);
		bool WriteAudioDataToBinFile(uint32_t BinDataSize);
};



#endif /* DATAWRITER_H_ */
