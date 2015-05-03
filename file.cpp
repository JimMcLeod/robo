#include "file.h"

SDL_Surface* loadSurface( std::string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	} else {
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, screen->format, NULL );
		if (optimizedSurface == NULL)
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
return optimizedSurface;
}

void loadImages()
{
    titleGFX = loadSurface("img/title.png");
    backgroundGFX = loadSurface("img/background.jpg");
    playerGFX = loadSurface("img/robot.png");
}
