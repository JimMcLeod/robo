#ifndef _UPDATE_PLAYER_INCLUDED__
#define _UPDATE_PLAYER_INCLUDED__

#include "game_object.h"
#include "input.h"
#include "bullet.h"
#include <math.h>

extern bool inpUP;
extern bool inpDW;
extern bool inpLF;
extern bool inpRG;
extern bool inpF1;
extern bool inpF2;
extern bool done;

extern float xDir[8];
extern float yDir[8];
extern SDL_Surface* screen;

void actOnInput(GameObject &player);
void updatePlayer(GameObject &player);

#endif
