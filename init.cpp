#include "init.h"

void GameStatus::init()
{
    titlePage = true;
    gameScene = false;
}
GameObject GameStatus::initPlayer(GameObject player)
{
    player.active=true;
    player.id=0;
    player.type=0;
    player.x=400;
    player.y=200;
    player.direction=6;
    player.animFrame=0;

    return player;
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
