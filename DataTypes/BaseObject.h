/*
 * Object.h
 *
 * Copyright (C) 2011 richard
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.
 *  Created on: 2011-02-05
 *      Author: richard
 */
#pragma once
#include <common.h>


enum ObjectType_t {
	INTEGER = 1,
	LONG,
	BOOLEAN,
	FLOAT,
	STRING,
	OBJECT,
	FUNCTION,
	LIST,
};


class BaseObject {
public:
	static unsigned int idCount;
	unsigned int id;
	std::string  name;
	ObjectType_t   type;

	virtual void print() {};

	BaseObject();
	virtual ~BaseObject();
};
