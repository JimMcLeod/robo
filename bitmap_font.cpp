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
    bool shadow = false;
    bool invert = false;
    bool highlight = false;

    for (unsigned int i=0; i<output.length(); i++)
    {
        int c = int(output[i]);
        switch (c)
        {
            case 9: // \t tab (centre text)
                position.x = (screen->w - (output.length() * 16)) /2;
                break;

            case 11: // \v vtab (toggle add shadow)
                shadow = !shadow;
                break;

            case 12: // \f form feed (toggle invert - black font white shadow)
                invert = !invert;
                break;

            case 13: // \r return (toggle highlight)
                highlight = !highlight;
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

                if (shadow)
                {
                    position.x += 2;
                    position.y += 2;

                    if (invert)
                    {
                        SDL_BlitSurface(bitmapFont, &character, screen, &position);
                    } else {
                        SDL_BlitSurface(bitmapFontBlack, &character, screen, &position);
                    }

                    position.x -= 2;
                    position.y -= 2;
                }
                if (invert)
                {
                    SDL_BlitSurface(bitmapFontBlack, &character, screen, &position);
                } else if (!highlight) {
                    SDL_BlitSurface(bitmapFont, &character, screen, &position);
                } else {
                    SDL_BlitSurface(bitmapFontHighlight, &character, screen, &position);
                }

                position.x += 16;
                break;
        }
    }
}
