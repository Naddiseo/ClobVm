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
#include <typeinfo>

Instruction::Instruction() {}
Instruction::~Instruction() {}

void Instruction::print() {
	std::cout << op << " (" << arg1 << ", " << arg2 << ", " << arg3 << ")\n";
}
