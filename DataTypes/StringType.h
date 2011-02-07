/*
 * StringType.h
 *
 * Copyright (C) 2011 richard
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.
 *  Created on: 2011-02-06
 *      Author: richard
 */
#pragma once
#include <DataTypes/TypedObject.h>
#include <string>

#define strpcast(x) std::dynamic_pointer_cast<StringType>(x)
#define strcast(x) (*strpcast(x))

class StringType : public TypedObject<std::string> {
public:
	StringType();
	StringType(std::string _s);
	virtual ~StringType();

	void print();
};

