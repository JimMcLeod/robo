#include "background.h"

void updateBackground(GameObject &background)
{

}

void renderBackground(GameObject &background)
{
    // position 0. 0 rect
    SDL_Rect originRect;
    originRect.x = 0;
    originRect.y = 0;

    SDL_BlitSurface(backgroundGFX, 0, screen, &originRect);
}
