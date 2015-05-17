#include "file.h"

SDL_Surface* loadSurface(std::string path, int r, int g, int b)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	} else {
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, screen->format, NULL);
		if (optimizedSurface != NULL)
		{
		    // Set transparency
			Uint32 colorkey = SDL_MapRGB(optimizedSurface->format, r, g, b);
			SDL_SetColorKey(optimizedSurface, SDL_SRCCOLORKEY, colorkey);
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
    return optimizedSurface;
}

SDL_Surface* loadSurface(std::string path)
{
    return loadSurface(path, 0xFF, 0, 0xFF);
}

void loadImages()
{
    titleGFX = loadSurface("img/title.png");
    backgroundGFX = loadSurface("img/background.jpg");
    bulletGFX = loadSurface("img/bullet.png");
    bitmapFont = loadSurface("img/font.png");
    bitmapFontBlack = loadSurface("img/font_black.png");
    bitmapFontHighlight = loadSurface("img/font_highlight.png");
    tilesGFX = loadSurface("img/tiles.png");
    loadPlayerGFX();
}

void loadPlayerGFX()
{
    for (int i=0; i<32; i++)
    {
        std::string filename="img/ply1_";
        if (i < 10)
        {
            filename.append("0");
            filename.append(1, static_cast<char>(i+48));
        } else {
            filename.append(1, static_cast<char>((i/10)+48));
            filename.append(1, static_cast<char>((i%10)+48));
        }
        filename.append(".png");
        playerGFX[i] = loadSurface(filename);
    }
}

void loadMap()
{
    SDL_Rect tile;
    tile.w = 16;
    tile.h = 16;
    SDL_Rect dest;

    std::ifstream file;
    file.open("map/robo.map");
    char line[256];

    if (!file)
    {
        printf("File not found or summat.\n");
        return;
    }

    for(int row = 0; row < 30; ++row)
    {
        std::string line;
        std::getline(file, line);


        std::stringstream iss(line);

        for (int col = 0; col < 50; ++col)
        {
            std::string val;
            std::getline(iss, val, ',');

            std::stringstream convertor(val);
            convertor >> map[col][row];
            int block = map[col][row] - 1;
            dest.x = col * 16;
            dest.y = row * 16;
            dest.w = 16;
            dest.h = 16;
            tile.x = (block % 10) * 16;
            tile.y = (block / 10) * 16;
            tile.w = 16;
            tile.h = 16;
            SDL_BlitSurface(tilesGFX, &tile, backgroundGFX, &dest);
        }
    }
    return;
}
