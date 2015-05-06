#include "init2.h"

void initGame()
{
    // Clear game objecta
    for (unsigned int i=0; i<noOfGameObjects; i++)
    {
        gameObjects[i].active = false;
    }
    initTitlePage();
}

void initTitlePage()
{
    GameObject titlePage;

    titlePage.active = true;
    titlePage.type = typeTitlePage;
    titlePage.update = updateTitlePage;
    titlePage.render = renderTitlePage;

    gameObjects[0] = titlePage;
}

void initBackground(GameObject &background)
{
    background.active = true;
    background.type = typeBackground;
    background.update = updateBackground;
    background.render = renderBackground;
}

void initPlayer(GameObject &player)
{
    player.active = true;
    player.id = 0;
    player.type = typePlayer;

    player.senseless = false;
    player.thrustAvailable = true;

    player.x = 400;
    player.y = 240;
    player.speed = 0;
    player.topSpeed = 10;
    player.acceleration = 0.3;
    player.friction = 0.2;
    player.direction = 0;
    player.turnRate = 0.2;
    player.noOfDirections = 8;
    player.animFrame = 0;
    player.animUpdate = 0.2;
    player.animNoOfFrames = 4;

    player.render = sprite;
    player.update = updatePlayer;
}
