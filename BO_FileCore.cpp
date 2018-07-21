/*
 *  BO_FileCORE.cpp
 *  BO
 *
 *  Created by Daniel Lindfors on 6/8/12.
 *  Copyright 2012 KTH. All rights reserved.
 *
 */

#include "BO_FileCore.h"


BO_FileManager::BO_FileManager() {}
BO_FileManager::~BO_FileManager() {}
SDL_Surface* BO_FileManager::loadImage(string filename) {}
SDL_Surface* BO_FileManager::loadImage(string filename, Uint32 colorkey) {}
Mix_Chunk* BO_FileManager::loadSound(string filename) {}
Mix_Music* BO_FileManager::loadMusic(string filename) {}
bool BO_FileManager::isLoaded(string filename) {}
void BO_FileManager::release(string filename) {}
