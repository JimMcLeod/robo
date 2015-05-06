#include "init.h"
#include "enums.h"

void GameStatus::init()
{
    titlePage = true;
    gameScene = false;
}

void GameStatus::initPlayer(GameObject &player)
{
    player.active = true;
    player.id = 0;
    player.type = typePlayer;
    player.x = 400;
    player.y = 220;
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
}

bool GameStatus::isTitlePage()
{
    return titlePage;
}

bool GameStatus::isGameScene()
{
    return gameScene;
}

void GameStatus::setTitlePage(bool state)
{
    titlePage = state;
}

void GameStatus::setGameScene(bool state)
{
    gameScene = state;
}
