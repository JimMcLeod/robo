#include "bullet.h"

void initBullet(float x, float y, float direction)
{
    GameObject bullet;
    clearGameObject(bullet);

    bullet.active = true;
    bullet.type = typeBullet;

    bullet.x = x;
    bullet.y = y;
    bullet.direction = direction;

    bullet.speed = 12;

    bullet.render = sprite;
    bullet.update = updateBullet;

    insertGameObject(bullet);
}

void updateBullet(GameObject &bullet)
{
    // Update position
    bullet.x += xDir[int(bullet.direction)] * bullet.speed;
    bullet.y += yDir[int(bullet.direction)] * bullet.speed;
    // Check in bounds
    if (bullet.x < 0)
    {
        bullet.active = false;
    }
    if (bullet.x > screen->w)
    {
        bullet.active = false;
    }
    if (bullet.y < 0)
    {
        bullet.active = false;
    }
    if (bullet.y > screen->h)
    {
        bullet.active = false;
    }
}
