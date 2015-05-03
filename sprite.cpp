#include <SDL/SDL.h>
#include "sprite.h"

void sprite(GameObject gameObject)
{
    float xoffset=playerGFX[gameObject.animFrame][gameObject.direction]->w/2;
    float yoffset=playerGFX[gameObject.animFrame][gameObject.direction]->h/2;

    SDL_Rect gameObjectRect;
    gameObjectRect.x=gameObject.x-xoffset;
    gameObjectRect.y=gameObject.y-yoffset;

    if (gameObject.type == 0)
    {
        SDL_BlitSurface(playerGFX[gameObject.animFrame][gameObject.direction], 0, screen, &gameObjectRect);
    }
}
