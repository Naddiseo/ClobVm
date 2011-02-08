/*
 * StringType.cpp
 *
 * Copyright (C) 2011 richard
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.
 *  Created on: 2011-02-06
 *      Author: richard
 */

#include "StringType.h"

StringType::StringType() {
	type  = ObjectType_t::STRING;
	value = "";
}

StringType::StringType(std::string _s) {
	type  = ObjectType_t::STRING;
	value = _s;
}

StringType::~StringType() {}

void
StringType::print() {
	//LOG("STRING(\"%s\")\n", value.c_str());
	std::cout << value;
}
