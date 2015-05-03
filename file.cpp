#include "file.h"

SDL_Surface* loadSurface(std::string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str());
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	} else {
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, screen->format, NULL );
		if (optimizedSurface != NULL)
		{
			Uint32 colorkey = SDL_MapRGB(optimizedSurface->format, 0xFF, 0, 0xFF);
			SDL_SetColorKey(optimizedSurface, SDL_SRCCOLORKEY, colorkey);
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
    loadPlayerGFX();
}

void loadPlayerGFX()
{
    for (int i=1; i<5; i++)
    {
        for (int j=1; j<9; j++)
        {
            std::string filename="img/pl";
            char c=static_cast<char>(i+48);
            filename.append(1, c);
            filename.append("_");
            c=static_cast<char>(j+48);
            filename.append(1, c);
            filename.append(".bmp");
            playerGFX[i-1][j-1] = loadSurface(filename);
        }
    }
}
