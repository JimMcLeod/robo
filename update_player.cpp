#include "update_player.h"

void updatePlayer(GameObject &player)
{
    if (!player.senseless)
        {
            actOnInput(player);
        }
        // Check speed within top bound
        if (player.speed > player.topSpeed)
        {
            player.speed = player.topSpeed;
        }
        // Update position
        player.x += xDir[int(player.direction)] * player.speed;
        player.y += yDir[int(player.direction)] * player.speed;
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
