#include "input.h"

void getInput ()
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
                // exit if ESCAPE is pressed
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
                break;

            }
        } // end switch
    } // end of message processing

}
