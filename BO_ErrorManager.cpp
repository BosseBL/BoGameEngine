/*
 *  BO_Error.cpp
 *  BO
 *
 *  Created by Daniel Lindfors on 5/27/12.
 *  Copyright 2012 KTH. All rights reserved.
 *
 */

#include "BO_ErrorManager.h"



	BO_Exception::BO_Exception(string what, int type) 
	:description(what), error_type(type)
	{}

	BO_Exception::BO_Exception(int type) 
	: description(""), error_type(type)
	{}

	BO_Exception::BO_Exception(string what) 
	:description(what), error_type(BO_UNKNOWN_EXCEPTION)
	{}
	
	BO_Exception::~BO_Exception() throw() {}
	
	const char* BO_Exception::what() const throw() {
		return description.c_str();
	}


	int BO_Exception::type() {
		return error_type;
	}