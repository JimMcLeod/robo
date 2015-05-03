#ifndef _GAMESTATUS_INCLUDED__
#define _GAMESTATUS_INCLUDED__

class GameStatus {
    bool titlePage;
    bool gameScene;
public:
    void init();
    bool isTitlePage();
    bool isGameScene();
    void setTitlePage(bool status);
    void setGameScene(bool status);
};

#endif
