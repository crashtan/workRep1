/*
 * header.cpp
 *
 *  Created on: Mar 23, 2018
 *      Author: Administrator
 */


#include "Header.h"

Header::Header(string file_input)
{
	wavFile = file_input;
	dataSize = 0;

	for (uint8_t item: header_array) {
		header_array[item] = 0;
	}
}

bool Header::HeaderRead() {

    fstream ifs(wavFile, ios::in | ios::binary);

    if (ifs.is_open()) {
    	ifs.seekg(0, ifs.beg);

    	ifs.read(header_array, HEADER_TOTAL_BYTES);
    	size_t count = ifs.gcount();

    	if (count == 0 || count != HEADER_TOTAL_BYTES) {
    		cout << "Header::ERROR: Problem reading wav header" << endl;
    		ifs.close();
    		return false;
    	}
    	ifs.close();
    	return true;
	} else {
		cout << "Header::ERROR: Problem reading file at given location" << endl;
		ifs.close();
	}
    return false;
}


bool Header::GetHeader() {
	return Header::HeaderRead();
}

void Header::GetChunk(uint8_t chunk_number) {
	cout << setw(15) << HEADER_CHUNK_LABELS[chunk_number] << ": ";
	uint32_t value = 0x00;

	if (HEADER_CHUNK_ENDIANESS[chunk_number] == little) {
		// Display little endian

		for (uint8_t j=0; j<HEADER_CHUNK_READ_LENGTHS[chunk_number]; j++) {
			value += ( ((uint8_t)header_array[HEADER_CHUNK_LOCATIONS[chunk_number]+j]) << (j*8));
		}
		cout << value << endl;

	} else {
		// Display big endian
		for (uint8_t j=0; j<HEADER_CHUNK_READ_LENGTHS[chunk_number]; j++) {
			cout << header_array[HEADER_CHUNK_LOCATIONS[chunk_number]+j];
		}
		cout << endl;
	}
	// Store Audio Data Size value in member variable
	if (chunk_number==12) {
		dataSize = value;
	}
}

uint32_t Header::GetDataSizeValue () {
	return dataSize;
}


void Header::DisplayHeader() {

	for (uint8_t i=0; i<HEADER_NO_OF_CHUNKS; i++) {
		Header::GetChunk(i);
	}
}
