/*
 * IntegerType.cpp
 *
 * Copyright (C) 2011 richard
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.
 *  Created on: 2011-02-06
 *      Author: richard
 */

#include "IntegerType.h"
#include <iostream>

IntegerType::IntegerType() {
	type  = INTEGER;
	value = 0;
}

IntegerType::IntegerType(long _l) {
	type  = INTEGER;
	value = _l;
}

IntegerType::~IntegerType() {
	// TODO Auto-generated destructor stub
}

IntegerType*
IntegerType::operator+(IntegerType& rhs) {
	IntegerType* ret = new IntegerType();

	ret->setValue(this->getValue() + rhs.getValue());

	return ret;
}

void
IntegerType::print() {
	std::cout << "Integer (" << value << ")\n";
}
