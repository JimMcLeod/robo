#ifndef _SPRITE_INCLUDED__
#define _SPRITE_INCLUDED__

#include <SDL/SDL.h>
#include "game_object.h"

extern GameObject gameObjects[5];
extern SDL_Surface* playerGFX[4][8];
extern SDL_Surface* screen;

void sprite(GameObject gameObject);

#endif

