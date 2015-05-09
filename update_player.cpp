#include "update_player.h"

bool inpLFPressed = false;
bool inpRGPressed = false;
bool inpUPPressed = false;
bool inpDWPressed = false;

void updatePlayer(GameObject &player)
{
    if (!player.senseless)
    {
        actOnInput(player);
    }
    // Check speed within bounds
    if (player.speed > player.topSpeed)
    {
        player.speed = player.topSpeed;
    }
    if (player.speed < -player.topSpeed)
    {
        player.speed = -player.topSpeed;
    }
    // Update position
    if (player.verticalMovement)
    {
        player.y += yDir[int(player.direction)] * player.speed;
    } else {
        player.x += xDir[int(player.direction)] * player.speed;
        player.y += yDir[int(player.direction)] * player.speed;
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
    player.speed -= player.friction;
    if (player.speed < 0)
    {
        player.speed = 0;
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

        if (inpF2 && player.thrustAvailable)
        {
            player.speed += player.acceleration;
        }
    }
    inpLFPressed = inpLF;
    inpRGPressed = inpRG;
    inpUPPressed = inpUP;
    inpDWPressed = inpDW;
}
