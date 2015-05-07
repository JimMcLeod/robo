#ifndef _BITMAP_FONT_INCLUDED__
#define _BITMAP_FONT_INCLUDED__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>

extern SDL_Surface* bitmapFont;
extern SDL_Surface* screen;

void drawBitmapString(int x, int y, std::string output);

#endif
