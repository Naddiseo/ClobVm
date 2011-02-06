/*
 * common.h
 *
 * Copyright (C) 2011 richard
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.
 *  Created on: 2011-02-05
 *      Author: richard
 */
#pragma once
#ifndef __GXX_EXPERIMENTAL_CXX0X__
#	define __GXX_EXPERIMENTAL_CXX0X__
#endif

#include <string>
#include <unordered_map>
#include <memory>

class BaseObject;

typedef std::shared_ptr<BaseObject> pObject;
typedef std::unordered_map<unsigned int, pObject> mObject;

#ifdef DEBUG
#	include <cstdio>
#	define LOG(fmt, ...) fprintf(stderr, "[%s:%i]" fmt, __FILE__, __LINE__, __VA_ARGS__);
#else
#	define LOG(...)
#endif

