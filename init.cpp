#include "init.h"

void GameStatus::init()
{
    titlePage = false;
    gameScene = true;
}
bool GameStatus::isTitlePage()
{
    return titlePage;
}
bool GameStatus::isGameScene()
{
    return gameScene;
}
