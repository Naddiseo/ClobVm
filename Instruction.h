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
	unsigned char reg1;
	unsigned char reg2;
	long          addr;

	Instruction(Opcode _o, unsigned char _r1, unsigned char _r2, long _a)
		: op(_o), reg1(_r1), reg2(_r2), addr(_a) {}
	Instruction();
	virtual ~Instruction();
};

