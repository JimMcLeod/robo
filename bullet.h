#ifndef _BULLET_INCLUDED__
#define _BULLET_INCLUDED__

#include "game_object.h"
#include "enums.h"
#include "init2.h"
#include "sprite.h"

extern bool inpF1Pressed;
extern bool inpF2Pressed;

void initBullet(float x, float y, float direction);
void updateBullet(GameObject &bullet);

#endif

