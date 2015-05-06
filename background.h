#ifndef _BACKGROUND_INCLUDED__
#define _BACKGROUND_INCLUDED__

#include "game_object.h"
#include "init2.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

extern SDL_Surface* screen;

extern SDL_Surface* backgroundGFX;

void updateBackground(GameObject &background);
void renderBackground(GameObject &background);

#endif

