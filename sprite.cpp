#include <SDL/SDL.h>
#include "sprite.h"
#include "enums.h"
#include "game_object.h"

void sprite(GameObject &gameObject)
{
    // Update animation frame
    gameObject.animFrame += gameObject.animUpdate;
    if (gameObject.animFrame >= gameObject.animNoOfFrames)
    {
        gameObject.animFrame -= gameObject.animNoOfFrames;
    }
    int animFrame = int(gameObject.animFrame);
    SDL_Rect gameObjectRect;

    // Render object
    switch (gameObject.type)
    {
        case typePlayer:
            // Set object position
            int direction;
            if (gameObject.verticalMovement)
            {
                direction = 2;
            } else {
                direction = int(gameObject.direction);
            }
            float xoffset=playerGFX[animFrame][direction]->w/2;
            float yoffset=playerGFX[animFrame][direction]->h/2;
            gameObjectRect.x=gameObject.x-xoffset;
            gameObjectRect.y=gameObject.y-yoffset;

            SDL_BlitSurface(playerGFX[animFrame][direction], 0, screen, &gameObjectRect);
            break;
    }
}
