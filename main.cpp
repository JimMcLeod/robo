#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enums.h"
#include "init.h"
#include "file.h"
#include "input.h"
#include "game_object.h"
#include "sprite.h"

SDL_Surface* screen;
bool inpUP;
bool inpDW;
bool inpLF;
bool inpRG;
bool inpFR;
bool done;

SDL_Rect playerRect;

SDL_Surface* titleGFX;
SDL_Surface* backgroundGFX;
SDL_Surface* playerGFX[4][8];

GameObject gameObjects[5];

int main (int argc, char** argv)
{
    // initialize SDL video
    if (SDL_Init( SDL_INIT_VIDEO) < 0 )
    {
        printf("Unable to init SDL: %s\n", SDL_GetError());
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    screen = SDL_SetVideoMode(800, 480, 16,
            SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);

    if (!screen)
    {
        printf("Unable to set full screen video: %s\n", SDL_GetError());
        return 1;
    }

    // load image files
    loadImages();

    // position 0. 0 rect
    SDL_Rect originRect;
    originRect.x = 0;
    originRect.y = 0;

    // Disable cursor
    SDL_ShowCursor(SDL_DISABLE);

    // Init game
    for (unsigned int i=0; i<5; i++)
    {
        gameObjects[i].active = false;
    }
    GameStatus gameStatus;
    gameStatus.init();
    gameStatus.initPlayer(gameObjects[0]);

    bool inpFRPressed = false;

    // program main loop
    done = false;
    while (!done)
    {
        // input
        getInput();
        actOnInput(gameObjects[0]);

        // DRAWING STARTS HERE

        // Render title screen
        if (gameStatus.isTitlePage())
        {
            SDL_BlitSurface(titleGFX, 0, screen, &originRect);
            if (!inpFR && inpFRPressed)
            {
                gameStatus.setGameScene(true);
                gameStatus.setTitlePage(true);
            }
            inpFRPressed = inpFR;
        }

        // Render game
        if (gameStatus.isGameScene())
        {
            SDL_BlitSurface(backgroundGFX, 0, screen, &originRect);

            sprite(gameObjects[0]);
            /*for (unsigned int i=0; i<sizeof(gameObjects); i++)
            {
                GameObject obj = gameObjects[i];
                if (obj.active == true)
                {
                    sprite(obj);
                }
            }*/
        }

        // DRAWING ENDS HERE
        SDL_Flip(screen);
    }

    // free loaded bitmap
    SDL_FreeSurface(titleGFX);
    SDL_FreeSurface(backgroundGFX);
    // MESS no freeing up of player surfaces

    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}
