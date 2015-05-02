#include "init.h"

void GameStatus::init()
{
    titlePage = true;
    gameScene = false;
}
bool GameStatus::isTitlePage()
{
    return titlePage;
}
bool GameStatus::isGameScene()
{
    return gameScene;
}
