#ifndef _GAMESTATUS_INCLUDED__
#define _GAMESTATUS_INCLUDED__

#include "game_object.h"

class GameStatus {
    bool titlePage;
    bool gameScene;
public:
    void init();
    GameObject initPlayer(GameObject player);
    bool isTitlePage();
    bool isGameScene();
    void setTitlePage(bool status);
    void setGameScene(bool status);
};

#endif
