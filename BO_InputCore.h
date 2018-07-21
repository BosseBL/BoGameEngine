/*
 *  BO_InputCORE.h
 *  BO
 *
 *  Created by Daniel Lindfors on 6/8/12.
 *  Copyright 2012 KTH. All rights reserved.
 *
 */

#ifndef BO_INPUTCORE_H
#define BO_INPUTCORE_H

#include <map.h>

using namespace std;

struct BO_InputEvent {
	int eventID;
	Uint8 eventType;
	Uint8 eventKey;
	void(*action)()
};


class BO_InputManager {
private:
	map<int, BO_InputEvent> eventBindings;
	
public:
	void setNewEventBinging(int eventID, uint8 eventType, Uint8 eventKey, void(*)func() );
	void changeAction(int eventID, void(*func)() );
	
	
	void handleEvents();
	
	
};



#endif