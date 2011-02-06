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
#include <iostream>
#include <Instruction.h>
#define SIZE 4
#define NREGS 4
static long registers[4] = {0,0,0,0};

static const Instruction test[SIZE] = {
		{NOP,   0, 0, 0},
		{LOADI, 0, 0, 100},
		{LOADI, 1, 0, 100},
		{ADD,   0, 1, 10000}
};

int getReg(int reg) {
	if (reg < 0) return 0;
	if (reg > NREGS) return NREGS;
	return reg;
}

int
main() {

	for (int i = 0; i < SIZE; i++) {
		Instruction c = test[i];

		switch (c.op) {
		case LOADI:
			registers[getReg(c.reg1)] = c.addr;
			break;
		case ADD:
			registers[getReg(c.reg1)] += registers[getReg(c.reg2)];
			break;
		default:
		case NOP:
			break;
		}
	}

	for (int i = 0; i < NREGS; i++) {
		std::cout << "Reg: " << i << " = " << registers[i] << std::endl;
	}

	return 0;
}
