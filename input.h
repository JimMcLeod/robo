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

extern float xDir[8];
extern float yDir[8];

extern SDL_Rect playerRect;

extern bool done;

void getInput();
void actOnInput(GameObject &player);
#endif
