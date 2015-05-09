#ifndef _INIT2_INCLUDED__
#define _INIT2_INCLUDED__

#include "game_object.h"
#include "sprite.h"
#include "title_page.h"
#include "background.h"
#include "enums.h"
#include "update_player.h"

extern const int noOfGameObjects;
extern GameObject gameObjects[];

void initGame();
void initTitlePage();
void initPlayer(GameObject &player);
void initBackground(GameObject &background);
void clearGameObject(GameObject &GameObject);
void insertGameObject(GameObject &GameObject);

#endif
