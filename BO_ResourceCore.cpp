/*
 *  BO_ResourceCORE.cpp
 *  BO
 *
 *  Created by Daniel Lindfors on 6/8/12.
 *  Copyright 2012 KTH. All rights reserved.
 *
 */

#include "BO_ResourceCore.h"



BO_ResourceManager::BO_ResourceManager() {}
BO_ResourceManager::~BO_ResourceManager() {}
SDL_Surface* BO_ResourceManager::getTextureSection(int textureID, SDL_Rect section) {}
SDL_Surface* BO_ResourceManager::getTexture(int textureID) {}
Mix_Music* BO_ResourceManager::getMusic(int musicID) {}
Mix_Chunk* BO_ResourceManager::getSound(int soundID) {}
int BO_ResourceManager::loadTextureFromFile(string filename) {}
int BO_ResourceManager::loadSoundFromFile(string filename) {}
int BO_ResourceManager::loadMusicFromFile(string filename) {}
void BO_ResourceManager::freeTexture(int textureID) {}
void BO_ResourceManager::freeSound(int soundID) {}
void BO_ResourceManager::freeMusic(int musicID) {}
void BO_ResourceManager::freeAllTextures() {}
void BO_ResourceManager::freeAllSounds() {}
void BO_ResourceManager::freeAllMusic() {}
void BO_ResourceManager::freeAllResources() {}