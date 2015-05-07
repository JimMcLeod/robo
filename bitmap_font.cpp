#include "bitmap_font.h"

void drawBitmapString(int x, int y, std::string output)
{
    SDL_Rect character;
    character.h = 48;
    character.w = 48;
    SDL_Rect position;
    position.x = x;
    position.y = y;
    int newline = x;

    for (int i=0; i<output.length(); i++)
    {
        printf("c:%c - %i\n", output[i], output[i]);
        int c = int(output[i])-32;
        switch (c)
        {
            case 9-32: // tab (centre text)
                position.x = (screen->w - (output.length() * 48)) /2;
                break;

            case 10-32: // newline
                position.x = newline;
                position.y += 48;
                break;

            default:
                int cx = (c & 15) * 48;
                int cy = (c & 240) / 16 * 48;
                character.x = cx;
                character.y = cy;

                SDL_BlitSurface(bitmapFont, &character, screen, &position);

                position.x += 48;
                break;
        }
    }
}
