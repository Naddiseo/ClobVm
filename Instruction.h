/*
 * Instruction.h
 *
 * Copyright (C) 2011 richard
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.
 *  Created on: 2011-02-03
 *      Author: richard
 */
#pragma once
#include <Opcodes.hpp>
class Instruction {
public:
	Opcode op;
	unsigned int arg1;
	unsigned int arg2;
	unsigned int arg3;

	Instruction();
	Instruction(Opcode _o) : op(_o), arg1(0), arg2(0), arg3(0) {};
	Instruction(Opcode _o, unsigned int _a1) : op(_o), arg1(_a1), arg2(0), arg3(0) {};
	Instruction(Opcode _o, unsigned int _a1, unsigned int _a2) : op(_o), arg1(_a1), arg2(_a2), arg3(0) {};
	Instruction(Opcode _o, unsigned int _a1, unsigned int _a2, unsigned int _a3) : op(_o), arg1(_a1), arg2(_a2), arg3(_a3) {};
	~Instruction();

	void print();

};

