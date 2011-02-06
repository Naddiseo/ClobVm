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

#include <Instruction.h>
#include <DataTypes/BaseObject.h>
#include <DataTypes/IntegerType.h>

static Instruction test[] = {
		{NOP,   1, 0},
		{LOADI, 1, 1000},
		{LOADI, 2, 1000},
		{ADD, 3, 1, 2},
		{PRINT, 3}
};



int
main() {
	mObject objects;
	objects.reserve(10);

	for (Instruction& c: test) {
		c.print();
		switch (c.op) {
		case LOADI: {
			objects[c.arg1] = pObject(new IntegerType(c.arg2));
		}
			break;
		case ADD: {
			objects[c.arg1] = *INTEGER_CAST(objects[c.arg2]) + *INTEGER_CAST(objects[c.arg3]);
		}
			break;
		case PRINT: {
			objects[c.arg1]->print();
		}
			break;
		default:
		case NOP:
			break;
		}
	}

	std::cout << "Objects.size = " << objects.size() << std::endl;

	return 0;
}
