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
#include <string>

class Object {
public:
	std::string name;

	Object();
	virtual ~Object();
};

