/*
 *  BO_Timer.h
 *  BO
 *
 *  Created by Daniel Lindfors on 5/27/12.
 *  Copyright 2012 KTH. All rights reserved.
 *
 */

#ifndef BO_TIMER_H
#define BO_TIMER_H

using namespace std;

class BO_Timer {
private:
	Uint32 start_ticks;
	Uint32 time; 
	Uint8 timerstate; // 0 stoped, 1 paused, 2 running
	Uint32 countdown;
	
public:
	BO_Timer() ;
	void start(Uint32 count);	//also resets or resumes when timer is running or paused		
	void stop();
	void pause();			
	Uint32 getTicks();	
	
	bool isPaused();			
	bool isRunning();
	bool isStoped();
	
	bool timeUp();
};




// needs polishing
class BO_FpsRegulator {
private:
	BO_Timer time;
	BO_Timer real_time;
	Uint32 msec_per_frame;
	int framecount;
	Uint32 time_sum;
public:
	BO_FpsRegulator(Uint32 fps);
	void setFps(Uint32 fps);			
	void reset(); 			
	void stop(); 
	void getFps(Uint32 interval, double* fps);			
	void regulateFps();			
};






#endif