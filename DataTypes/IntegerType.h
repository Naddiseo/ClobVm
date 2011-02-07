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

#define intpcast(x) std::dynamic_pointer_cast<IntegerType>(x)
#define intcast(x) (*intpcast(x))

class IntegerType : public TypedObject<long> {
public:
	IntegerType();
	IntegerType(long _l);
	virtual ~IntegerType();

	pObject operator+(const IntegerType& rhs);
	pObject operator-(const IntegerType& rhs);
	pObject operator*(const IntegerType& rhs);
	pObject operator/(const IntegerType& rhs);
		
	
	void print();
};



