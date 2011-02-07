/*
 * TypedObject.h
 *
 * Copyright (C) 2011 richard
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.
 *  Created on: 2011-02-06
 *      Author: richard
 */
#pragma once

#include "DataTypes/BaseObject.h"

// can't put cast in here
template<class T>
class TypedObject: public BaseObject {
public:
	T value;

	T    getValue() const { return value; }
	void setValue(T _v) { value = _v; }

	TypedObject();
	virtual ~TypedObject();
};

template<class T>
TypedObject<T>::TypedObject()  {
	// TODO Auto-generated constructor stub

}

template<class T>
TypedObject<T>::~TypedObject() {
	// TODO Auto-generated destructor stub
}
