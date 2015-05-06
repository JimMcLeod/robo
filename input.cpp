#include "input.h"
#include <math.h>

void getInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        // check for messages
        switch (event.type)
        {
        // exit if the window is closed
        case SDL_QUIT:
            done = true;
            break;

            // check for keypresses
        case SDL_KEYDOWN:
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    done = true;
                if (event.key.keysym.sym == SDLK_UP)
                    inpUP = true;
                if (event.key.keysym.sym == SDLK_DOWN)
                    inpDW = true;
                if (event.key.keysym.sym == SDLK_LEFT)
                    inpLF = true;
                if (event.key.keysym.sym == SDLK_RIGHT)
                    inpRG = true;
                if (event.key.keysym.sym == SDLK_PAGEDOWN)
                    inpF1 = true;
                if (event.key.keysym.sym == SDLK_END)
                    inpF2 = true;
                break;

            }
        case SDL_KEYUP:
            {
                if (event.key.keysym.sym == SDLK_UP)
                    inpUP = false;
                if (event.key.keysym.sym == SDLK_DOWN)
                    inpDW = false;
                if (event.key.keysym.sym == SDLK_LEFT)
                    inpLF = false;
                if (event.key.keysym.sym == SDLK_RIGHT)
                    inpRG = false;
                if (event.key.keysym.sym == SDLK_PAGEDOWN)
                    inpF1 = false;
                if (event.key.keysym.sym == SDLK_END)
                    inpF2 = false;
                break;

            }
        }
    }
}

bool inpLFPressed = false;
bool inpRGPressed = false;
void actOnInput(GameObject &player)
{
    if (inpUP)
        player.y--;
    if (inpDW)
        player.y++;
    if (inpRG && !inpRGPressed)
    {
        player.direction = floor(player.direction + 1);
        if (player.direction >= player.noOfDirections)
        {
            player.direction -= player.noOfDirections;
        }
    }
    if (inpRG && inpRGPressed) {
        player.direction += player.turnRate;
        if (player.direction >= player.noOfDirections)
        {
            player.direction -= player.noOfDirections;
        }
    }
    if (inpLF && !inpLFPressed)
    {
        player.direction = floor(player.direction) - player.turnRate;
        if (player.direction < 0)
        {
            player.direction = player.noOfDirections - player.turnRate;
        }
    }
    if (inpLF && inpLFPressed) {
        if (player.direction <= 0)
        {
            player.direction += player.noOfDirections;
        }
        player.direction -= player.turnRate;
    }
    inpLFPressed = inpLF;
    inpRGPressed = inpRG;
    if (inpF2)
    {
        player.speed += player.acceleration;
    }
}
