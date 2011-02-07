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
		{LOADI, 2, 2000},
		{ADD, 3, 1, 2},
		{SUBTRACT, 4, 2, 1},
		{MULTIPLY, 5, 1, 2},
		{DIVIDE, 6, 2, 1},
		{PRINT, 3},
		{PRINT, 4},
		{PRINT, 5},
		{PRINT, 6},
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
			objects[c.arg1] = objects[c.arg2]->intcast() + objects[c.arg3]->intcast();
		}
			break;
		case SUBTRACT: {
			objects[c.arg1] = objects[c.arg2]->intcast() - objects[c.arg3]->intcast();
		}
			break;
		case MULTIPLY: {
			objects[c.arg1] = objects[c.arg2]->intcast() * objects[c.arg3]->intcast();
		}
			break;
		case DIVIDE: {
			objects[c.arg1] = objects[c.arg2]->intcast() / objects[c.arg3]->intcast();
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
