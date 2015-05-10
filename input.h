#ifndef _INPUT_INCLUDED__
#define _INPUT_INCLUDED__

#include <SDL/SDL.h>
#include "game_object.h"

extern bool inpUP;
extern bool inpDW;
extern bool inpLF;
extern bool inpRG;
extern bool inpF1;
extern bool inpF2;
extern bool done;

extern float xDir[32];
extern float yDir[32];

extern SDL_Rect playerRect;

void getInput();

#endif
