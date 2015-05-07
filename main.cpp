#include <cstdlib>
#include "init2.h"
#include "file.h"
#include "input.h"
#include "game_object.h"

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
SDL_Surface* bitmapFont;
SDL_Surface* bitmapFontBlack;
SDL_Surface* bitmapFontHighlight;

const int noOfGameObjects = 5;
GameObject gameObjects[noOfGameObjects];

float xDir[8];
float yDir[8];

const int FPS = 30;
Uint32 waitTime = 1000.0f/FPS;
Uint32 frameStartTime = 0;
Sint32 delayTime;

void initialisation();
void freeResources();

int main (int argc, char** argv)
{
    initialisation();

    loadImages();

    initGame();

    // program main loop
    done = false;
    while (!done)
    {
        getInput();

        for (unsigned int i=0; i<noOfGameObjects; i++)
        {
            if (gameObjects[i].active == true)
            {
                gameObjects[i].update(gameObjects[i]);
                gameObjects[i].render(gameObjects[i]);
            }
        }
        SDL_Flip(screen);

        delayTime = waitTime - (SDL_GetTicks() - frameStartTime);
        if (delayTime > 0)
            SDL_Delay((Uint32)delayTime);
        frameStartTime = SDL_GetTicks();
    }

    freeResources();

    printf("Exited cleanly\n");
    return 0;
}

void initialisation()
{
    // initialize SDL video
    if (SDL_Init( SDL_INIT_VIDEO) < 0 )
    {
        printf("Unable to init SDL: %s\n", SDL_GetError());
        return;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create screen
    screen = SDL_SetVideoMode(800, 480, 16,
            SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
    if (!screen)
    {
        printf("Unable to set full screen video: %s\n", SDL_GetError());
        return;
    }

    // Disable cursor
    SDL_ShowCursor(SDL_DISABLE);

    // Set up 8 directional movement table
    float dirInc = 360/8;
    for (int i=0; i<8; i++)
    {
        int j = (-i + 4) & 7;
        xDir[i] = sin(j*dirInc*3.1415/180);
        yDir[i] = cos(j*dirInc*3.1415/180);
    }
}

void freeResources()
{
    // Free images
    SDL_FreeSurface(titleGFX);
    SDL_FreeSurface(backgroundGFX);
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<8; j++)
        {
            SDL_FreeSurface(playerGFX[i][j]);
        }
    }

}
