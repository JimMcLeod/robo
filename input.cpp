#include "input.h"

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
                if (event.key.keysym.sym == SDLK_END)
                    inpFR = true;
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
                if (event.key.keysym.sym == SDLK_END)
                    inpFR = false;
                break;

            }
        }
    }
}

void actOnInput(GameObject &player)
{
    if (inpUP)
        player.y--;
    if (inpDW)
        player.y++;
    if (inpRG)
    {
        player.direction += player.turnRate;
        if (player.direction >= player.noOfDirections)
        {
            player.direction -= player.noOfDirections;
        }
    }
    if (inpLF)
    {
        if (player.direction <= 0)
        {
            player.direction += player.noOfDirections;
        }
        player.direction -= player.turnRate;
    }
    if (inpFR)
    {
        player.x += xDir[int(player.direction)];
        player.y += yDir[int(player.direction)];
    }
}
