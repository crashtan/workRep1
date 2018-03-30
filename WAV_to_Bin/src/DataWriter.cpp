/*
 * DataWriter.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: Administrator
 */
#include "DataWriter.h"

DataWriter::DataWriter(string file_input)
{
	wavFile = file_input;
	binFile = file_input+".bin";
	txtFile = file_input+".txt";
}

bool DataWriter::WriteAudioDataToBinFile(uint32_t BinDataSize) {

	if (BinDataSize == 0) {
		cout << "DataWriter::WARNING: Audio Data Size is ZERO!" << endl;
		return true;
	}

	// INPUT FILE OPEN
	ifstream fptr_input(wavFile, ios::in | ios::binary);
    if (!fptr_input.is_open()) {
		cout << "DataWriter::ERROR: Problem READING file at given location" << endl;
		fptr_input.close();
		return false;
	}
    fptr_input.seekg(HEADER_SIZE, fptr_input.beg);


	//OUTPUT FILE OPEN
	ofstream fptr_output(binFile, ios::out | ios::binary);
    if (!fptr_output.is_open()) {
		cout << "DataWriter::ERROR: Problem WRITING DATA file at given location" << endl;
		fptr_output.close();
		return false;
	}

	//OUTPUT TXT FILE OPEN
	ofstream fptr_output_values(txtFile, ios::out);
    if (!fptr_output_values.is_open()) {
		cout << "DataWriter::ERROR: Problem WRITING TXT file at given location" << endl;
		fptr_output_values.close();
		return false;
	}
    fptr_output_values << "{";

	// WRITE BIN AUDIO DATA TO FILE
	int count_read = 0;
	char dataByte = 0;

	//int16_t _16Bit = 0;

	cout<< "...WRITING...please wait..." << endl;

	for (uint32_t i=0; i<BinDataSize; i++) {
		//READ
		fptr_input.read(&dataByte, 1);
		count_read = fptr_input.gcount();

		if (count_read <= 0) {
			cout << "DataWriter::ERROR: Problem reading input file data" << endl;
			fptr_input.close();
			fptr_output.close();
			return false;
		} else {
			//WRITE
			fptr_output.write(&dataByte, 1);

			//WRITE TXT FILE OUTPUT, 16bit
			if (i<(4096*5)) {
				//================================================
				// Signed 16_bit output
				//================================================
//				if ((i%2) == 0) {
//					_16Bit = (int16_t)dataByte;
//				} else {
//					_16Bit |= (int16_t)(((uint8_t)dataByte)<<8);
//
//				if (i != (4096*5)-1) {
//						fptr_output_values << (int)_16Bit << ", ";
//					} else {
//						fptr_output_values << (int)_16Bit << "};";
//					}
//				}

				//================================================
				// Signed 8_bit output
				//================================================
				if (i != (4096*5)-1) {
					fptr_output_values << (int)dataByte << ", ";
				} else {
					fptr_output_values << (int)dataByte << "};" << endl;
					fptr_output_values << "DataLength is: " << i+1;
				}
				//================================================
			}

		}
	}
	fptr_output_values.close();

	fptr_input.close();
	fptr_output.close();
	cout << "Completed File Write" << endl;
	return true;
}

