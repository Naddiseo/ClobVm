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

vObject objects;

void add(int pos, BaseObject* o) {
	if (pos >= objects.size()) {
		objects.resize(static_cast<int>(pos * 1.5));
	}else {
		BaseObject* current = objects[pos];
		if (current) {
			delete current;
		}
	}
	objects[pos] = o;
}


int
main() {
	objects.reserve(10);

	for (Instruction& c: test) {
		c.print();
		switch (c.op) {
		case LOADI: {
			add(c.arg1, new IntegerType(c.arg2));
		}
			break;
		case ADD: {
			add(c.arg1, *INTEGER_CAST(objects[c.arg2]) + *INTEGER_CAST(objects[c.arg3]));
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

	for (BaseObject*& o: objects) {
		std::cout << "Freeing " << o->id <<std::endl;
		if (o->id) {
			delete o;
		}
	}

	return 0;
}
