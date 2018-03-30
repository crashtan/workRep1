/*
 * header.h
 *
 *  Created on: Mar 23, 2018
 *      Author: Administrator
 */

#ifndef HEADER_H_
#define HEADER_H_

#include <cstdint>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

enum endianess {
	big,
	little
};

const uint8_t HEADER_TOTAL_BYTES = 44;
const uint8_t HEADER_CHUNK_READ_LENGTHS[] = {4, 4, 4, 4, 4, 2, 2, 4, 4, 2, 2, 4, 4};
const uint8_t HEADER_CHUNK_LOCATIONS[] = {0, 4, 8, 12, 16, 20, 22, 24, 28, 32, 34, 36, 40};
const uint8_t HEADER_CHUNK_ENDIANESS[] = {big, little, big, big, little, little, little, little, little, little, little, big, little};
const string HEADER_CHUNK_LABELS[] = {"ChunkID", "ChunkSize", "Format", "Subchunk1ID", "SubChunk1Size", "AudioFormat", "NumChannels", "SampleRate", "ByteRate", "BlockAlign", "BitsPerSample", "SubChunk2ID", "SubChunk2Size"};
const uint8_t HEADER_NO_OF_CHUNKS = 13;
const uint8_t HEADER_MAX_CHUNK_SIZE = 4;

class Header {

	private:
		char header_array[HEADER_TOTAL_BYTES];
		string wavFile;
		uint32_t dataSize;

		bool HeaderRead();

	public:
		Header(string file_input);

		bool GetHeader();
		void GetChunk(uint8_t chunk_number);
		void DisplayHeader();
		uint32_t GetDataSizeValue();
};

#endif /* HEADER_H_ */
