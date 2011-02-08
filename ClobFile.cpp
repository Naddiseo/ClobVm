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
#include <iostream>

#include <common.h>

ClobFile::ClobFile(std::string _path, Instructions _instructions, strings_t _data) {
	path = _path;
	instructions = _instructions;

	header = {0, _instructions.size(), _data.size()};

	for (auto _d : _data) {
		DataEntry_t entry;
		entry.string = _d;
		entry.length = entry.string.size();
		data.push_back(entry);
	}
}

ClobFile::~ClobFile() {}

bool
ClobFile::load() {
	if (path.size() == 0) return false;

	std::fstream file(path, std::ios::in | std::ios::binary);
	file.read(reinterpret_cast<char*>(&header), sizeof(ClobFileHeader_t));
	LOG("Read header, got %i data, %i instructions", header.dataCount, header.instructionCount);

	for (int i = 0; i < header.dataCount; i++) {
		DataEntry_t entry;
		file.read(reinterpret_cast<char*>(&entry.length), sizeof(unsigned long));

		char* buffer = new char[entry.length];
		if (!buffer) {
			return false;
		}
		file.read(buffer, entry.length);
		entry.string = buffer;
		delete[] buffer;
		LOG("Reading string[%i==%i](\"%s\")\n", entry.string.size(), entry.length, entry.string.c_str());
		data.push_back(entry);
	}


	LOG("Reading %i instructions\n", header.instructionCount);
	for (int i = 0; i < header.instructionCount; i++) {
		Instruction instr;
		file.read(reinterpret_cast<char*>(&instr), sizeof(Instruction));
		instr.print();
		instructions.push_back(instr);
	}

	return true;
}

bool ClobFile::save() {
	if (path.size() == 0) return false;
	std::fstream file(path, std::ios::out | std::ios::binary);

	file.write(reinterpret_cast<char*>(&header), sizeof(ClobFileHeader_t));
	LOG("Saved header, got %i data, %i instructions", header.dataCount, header.instructionCount);

	for (DataEntry_t& entry : data) {
		entry.length = entry.string.size();
		file.write(reinterpret_cast<char*>(&entry.length), sizeof(unsigned long));
		file.write(entry.string.c_str(), entry.string.size());
		LOG("Saving string[%i==%i](\"%s\")\n", entry.string.size(), entry.length, entry.string.c_str());
	}

	LOG("Writing %i instructions\n", header.instructionCount);
	for (Instruction& instr : instructions) {
		instr.print();
		file.write(reinterpret_cast<char*>(&instr), sizeof(Instruction));
	}

	file.close();

	return true;
}
