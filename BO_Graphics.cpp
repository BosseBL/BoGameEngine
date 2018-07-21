/*
 *  BO_Graphics.cpp
 *  BO
 *
 *  Created by Daniel Lindfors on 5/27/12.
 *  Copyright 2012 KTH. All rights reserved.
 *
 */

#include "BO_Graphics.h"
#include "BO_ErrorManager.h"
#include <SDL_image/SDL_image.h>

using namespace std;


//function definitions


Uint32 getPixel(SDL_Surface* screen, int x, int y) {
	int BPP = screen->format->BytesPerPixel; 
	Uint8* pp = (Uint8*)screen->pixels + y*screen->pitch + x*BPP;
	
	switch(BPP) {
		case 1:
			return *pp;
			break;
		case 2:
			return *(Uint16*)pp;
			break;
		case 3:
			if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
				return pp[0] << 16 | pp[1] << 8 | pp[2];
			}
			else {
				return pp[0] | pp[1] << 8 | pp[2] << 16;
			}
			break;
		case 4:
			return *(Uint32*)pp;
			break;
		default:
			return 0;
			break;
			
	}
}



//class definitions:

	//BO_SpriteSheet base class

BO_SpriteSheet::BO_SpriteSheet(string imgFileName, Uint32 colorKey) 
: imageFileName(imgFileName)
{
	loadSpriteSheet(imageFileName, colorKey);
}
BO_SpriteSheet::BO_SpriteSheet(string imgFileName) 
: imageFileName(imgFileName)  
{
	loadSpriteSheet(imageFileName);
}
BO_SpriteSheet::BO_SpriteSheet(SDL_Surface* sheet) 
: imageFileName("")
{
	loadSpriteSheet(sheet);
}

BO_SpriteSheet::~BO_SpriteSheet() {
	if (!imageFileName.empty()) SDL_FreeSurface(spriteSheet);
}

SDL_Surface* BO_SpriteSheet::getSpriteSheet() {
	return spriteSheet;
}

void BO_SpriteSheet::setColorkey(Uint32 colorkey) {
	SDL_SetColorKey(spriteSheet, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
}
void BO_SpriteSheet::setColorkey(int x, int y) {
	if (x < 0 || x >= spriteSheet->w || y < 0 || y >= spriteSheet->h) {
		throw BO_Exception("setColorkey(int x, int y) in BO_SpriteSheet out of bound", BO_OUT_OF_BOUND_EXCEPTION);
	}
	
	SDL_SetColorKey(spriteSheet, SDL_SRCCOLORKEY | SDL_RLEACCEL, getPixel(spriteSheet, x, y) );
}
void BO_SpriteSheet::setColorkey() {
	this->setColorkey(spriteSheet->w - 1, spriteSheet->h - 1);
}
 
void BO_SpriteSheet::loadSpriteSheet(string imgFileName, Uint32 colorkey) {
	
	if (spriteSheet != NULL && !imageFileName.empty() ) SDL_FreeSurface(spriteSheet);
	spriteSheet = loadImage(imgFileName);
	
	if (spriteSheet == NULL) {
		throw BO_Exception("loadSpriteSheet() couldn't load file " + imageFileName + " at BO_SpriteSheet", BO_MISSING_FILE_EXCEPTION);
	}
	else {
		imageFileName = imgFileName;
		setColorkey(colorkey);
	}
	
}
void BO_SpriteSheet::loadSpriteSheet(string imgFileName) {
	
	if (spriteSheet != NULL && !imageFileName.empty() ) SDL_FreeSurface(spriteSheet);
	
	spriteSheet = loadImage(imgFileName);
	imageFileName = imgFileName;
	
	if (spriteSheet == NULL) {
		throw BO_Exception("loadSpriteSheet() couldn't load file " + imageFileName + " at BO_SpriteSheet", BO_MISSING_FILE_EXCEPTION);
	}
	
}
void BO_SpriteSheet::loadSpriteSheet(SDL_Surface* sheet) {
	
	if (spriteSheet != NULL && !imageFileName.empty() ) SDL_FreeSurface(spriteSheet);
	
	spriteSheet = sheet;
	imageFileName = "";
	
}

void BO_SpriteSheet::blit_Sprite(SDL_Rect* clip, SDL_Rect* ofset, SDL_Surface* surf) {
	if (SDL_BlitSurface(spriteSheet, clip , surf, ofset ) == -1) {
		throw BO_Exception("could not blit clip from location x = " + toString(clip->x) + ", y = " + toString(clip->y) + " in file " + imageFileName, BO_BLIT_FALIURE_EXCEPTION );
	}

}
