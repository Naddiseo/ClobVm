/*
 * Opcodes.hpp
 *
 * Copyright (C) 2011 richard
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.
 *  Created on: 2011-02-03
 *      Author: richard
 */
#pragma once

enum Opcode {
	NOP = 1,
	LOADI, // LOAD INT onto stack

	PRINT,

	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,


	BEGINCLASS,
	ENDCLASS,
	LOADCLASS,
};
