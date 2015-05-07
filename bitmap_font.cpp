#include "bitmap_font.h"

void drawBitmapString(int x, int y, std::string output)
{
    SDL_Rect character;
    character.h = 16;
    character.w = 16;
    SDL_Rect position;
    position.x = x;
    position.y = y;
    int newline = x;

    for (int i=0; i<output.length(); i++)
    {
        int c = int(output[i]);
        switch (c)
        {
            case 9: // tab (centre text)
                position.x = (screen->w - (output.length() * 16)) /2;
                break;

            case 10: // newline
                position.x = newline;
                position.y += 16;
                break;

            default:
                int cx = (c & 15) * 16;
                int cy = c & 240;
                character.x = cx;
                character.y = cy;

                SDL_BlitSurface(bitmapFont, &character, screen, &position);

                position.x += 16;
                break;
        }
    }
}
