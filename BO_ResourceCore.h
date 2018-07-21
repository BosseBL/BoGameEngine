/*
 *  BO_ResourceCORE.h
 *  BO
 *
 *  Created by Daniel Lindfors on 6/8/12.
 *  Copyright 2012 KTH. All rights reserved.
 *
 */

#ifndef BO_RESOURCECORE_H
#define BO_RESOURCECORE_H

#include <map.h>
#include <SDL.h>
#include <SDL_mixer/SDL_mixer.h>
#include <string>

using namespace std;

class BO_ResourceManager {
private:
	map<int, SDL_Surface*> textures;
	map<int, Mix_Chunk*> sounds;
	map<int, Mix_Music*> musics;
	
public:
	BO_ResourceManager();
	~BO_ResourceManager();
	
	SDL_Surface* getTextureSection(int textureID, SDL_Rect section);
	SDL_Surface* getTexture(int textureID);
	
	Mix_Music* getMusic(int musicID);
	Mix_Chunk* getSound(int soundID);
	
	int loadTextureFromFile(string filename);
	int loadSoundFromFile(string filename);
	int loadMusicFromFile(string filename);
	
	void freeTexture(int textureID);
	void freeSound(int soundID);
	void freeMusic(int musicID);
	
	void freeAllTextures();
	void freeAllSounds();
	void freeAllMusic();
	
	void freeAllResources();
	
};


#endif