/*
 * Instruction.cpp
 *
 * Copyright (C) 2011 richard
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.
 *  Created on: 2011-02-03
 *      Author: richard
 */

#include "Instruction.h"
#include <iostream>
#include <common.h>

Instruction::Instruction() {}
Instruction::~Instruction() {}

void Instruction::print() {
	LOG("%i (%i, %i, %i)\n", op, arg1, arg2, arg3);
}
