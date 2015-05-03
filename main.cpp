#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <stdio.h>
#include <string>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "init.h"
#include "file.h"
#include "input.h"

SDL_Surface* screen;
bool inpUP;
bool inpDW;
bool inpLF;
bool inpRG;
bool inpFR;
bool done;
int playerX;
int playerY;

int main ( int argc, char** argv )
{
    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    screen = SDL_SetVideoMode(800, 480, 16,
            SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);

    if (!screen)
    {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }

    // load an image
    SDL_Surface* titleGFX = loadSurface("img/title.png", screen);
    SDL_Surface* backgroundGFX = loadSurface("img/background.jpg", screen);
    SDL_Surface* playerGFX = loadSurface("img/robot.png", screen);

    // position of background image
    SDL_Rect originRect;
    originRect.x = 0;
    originRect.y = 0;

    // Disable cursor
    SDL_ShowCursor(SDL_DISABLE);

    // Init game
    GameStatus gameStatus;
    gameStatus.init();

    // Player positiom
    SDL_Rect playerRect;
    playerRect.x = 400;
    playerRect.y = 200;

    // program main loop
    done = false;
    while (!done)
    {
        // message processing loop
        getInput();

        // input test
        if (inpUP)
            playerRect.y--;
        if (inpDW)
            playerRect.y++;
        if (inpLF)
            playerRect.x--;
        if (inpRG)
            playerRect.x++;

        // DRAWING STARTS HERE

        // draw bitmap
        if (gameStatus.isTitlePage())
        {
            SDL_BlitSurface(titleGFX, 0, screen, &originRect);
            if (inpFR)
            {
                gameStatus.setGameScene(true);
                gameStatus.setTitlePage(true);
            }
        }
        if (gameStatus.isGameScene())
        {
            SDL_BlitSurface(backgroundGFX, 0, screen, &originRect);
            SDL_BlitSurface(playerGFX, 0, screen, &playerRect);

        }

        // DRAWING ENDS HERE

        // finally, update the screen :)
        SDL_Flip(screen);
    } // end main loop

    // free loaded bitmap
    SDL_FreeSurface(titleGFX);
    SDL_FreeSurface(backgroundGFX);

    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}
