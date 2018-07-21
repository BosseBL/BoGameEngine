/*
 *  BO_SystemCORE.cpp
 *  BO
 *
 *  Created by Daniel Lindfors on 6/8/12.
 *  Copyright 2012 KTH. All rights reserved.
 *
 */

#include "BO_SystemCore.h"


BO_ProcessManager::BO_ProcessManager() {}
BO_ProcessManager::~BO_ProcessManager() {}

int BO_ProcessManager::push(void(*function)()) {
	processes.push_back(function);
	return processes.size();
}
bool BO_ProcessManager::process() {
	for (int i = 0; i < processes.size(); i++) {
		processes[i]();
	}
	return true;
}
bool BO_ProcessManager::popAll() {
	processes.erase(processes.begin(), processes.end());
	return processes.empty();
}
bool BO_ProcessManager::pop(int i) {
	int size = processes.size();
	processes.erase(processes.begin() + i);
	return processes.size() == size-1 ? true : false;
}
bool BO_ProcessManager::pop() {
	int size = processes.size();
	processes.pop_back();
	return processes.size() == size-1 ? true : false;
}
bool BO_ProcessManager::pop(void(*foo)()) {
	for (int i = 0; i < processes.size(); i++) {
		if (processes[i] == foo) {
			return pop(i);
		}
	}
	return false;
}
bool BO_ProcessManager::isInProcesses(void(*foo)()) {
	for (int i = 0; i < processes.size(); i++) {
		if (processes[i] == foo) {
			return true;
		}
	}
	return false;
}




BO_StateManager::BO_StateManager() {}
BO_StateManager::~BO_StateManager() {}
int BO_StateManager::push(BO_State) {}
bool BO_StateManager::pop() {}
bool BO_StateManager::popAll() {}
int BO_StateManager::currentState() {}




BO_App::BO_App() {}
BO_App::~BO_App() {}
bool BO_App::initialize() {}
void BO_App::run() {}
void BO_App::shutDown() {}
bool BO_App::resizeWindow(int width, int height) {}
bool BO_App::togleFullscreen() {}




