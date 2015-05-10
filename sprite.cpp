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
    float xoffset;
    float yoffset;

    // Render object
    switch (gameObject.type)
    {
        case typePlayer:
            // Set object direction
            int direction;
            if (gameObject.verticalMovement)
            {
                direction = 2;
            } else {
                direction = int(gameObject.direction);
            }
            // Set object position
            xoffset=playerGFX[direction]->w/2;
            yoffset=playerGFX[direction]->h/2;
            gameObjectRect.x=gameObject.x-xoffset;
            gameObjectRect.y=gameObject.y-yoffset;

            SDL_BlitSurface(playerGFX[direction], 0, screen, &gameObjectRect);
            break;

        case typeBullet:
            xoffset=bulletGFX->w/2;
            yoffset=bulletGFX->h/2;
            gameObjectRect.x=gameObject.x-xoffset;
            gameObjectRect.y=gameObject.y-yoffset;

            SDL_BlitSurface(bulletGFX, 0, screen, &gameObjectRect);
            break;
    }
}
