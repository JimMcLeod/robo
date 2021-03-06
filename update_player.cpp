#include "update_player.h"

bool inpLFPressed = false;
bool inpRGPressed = false;
bool inpUPPressed = false;
bool inpDWPressed = false;

void updatePlayer(GameObject &player)
{
    int direction = player.direction;
    if (!player.senseless)
    {
        actOnInput(player);
    }
    // Check speed within bounds
    if (player.speed > player.topSpeed)
    {
        player.speed = player.topSpeed;
    }
    // Update position
    if (player.asteroidStyle)
    {
        if (player.thrustActivated)
        {
            player.xVector += xDir[int(player.direction)] * 1;//player.speed;
            player.yVector += yDir[int(player.direction)] * 1;//player.speed;
        }
        if (player.gravity > 0)
        {
            player.yVector += player.gravity;
        }
        player.x += player.xVector;
        player.y += player.yVector;
    } else {
        player.x += xDir[int(player.direction)] * player.speed;
        if (environmentCollision(player.x + 24, player.y))
        {
            while (environmentCollision(player.x + 24, player.y))
            {
                player.x = int(player.x) - 1;
            }
        }
        if (environmentCollision(player.x - 24, player.y))
        {
            while (environmentCollision(player.x - 24, player.y))
            {
                player.x = int(player.x) + 1;
            }
        }
        player.y += yDir[int(player.direction)] * player.speed;
        if (environmentCollision(player.x, player.y + 24))
        {
            while (environmentCollision(player.x, player.y + 24))
            {
                player.y = int(player.y) - 1;
            }
        }
        if (environmentCollision(player.x, player.y - 24))
        {
            while (environmentCollision(player.x, player.y - 24))
            {
                player.y = int(player.y) + 1;
            }
        }
    }
    // Check in bounds
    if (player.x < 0)
    {
        player.x = 0;
    }
    if (player.x > screen->w)
    {
        player.x = screen->w;
    }
    if (player.y < 0)
    {
        player.y = 0;
    }
    if (player.y > screen->h)
    {
        player.y = screen->h;
    }
    // Friction
    if (!player.asteroidStyle)
    {
        player.speed -= player.friction;
        if (player.speed < 0)
        {
            player.speed = 0;
        }
    } else {
        player.xVector *= player.friction;
        player.yVector *= player.friction;
    }
}

void actOnInput(GameObject &player)
{
    if (player.verticalMovement)
    {
        if (inpUP)
        {
            if (!inpUPPressed)
            {
                player.speed = 0;
            }
            player.direction = 0;
            player.speed += player.acceleration;
        }
        if (inpDW)
        {
            if (!inpDWPressed)
            {
                player.speed = 0;
            }
            player.direction = 4;
            player.speed += player.acceleration;
        }
    } else {
        if (inpRG && !inpRGPressed)
        {
            player.direction = floor(player.direction + 1);
            if (player.direction >= player.noOfDirections)
            {
                player.direction -= player.noOfDirections;
            }
        }
        if (inpRG && inpRGPressed) {
            player.direction += player.turnRate;
            if (player.direction >= player.noOfDirections)
            {
                player.direction -= player.noOfDirections;
            }
        }
        if (inpLF && !inpLFPressed)
        {
            player.direction = floor(player.direction) - player.turnRate;
            if (player.direction < 0)
            {
                player.direction = player.noOfDirections - player.turnRate;
            }
        }
        if (inpLF && inpLFPressed) {
            if (player.direction <= 0)
            {
                player.direction += player.noOfDirections;
            }
            player.direction -= player.turnRate;
        }

        player.thrustActivated = false;
        if (inpF2 && player.thrustAvailable)
        {
            if (player.asteroidStyle)
            {
                player.thrustActivated = true;
            } else {
                player.speed += player.acceleration;
            }
        }
    }
    if (inpF1 && !inpF1Pressed)
    {
        initBullet(player.x, player.y, player.direction);
        player.fireReady = player.fireReset;
    }
    if (inpF1 && inpF1Pressed) {
        player.fireReady -= player.fireRate;
        if (player.fireReady < 0)
        {
            initBullet(player.x, player.y, player.direction);
            player.fireReady = player.fireReset;
        }
    }

    inpLFPressed = inpLF;
    inpRGPressed = inpRG;
    inpUPPressed = inpUP;
    inpDWPressed = inpDW;
    inpF1Pressed = inpF1;
}

bool environmentCollision(float x, float y)
{
    int ix, iy;
    ix = x / 16;
    iy = y / 16;

    if (map[ix][iy] != 1)
    {
        return true;
    } else {
        return false;
    }
}
