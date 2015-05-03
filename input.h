#ifndef _INPUT_INCLUDED__
#define _INPUT_INCLUDED__

#include <SDL/SDL.h>

extern bool inpUP;
extern bool inpDW;
extern bool inpLF;
extern bool inpRG;
extern bool inpFR;

extern SDL_Rect playerRect;

extern bool done;

void getInput();
void actOnInput();
#endif