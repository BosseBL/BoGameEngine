/*
 *  BO_ErrorManager.h
 *  BO
 *
 *  Created by Daniel Lindfors on 5/27/12.
 *  Copyright 2012 KTH. All rights reserved.
 *
 */

#ifndef BO_ERRORMANAGER_H
#define BO_ERRORMANAGER_H

#include <stdlib.h>
#include <string>

using namespace std;

#define BO_UNKNOWN_EXCEPTION 0
#define BO_MISSING_FILE_EXCEPTION 2
#define BO_OUT_OF_BOUND_EXCEPTION 3
#define BO_BLIT_FALIURE_EXCEPTION 4
#define BO_BAD_STATE_EXCEPTION 5


class BO_Exception : public exception {
private:
	int error_type;
	string description;
	
public:
	BO_Exception(string what, int type);
	BO_Exception(int type);
	BO_Exception(string what);
	
	~BO_Exception() throw();
	
	const char* what() const throw();
	int type();
};


#endif