/*
 * testcomp.cpp
 *
 * Copyright (C) 2011 richard
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.
 *  Created on: 2011-02-06
 *      Author: richard
 */

#include <ClobFile.h>
#include <vector>

static strings_t data = {
		"Content-Type: text/html\n\n",
		"<html><body>Hello from within Clob VM File</body><html>\n"
};

static Instructions test = {
		{LOADS, 1, 0},
		{LOADS, 2, 1},
		{PRINT, 1},
		{PRINT, 2},
		/*{NOP,   1, 0},
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
		 */
};


int main() {
	ClobFile f("test.clobcc", test, data);
	f.save();

	ClobFile f2("test.clobcc");
	f2.load();

	return 0;
}
