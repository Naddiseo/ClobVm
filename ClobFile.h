/*
 * ClobFile.h
 *
 * Copyright (C) 2011 richard
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.
 *  Created on: 2011-02-06
 *      Author: richard
 */
#pragma once
#include <vector>
#include <string>
#include <Instruction.h>

struct DataEntry_t {
	unsigned long length;
	std::string   string;
};

typedef std::vector<DataEntry_t> DataEntries_t;
typedef std::vector<Instruction> Instructions;
typedef std::vector<std::string> strings_t;
class ClobFile {
public:
	unsigned long dataSize;
	unsigned long instructionSize;
	DataEntries_t   data;
	Instructions   instructions;

	ClobFile(std::string _path) : path(_path) {}
	ClobFile(std::string _path, Instructions _instructions, strings_t _data);
	bool load();
	bool save();
	virtual ~ClobFile();
private:
	std::string path;
};

