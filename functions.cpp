
#include "functions.h"




SDL_Surface* initialize(int w, int h, string name, int bpp, int screenInitFlags) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) return NULL;
	SDL_WM_SetCaption(name.c_str(), NULL);
	return SDL_SetVideoMode(w, h, bpp, screenInitFlags );
}


SDL_Surface* loadImage(string file) {
	SDL_Surface* img = NULL;
	SDL_Surface* imgOpt = NULL;
	
	img = IMG_Load(file.c_str() );
	
	if (img != NULL) {
		imgOpt = SDL_DisplayFormat(img);
		SDL_FreeSurface(img);
		if (imgOpt == NULL) return NULL;
		else return imgOpt;
	}
	SDL_FreeSurface(img);
	SDL_FreeSurface(imgOpt);
	return NULL;
}


SDL_Surface* loadImage(string file, Uint32 colorkey) {
	SDL_Surface* img = NULL;
	SDL_Surface* imgOpt = NULL;
	
	img = IMG_Load(file.c_str() );
	
	if (img != NULL) {
		SDL_SetColorKey(imgOpt, SDL_SRCCOLORKEY, colorkey);
		imgOpt = SDL_DisplayFormat(img);
		SDL_FreeSurface(img);
		if (imgOpt != NULL) {
			return imgOpt;
		}
	}
	return NULL;
}