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

extern float xDir[32];
extern float yDir[32];
extern SDL_Surface* screen;
extern SDL_Surface* playerGFX[32];

void actOnInput(GameObject &player);
void updatePlayer(GameObject &player);
bool environmentCollision(float x, float y);

#endif
