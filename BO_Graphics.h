/*
 *  BO_Graphics.h
 *  BO
 *
 *  Created by Daniel Lindfors on 5/27/12.
 *  Copyright 2012 KTH. All rights reserved.
 *
 */

/* to do:
 * uniform sprite sheet where all the sprites are uniform. needs only one SDL_Rect
 * variable sprite sheet where all the sprites comes in diffrent sizes. probobly needs a map of rects
 * manual sprite sheet where the user uses width, height, x and y in calls to get the sprite manualy. pobobly not compatible with BO_System
 *
 *create functionality to group parts of sprite Sheet
 */



#ifndef BO_GRAPHICS_H
#define BO_GRAPHICS_H

#include <SDL.h>
#include <string>
#include <map.h>
#include "functions.h"


using namespace std;

//function declarations


Uint32 getPixel(SDL_Surface* screen, int x, int y);


//class declaratons

class BO_SpriteSheet {			//base class for sprite sheets
protected:
	SDL_Surface* spriteSheet;
	string imageFileName;		//used to avoid a SDL_FreeSurface call on a surface used in other parts of the program. se destructor.
	
public:
	BO_SpriteSheet(string imgFileName, Uint32 colorKey);
	BO_SpriteSheet(string imgFileName);
	BO_SpriteSheet(SDL_Surface* sheet);
	
	~BO_SpriteSheet();
	
	SDL_Surface* getSpriteSheet();
	
	void setColorkey(Uint32 colorkey);
	void setColorkey(int x, int y);		//sets the colorkey to whatever color the pixle at the cordinates x and y on the spriteSheet has.
	void setColorkey();					//a default setter. it sets the colorkey to the same color as the lowest and rightmost pixle in the spriteSheet
	
	void loadSpriteSheet(string imgFileName, Uint32 colorkey);
	void loadSpriteSheet(string imgFileName);
	void loadSpriteSheet(SDL_Surface* sheet);
	
	void blit_Sprite(SDL_Rect* clip, SDL_Rect* ofset, SDL_Surface* surf);
};

class BO_SpriteAnimation {
	
};




class BO_UniformSpriteSheet : public BO_SpriteSheet {
private:
	SDL_Rect rect;
public:
	BO_UniformSpriteSheet();
	~BO_UniformSpriteSheet();

};

class BO_NoneUniformSpriteSheet : public BO_SpriteSheet {
private:
	map<string, SDL_Rect>spriteSheetMap;
public:
	
	BO_NoneUniformSpriteSheet();
	~BO_NoneUniformSpriteSheet();
};

#endif