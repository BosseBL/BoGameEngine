/*
 *  BO_FileCORE.h
 *  BO
 *
 *  Created by Daniel Lindfors on 6/8/12.
 *  Copyright 2012 KTH. All rights reserved.
 *
 */

#ifndef BO_FILECORE_H
#define BO_FILECORE_H

#include <string.h>
#include <vector.h>
#include <SDL.h>
#include <SDL_mixer/SDL_mixer.h>

using namespace std;

class BO_FileManager {
private:
	vector<string> filesLoaded;
	
public:
	BO_FileManager();   //check if everything is initialized
	~BO_FileManager();
	
	
	SDL_Surface* loadImage(string filename);
	SDL_Surface* loadImage(string filename, Uint32 colorkey);

	Mix_Chunk* loadSound(string filename);
	Mix_Music* loadMusic(string filename);
	
	bool isLoaded(string filename);
	
	void release(string filename);
	
};


#endif