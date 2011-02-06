/*
 * IntegerType.h
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

#define INTEGER_CAST(x) std::dynamic_pointer_cast<IntegerType>(x)

class IntegerType : public TypedObject<long> {
public:
	IntegerType();
	IntegerType(long _l);
	virtual ~IntegerType();

	pObject operator+(IntegerType& rhs);

	void print();
};



