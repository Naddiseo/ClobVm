/*
 * ObjectType.h
 *
 * Copyright (C) 2011 richard
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.
 *  Created on: 2011-02-06
 *      Author: richard
 */
#pragma once
#include <DataTypes/BaseObject.h>

#define OBJECT_PCAST(x) std::dynamic_pointer_cast<ObjectType>(x)
#define OBJECT_CAST(x) (*OBJECT_PCAST(x))
#define objcast cast<ObjectType>

class ObjectType : public BaseObject {
public:
	ObjectType();
	virtual ~ObjectType();
};

