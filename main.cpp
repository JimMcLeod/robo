#include <cstdlib>
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
bool inpF1;
bool inpF2;
bool done;

SDL_Surface* titleGFX;
SDL_Surface* backgroundGFX;
SDL_Surface* playerGFX[4][8];

const int noOfGameObjects = 5;
GameObject gameObjects[noOfGameObjects];

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
    for (unsigned int i=0; i<noOfGameObjects; i++)
    {
        gameObjects[i].active = false;
    }
    GameStatus gameStatus;
    gameStatus.init();
    gameStatus.initPlayer(gameObjects[0]);

    bool inpF1Pressed = false;
    bool inpF2Pressed = false;

    // program main loop
    done = false;
    while (!done)
    {
        // input
        getInput();
        actOnInput(gameObjects[0]);
        // Check speed within top bound
        if (gameObjects[0].speed > gameObjects[0].topSpeed)
        {
            gameObjects[0].speed = gameObjects[0].topSpeed;
        }
        // Update position
        gameObjects[0].x += xDir[int(gameObjects[0].direction)] * gameObjects[0].speed;
        gameObjects[0].y += yDir[int(gameObjects[0].direction)] * gameObjects[0].speed;
        // Check in bounds
        if (gameObjects[0].x < 0)
        {
            gameObjects[0].x = 0;
        }
        if (gameObjects[0].x > screen->w)
        {
            gameObjects[0].x = screen->w;
        }
        if (gameObjects[0].y < 0)
        {
            gameObjects[0].y = 0;
        }
        if (gameObjects[0].y > screen->h)
        {
            gameObjects[0].y = screen->h;
        }
        // Friction
        gameObjects[0].speed -= gameObjects[0].friction;
        if (gameObjects[0].speed < 0)
        {
            gameObjects[0].speed = 0;
        }

        // DRAWING STARTS HERE

        // Render title screen
        if (gameStatus.isTitlePage())
        {
            SDL_BlitSurface(titleGFX, 0, screen, &originRect);
            if ((!inpF1 && inpF1Pressed) || (!inpF2 && inpF2Pressed))
            {
                gameStatus.setGameScene(true);
                gameStatus.setTitlePage(true);
            }
            inpF1Pressed = inpF1;
            inpF2Pressed = inpF2;
        }

        // Render game
        if (gameStatus.isGameScene())
        {
            SDL_BlitSurface(backgroundGFX, 0, screen, &originRect);
            for (unsigned int i=0; i<noOfGameObjects; i++)
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
        int j = (-i + 4) & 7;
        xDir[i] = sin(j*dirInc*3.1415/180);
        yDir[i] = cos(j*dirInc*3.1415/180);
    }
}
