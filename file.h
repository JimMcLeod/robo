#ifndef _FILE_INCLUDED__
#define _FILE_INCLUDED__

#include <string>
#include <SDL/SDL_image.h>

extern SDL_Surface* screen;

SDL_Surface* loadSurface(std::string path);
SDL_Surface* loadSurface(std::string path, int r, int g, int b);

extern SDL_Surface* titleGFX;
extern SDL_Surface* backgroundGFX;
extern SDL_Surface* playerGFX[4][8];
extern SDL_Surface* bitmapFont;
extern SDL_Surface* bitmapFontBlack;

void loadImages();
void loadPlayerGFX();

#endif
