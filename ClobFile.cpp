/*
 * ClobFile.cpp
 *
 * Copyright (C) 2011 richard
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.
 *  Created on: 2011-02-06
 *      Author: richard
 */

#include "ClobFile.h"
#include <fstream>
#include <string>

ClobFile::ClobFile(std::string _path, Instructions _instructions, strings_t _data) {
	path = _path;
	instructions = _instructions;


	for (auto _d : _data) {
		DataEntry_t entry;
		entry.string = _d;
		entry.length = entry.string.size();
	}
}

ClobFile::~ClobFile() {}

bool
ClobFile::load() {
	if (path.size() == 0) return false;

	std::ifstream file(path);
	file.read((char*)&dataSize, sizeof(dataSize));
	file.read((char*)&instructionSize, sizeof(instructionSize));

	// Make sure it's not some ridiculous size
	if (dataSize > 100) {
		dataSize = 100; // for now..
	}

	for (int i = 0; i < dataSize; i++) {
		DataEntry_t entry;
		file.read((char*)&entry.length, sizeof(entry.length));
		char* buffer = new char[entry.length];
		file.read(buffer, entry.length);
		entry.string = buffer;
		delete[] buffer;

		data.push_back(entry);
	}

	// Make sure it's not some ridiculous size
	if (instructionSize > 100) {
		instructionSize = 100; // for now..
	}

	for (int i = 0; i < instructionSize; i++) {
		Instruction instr;
		file.read((char*)&instr, sizeof(Instruction));
		instructions.push_back(instr);
	}

	return true;
}

bool ClobFile::save() {
	if (path.size() == 0) return false;
	std::ofstream file(path);
	dataSize        = data.size();
	instructionSize = instructions.size();

	file.write((char*)&dataSize, sizeof(dataSize));
	file.write((char*)&instructionSize, sizeof(instructionSize));

	for (DataEntry_t& entry : data) {
		entry.length = entry.string.size();
		file.write((char*)&entry.length, sizeof(entry.length));
		file.write(entry.string.c_str(), entry.string.size());
	}

	for (Instruction& instr : instructions) {
		file.write((char*)&instr, sizeof(Instruction));
	}

	file.close();

	return true;
}
