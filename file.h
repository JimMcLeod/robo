#ifndef _FILE_INCLUDED__
#define _FILE_INCLUDED__

#include <string>
#include <SDL/SDL_image.h>
#include <iostream>
#include <fstream>
#include <sstream>

extern SDL_Surface* screen;

SDL_Surface* loadSurface(std::string path);
SDL_Surface* loadSurface(std::string path, int r, int g, int b);

extern SDL_Surface* titleGFX;
extern SDL_Surface* tilesGFX;
extern SDL_Surface* backgroundGFX;
extern SDL_Surface* playerGFX[32];
extern SDL_Surface* bulletGFX;
extern SDL_Surface* bitmapFont;
extern SDL_Surface* bitmapFontBlack;
extern SDL_Surface* bitmapFontHighlight;
extern int map[50][30];

void loadImages();
void loadPlayerGFX();
void loadMap();

#endif
