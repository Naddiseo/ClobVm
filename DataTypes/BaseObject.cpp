/*
 * Object.cpp
 *
 * Copyright (C) 2011 richard
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.
 *  Created on: 2011-02-05
 *      Author: richard
 */

#include "DataTypes/BaseObject.h"

unsigned int BaseObject::idCount = 0;

BaseObject::BaseObject() { id = ++idCount; }
BaseObject::~BaseObject() {
	//LOG("Destroying Object %d of %d\n", id, idCount);
}
