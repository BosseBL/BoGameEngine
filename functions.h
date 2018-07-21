

#ifndef BO_FUNCTIONS_H
#define BO_FUNCTIONS_H


#include <string.h>
#include <iostream.h>
#include <sstream>
#include <SDL.h>
#include <SDL_image/SDL_image.h>

using namespace std;

template <typename num>		//takes nummerical values and turns them into a string
string toString(num i) {
	stringstream ss;
	ss << i;
	return ss.str();
}      

SDL_Surface* initialize(int w, int h, string name, int bpp, int screenInitFlags);


SDL_Surface* loadImage(string file);


SDL_Surface* loadImage(string file, Uint32 colorkey);




#endif
