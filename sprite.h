#ifndef _SPRITE_INCLUDED__
#define _SPRITE_INCLUDED__

#include <SDL/SDL.h>
#include "game_object.h"

extern GameObject gameObjects[];
extern SDL_Surface* playerGFX[32];
extern SDL_Surface* bulletGFX;
extern SDL_Surface* screen;

void sprite(GameObject &gameObject);

#endif

