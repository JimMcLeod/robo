#include "title_page.h"

bool inpF1Pressed = false;
bool inpF2Pressed = false;

void updateTitlePage(GameObject &titlePage)
{
    if ((!inpF1 && inpF1Pressed) || (!inpF2 && inpF2Pressed))
    {
        initBackground(gameObjects[0]); // always make this [0]
        initPlayer(gameObjects[1]);
    }
    inpF1Pressed = inpF1;
    inpF2Pressed = inpF2;
}

void renderTitlePage(GameObject &titlePage)
{
    // position 0. 0 rect
    SDL_Rect originRect;
    originRect.x = 0;
    originRect.y = 0;

    SDL_BlitSurface(titleGFX, 0, screen, &originRect);

    drawBitmapString(30, 40, "Flying Saucer\nAttack");
    drawBitmapString(0, 400, "\tPRESS FIRE");
}
