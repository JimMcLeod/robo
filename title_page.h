#ifndef _TITLE_PAGE_INCLUDED__
#define _TITLE_PAGE_INCLUDED__

#include "game_object.h"
#include "init2.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

extern SDL_Surface* screen;

extern bool inpUP;
extern bool inpDW;
extern bool inpLF;
extern bool inpRG;
extern bool inpF1;
extern bool inpF2;
extern bool done;

extern SDL_Surface* titleGFX;

void updateTitlePage(GameObject &titlePage);
void renderTitlePage(GameObject &titlePage);

#endif
