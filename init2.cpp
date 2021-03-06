#include "init2.h"

void initGame()
{
    // Clear game object
    for (signed int i=0; i<noOfGameObjects; i++)
    {
        clearGameObject(gameObjects[i]);
    }
    loadMap();
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
    player.id = 1;
    player.type = typePlayer;

    player.senseless = false;
    player.thrustAvailable = true;
    player.verticalMovement = false;
    player.asteroidStyle = false;
    player.thrustActivated = false;
    player.xVector = 0;
    player.yVector = 0;
    player.gravity = 0;

    player.x = 400;
    player.y = 240;
    player.direction = 0;

    player.speed = 0;
    player.topSpeed = 10;
    player.acceleration = 0.3;
    player.friction = 0.2;

    player.turnRate = 0.5;
    player.noOfDirections = 32;

    player.animFrame = 0;
    player.animUpdate = 0.2;
    player.animNoOfFrames = 4;

    player.fireRate = 2;
    player.fireReady = 10;
    player.fireReset = 10;

    player.render = sprite;
    player.update = updatePlayer;
}

void clearGameObject(GameObject &gameObject)
{
    gameObject.active = false;
    gameObject.type = 0;

    gameObject.senseless = false;
    gameObject.thrustAvailable = false;
    gameObject.verticalMovement = false;
    gameObject.asteroidStyle = false;
    gameObject.thrustActivated = false;
    gameObject.xVector = 0;
    gameObject.yVector = 0;
    gameObject.gravity = 0;

    gameObject.x = 0;
    gameObject.y = 0;
    gameObject.width = 0;
    gameObject.height = 0;

    gameObject.direction = 0;
    gameObject.turnRate = 0;
    gameObject.noOfDirections = 0;

    gameObject.speed = 1;
    gameObject.topSpeed = 0;
    gameObject.acceleration = 0;
    gameObject.friction = 0;

    gameObject.animFrame = 0;
    gameObject.animUpdate = 0;
    gameObject.animNoOfFrames = 0;

    gameObject.fireReady = 0;
    gameObject.fireRate = 0;
    gameObject.fireReset = 0;
}

void insertGameObject(GameObject &gameObject)
{
    for (int i=0; i<noOfGameObjects; i++)
    {
        if (!gameObjects[i].active)
        {
            gameObjects[i] = gameObject;
            return;
        }
    }
}
