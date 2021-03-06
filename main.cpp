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
bool inpF1Pressed = false;
bool inpF2Pressed = false;
bool done;

SDL_Surface* titleGFX;
SDL_Surface* tilesGFX;
SDL_Surface* backgroundGFX;
SDL_Surface* playerGFX[32];
SDL_Surface* bulletGFX;
SDL_Surface* bitmapFont;
SDL_Surface* bitmapFontBlack;
SDL_Surface* bitmapFontHighlight;

const int noOfGameObjects = 20;
GameObject gameObjects[noOfGameObjects];

float xDir[32];
float yDir[32];

int map[50][30];

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

        // FPS throttle
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

    // Set up 32 directional movement table (0 is north, moving clockwise)
    float dirInc = 360/32;
    for (int i=0; i<32; i++)
    {
        int j = (-i + 16) & 31;
        xDir[i] = sin(j*dirInc*3.14159/180);
        yDir[i] = cos(j*dirInc*3.14159/180);
    }
    xDir[0] = 0;
    yDir[8] = 0;
    yDir[24] = 0;
}

void freeResources()
{
    // Free images
    SDL_FreeSurface(titleGFX);
    SDL_FreeSurface(backgroundGFX);
    SDL_FreeSurface(bitmapFont);
    SDL_FreeSurface(bitmapFontBlack);
    SDL_FreeSurface(bitmapFontHighlight);

    for (int i=0; i<32; i++)
    {
            SDL_FreeSurface(playerGFX[i]);
    }

}
