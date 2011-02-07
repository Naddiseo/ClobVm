/*
 * main.cpp
 *
 * Copyright (C) 2011 richard
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.
 *  Created on: 2011-02-03
 *      Author: richard
 */
#include <common.h>
#include <iostream>

#include <ClobFile.h>
#include <Instruction.h>
#include <DataTypes/BaseObject.h>
#include <DataTypes/IntegerType.h>
#include <DataTypes/StringType.h>


int
main() {
	mObject objects;
	objects.reserve(10);
	Instruction test[] = {};
	const char* data[] = {};

	const char* filename = getenv("SCRIPT_FILENAME");

	//std::cout <<"Content-type: text/html\n\n";
	//std::cout <<"You requested: " << filename << std::endl;
	ClobFile f(filename);
	f.load();


	for (Instruction& c: f.instructions) {
		//c.print();
		switch (c.op) {
		case LOADI:
			objects[c.arg1] = pObject(new IntegerType(c.arg2));

			break;
		case LOADS:
			//XXX broken
			objects[c.arg1] = pObject(new StringType(f.data[c.arg2].string));

			break;
		case ADD:
			objects[c.arg1] = intcast(objects[c.arg2]) + intcast(objects[c.arg3]);

			break;
		case SUBTRACT:
			objects[c.arg1] = intcast(objects[c.arg2]) - intcast(objects[c.arg3]);

			break;
		case MULTIPLY:
			objects[c.arg1] = intcast(objects[c.arg2]) * intcast(objects[c.arg3]);

			break;
		case DIVIDE:
			objects[c.arg1] = intcast(objects[c.arg2]) / intcast(objects[c.arg3]);

			break;
		case PRINT:
			objects[c.arg1]->print();

			break;
		default:
		case NOP:
			break;
		}
	}

	//std::cout << "Objects.size = " << objects.size() << std::endl;

	return 0;
}
