#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
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

float xDir[8];
float yDir[8];

void firstInit();

int main (int argc, char** argv)
{
    firstInit();

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

            for (unsigned int i=0; i<5; i++)
            {
                if (gameObjects[i].active == true)
                {
                    sprite(gameObjects[i]);
                }
            }
        }

        // DRAWING ENDS HERE
        SDL_Flip(screen);
    }

    // free loaded images
    SDL_FreeSurface(titleGFX);
    SDL_FreeSurface(backgroundGFX);
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<8; j++)
        {
            SDL_FreeSurface(playerGFX[i][j]);
        }
    }

    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}

void firstInit()
{
    // Set up movement table
    float dirInc = 360/8;
    for (int i=0; i<8; i++)
    {
        int j = -i + 4 & 7;
        xDir[i] = sin(j*dirInc*3.1415/180);
        yDir[i] = cos(j*dirInc*3.1415/180);
    }
}
