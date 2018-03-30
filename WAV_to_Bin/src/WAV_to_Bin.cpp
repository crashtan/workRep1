//============================================================================
// Name        : WAV_to_Bin.cpp
// Author      : jmanzoor
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

//#include "Footer.h"
#include "Header.h"
#include "DataWriter.h"

int main(int argc, char** argv)
{
//	string file_location = "";
//	if (argc != 2) {
//		cout << "Enter 2 arguments: <PROGRAM> <FILE_PATH>" << endl;
//		return 0;
//	} else {
//		file_location = argv[1];
//        cout << "File name is: " << file_location << endl;
//	}

	uint32_t size = 0;
	//string file_location_test3 = "Roland-JV-2080-PizzicatoStr-C5.wav";
	string file_location_test2 = "futurebells_beat.wav";

	//Read Header
	Header wavHeader(file_location_test2);
	bool header_check = wavHeader.GetHeader();
	if(header_check){
		wavHeader.DisplayHeader();
	} else {
		exit(-1);
	}
	// Display Header updates dataSize member
	size = wavHeader.GetDataSizeValue();

	//Write audio .wav Data to binary file
	DataWriter Audio(file_location_test2);
	Audio.WriteAudioDataToBinFile(size);

	//Display footer
	exit(0);
}
