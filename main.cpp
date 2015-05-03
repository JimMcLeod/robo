#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
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

enum Type
{
    player
};

SDL_Rect playerRect;

SDL_Surface* titleGFX;
SDL_Surface* backgroundGFX;
SDL_Surface* playerGFX[4][8];

GameObject gameObjects[5];

void test()
{
    printf("TEST\n\n");
}

int main (int argc, char** argv)
{
    // initialize SDL video
    if (SDL_Init( SDL_INIT_VIDEO) < 0 )
    {
        printf("Unable to init SDL: %s\n", SDL_GetError());
        return 1;
    }

    gameObjects[0].update = &test;
    gameObjects[0].update();

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

    // load images
    loadImages();

    // position of background image
    SDL_Rect originRect;
    originRect.x = 0;
    originRect.y = 0;

    // Disable cursor
    SDL_ShowCursor(SDL_DISABLE);

    // Init game
    GameStatus gameStatus;
    gameStatus.init();
    GameObject player=gameObjects[0];
    player=gameStatus.initPlayer(player);
    player.direction = 0;
    bool inpFRPressed = false;
    // program main loop
    done = false;
    while (!done)
    {
        // message processing loop
        getInput();
        player = actOnInput(player);

        // DRAWING STARTS HERE

        // draw titles
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
            player.animFrame++;
            player.animFrame = player.animFrame & 3;
            sprite(player);
        }

        // DRAWING ENDS HERE
        SDL_Flip(screen);
    }

    // free loaded bitmap
    SDL_FreeSurface(titleGFX);
    SDL_FreeSurface(backgroundGFX);

    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}
