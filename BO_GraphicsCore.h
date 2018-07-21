/*
 *  BO_GraphicsCORE.h
 *  BO
 *
 *  Created by Daniel Lindfors on 6/8/12.
 *  Copyright 2012 KTH. All rights reserved.
 *
 */

#ifndef BO_GRAPHICSCORE_H
#define BO_GRAPHICSCORE_H

using namespace std;

#include <SDL.h>
#include <string>
#include <vector>
#include <map.h>


class BO_Animation {
	
private:
	vector<int> texture;
	vector<Uint32> ms_delay;
	int current_frame;
	Uint32 last_time;
	bool paused;
	int repetitions;
	
public:
	BO_Animation();
	~BO_Animation();
	
	void update();
	void setRepetitions(int reps);
	void pause();
	void resume();
	void reset();
	void jumpToFrame(int frame);
	void setTexture(int frame, int texture);
	void setDelay(int frame, Uint32 delay);
	void draw(float x, float y);
};

class BO_AnimationManager {
private:
	map<int, BO_Animation> animations;
	
public:
	BO_AnimationManager();
	~BO_AnimationManager();
	
	int createAnimation(vector<int> frames, vector<Uint32> delay);
	int createAnimation(vector<int> frames, Uint32 delay);
	
	void remove(int animation);
	void removeAll();
	
	void play(int animation);
	void playAll();
	
	void update(int animation);
	void updateAll();
	
	void resume(int animation);
	void resumeAll();
	
	void setRepetitions(int animation, int repetitions);
	
	void reset(int animation);
	void resetAll();
	
	void jumpToFrame(int animation, int frame);
	
	void drawAnimation(int animation, float x, float y);
};

struct BO_TextureSection {
	int textureID;
	SDL_Rect section;
};

struct BO_Texture {
	int texture;
	string filename;
	float w, h;
};

class BO_TextureManager {
private:
	map<int, BO_Texture> textures;
	map<int, BO_TextureSection> textureSections;
	
public:
	
	BO_TextureManager();
	~BO_TextureManager();
	
	int loadTextureFromFile(string filename);
	int loadTextureFromMemory(SDL_Surface* surface);
	
	vector<int> loadTexturesByFileList(string filelist);
	
	void reloadTextures();
	
	int createTextureSection(int textureID, SDL_Rect section);
	
	void removeTexture(int textureID);
	void removeAllTextures();
	void removeTextureSection(int textureSectionID);
	void remveAllTextureSections();
	
	void drawTexture(int textureID, int x, int y);
	void drawTextureSection(int textureSectionID, int x, int y);
	
	int getTextureWidth(int textureID);
	int getTextureHeight(int textureID);
	
};



class BO_Camera {
private:
	int xPosition, yPosition;
	
public:
	
	BO_Camera();
	~BO_Camera();
	
	void move(int dX, int dY);
	void setPosition(int x, int y);
	
	int getX();
	int getY();
	
};

class BO_Graphics {
	
protected:
	bool initialized;
	
public:
	BO_Graphics();
	~BO_Graphics();
	
	void initialize(int width, int height);
	void shutDown();
		
};


#endif