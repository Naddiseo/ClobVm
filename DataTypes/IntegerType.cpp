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

pObject
IntegerType::operator+(IntegerType& rhs) {
	pObject ret(new IntegerType());

	INTEGER_CAST(ret)->setValue(this->getValue() + rhs.getValue());

	return ret;
}

void
IntegerType::print() {
	LOG("Integer(%d)\n", value);
}
