/*
 *  BO_Timer.cpp
 *  BO
 *
 *  Created by Daniel Lindfors on 5/27/12.
 *  Copyright 2012 KTH. All rights reserved.
 *
 */

#include "BO_Timer.h"
#include "BO_ErrorManager.h"
#include "functions.h"

BO_Timer::BO_Timer() 
:start_ticks(0), time(0), timerstate(0) {}
void BO_Timer:: start(Uint32 count) {
	
	countdown = count;
	
	switch (timerstate) {
		case 0:
			time = 0;
			start_ticks = SDL_GetTicks();
			timerstate = 2;
			break;
		case 1:
			start_ticks = SDL_GetTicks();
			timerstate = 2;
			break;
		case 2:
			start_ticks = SDL_GetTicks();
			time = 0;
			break;
		default:
			throw BO_Exception("BO_Timer reach default state in start()", BO_BAD_STATE_EXCEPTION);
			break;
	}
}

void BO_Timer::stop() {
	switch (timerstate) {
		case 0:
			throw BO_Exception("BO_Timer called stop() while already stoped", BO_BAD_STATE_EXCEPTION );
			break;
		case 1:
			timerstate = 0;
			break;
		case 2:
			time += SDL_GetTicks() - start_ticks;
			timerstate = 0;
			break;
		default:
			break;
	}
}

void BO_Timer::pause() {
	switch (timerstate) {
		case 0:
			throw BO_Exception("BO_Timer called pause() while the state was 'stoped' ", BO_BAD_STATE_EXCEPTION);
			break;
		case 1:
			cerr<<"timer's already paused";
			break;
		case 2:
			time += SDL_GetTicks() - start_ticks;
			timerstate = 1;
			break;
		default:
			cerr<<"no such state: " << timerstate;
			break;
	}
}

Uint32 BO_Timer::getTicks() {
	switch (timerstate) {
		case 0: case 1:
			return time;
			break;
		case 2:
			return time + (SDL_GetTicks() - start_ticks);
			break;
		default:
			throw BO_Exception("BO_Timer -> getTicks() while in state" + toString(timerstate), BO_BAD_STATE_EXCEPTION);
			return 0;
			break;
	}
}

bool BO_Timer::isPaused() {
	if (timerstate == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool BO_Timer::isRunning() {
	if (timerstate == 2) {
		return true;
	}
	else {
		return false;
	}
}

bool BO_Timer::isStoped() {
	if (timerstate == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool BO_Timer::timeUp() {
	countdown < SDL_GetTicks() - getTicks() ? false : true;
}



BO_FpsRegulator::BO_FpsRegulator(Uint32 fps) 
: framecount(0), time_sum(0)
{
	setFps(fps); //sets msec_per_frame;
}

void BO_FpsRegulator::setFps(Uint32 fps) { 
	msec_per_frame = 1000/fps; 
}

void BO_FpsRegulator::reset() {
	time.stop();
	time.start(0);
	framecount = 0;
	time_sum = 0;
}

void BO_FpsRegulator::stop() {
	time.stop();
	framecount = 0;
	time_sum = 0;
}

void BO_FpsRegulator::getFps(Uint32 interval, double* fps) {
	
	if (real_time.isRunning()) {
		
		framecount++;
		
		if (interval < real_time.getTicks() ) {
			*fps = double(framecount*1000)/real_time.getTicks();
			framecount = 0;
			real_time.start(0);
		}
	}
	else {
		real_time.start(0);
	}
	
}

void BO_FpsRegulator::regulateFps() {
	
	if ( time.isRunning() ) {
		Uint32 ms = time.getTicks();
		if (ms < msec_per_frame) {
			SDL_Delay( msec_per_frame - ms );
		}
	}
	
	time.start(0);
}


