/*
 *  BO_SystemCORE.h
 *  BO
 *
 *  Created by Daniel Lindfors on 6/8/12.
 *  Copyright 2012 KTH. All rights reserved.
 *
 */



#ifndef BO_SYSTEMCORE_H
#define BO_SYSTEMCORE_H

#include <vector.h>

using namespace std;





class BO_ProcessManager {
private:
	vector<void(*)()> processes;  //vector of function pointers
	
public:
	BO_ProcessManager();
	~BO_ProcessManager();
	
	bool process();
	int push(void(*function)() );
	bool popAll();
	bool pop(int element);
	bool pop();
	bool pop(void(*)());
	bool isInProcesses(void(*)());
};





struct BO_State {
	void (*stateInitializer)();
	int state;
};


class BO_StateManager {
private:
	vector<BO_State> states;
	
public:
	BO_StateManager();
	~BO_StateManager();
	
	int push(BO_State);
	bool pop();
	bool popAll();
	int currentState();
	
};






class BO_App {
protected:
	int Width, Height;
	int bpp;
	bool fullscreen;
	SDL_Surface* screen;
	Uint32 windowInitFlags;
	string windowName;
	
public:
	BO_App();
	virtual ~BO_App() = 0;
	
	virtual bool initialize() = 0;
	virtual void run() = 0;
	virtual void shutDown() = 0;
	virtual bool resizeWindow(int width, int height) = 0;
	virtual bool togleFullscreen() = 0;
};


#endif