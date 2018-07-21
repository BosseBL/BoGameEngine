
/* Simple program:  Create a blank window, wait for keypress, quit.
 
 Please see the SDL documentation for details on using the SDL API:
 /Developer/Documentation/SDL/docs.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <iostream.h>
#include "BO_ErrorManager.h"
#include "BO_Graphics.h"
#include "functions.h"
#include "BO_Physics.h"
#include "SDL.h"
#include "BO_SystemCore.h"

using namespace std;

void foo() {
	cout << "foo";
}




int main(int argc, char *argv[])
{
	
	BO_ProcessManager procman;
	procman.push(foo);
	procman.process();
	
	
	
	
	try{
		string str;
		Uint32 initflags = SDL_INIT_VIDEO;  /* See documentation for details */
		SDL_Surface *screen;
		Uint8  video_bpp = 0;
		Uint32 videoflags = SDL_SWSURFACE;
		int    done;
		SDL_Event event;
		
		/* Initialize the SDL library */
		if ( SDL_Init(initflags) < 0 ) {
			fprintf(stderr, "Couldn't initialize SDL: %s\n",
					SDL_GetError());
			exit(1);
		}
		
		/* Set 640x480 video mode */
		screen=SDL_SetVideoMode(640,480, video_bpp, videoflags);
		if (screen == NULL) {
			fprintf(stderr, "Couldn't set 640x480x%d video mode: %s\n",
					video_bpp, SDL_GetError());
			SDL_Quit();
			exit(2);
		}
		
		done = 0;
		while ( !done ) {
			
			/* Check for events */
			while ( SDL_PollEvent(&event) ) {
				switch (event.type) {
						
					case SDL_MOUSEMOTION:
						break;
					case SDL_MOUSEBUTTONDOWN:
						break;
					case SDL_KEYDOWN:
						/* Any keypress quits the app... */
					case SDL_QUIT:
						done = 1;
						break;
					default:
						break;
				}
			}
		}
		
		/* Clean up the SDL library */
		SDL_Quit();
	}
	catch (BO_Exception& e) {
		cerr<< e.what() << "  " << e.type();
	}
	return(0);
}

