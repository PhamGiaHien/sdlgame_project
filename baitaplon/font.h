#ifndef FONT.H
#define FONT.H

#include "defs.h"

SDL_Texture* init_font(SDL_Renderer* renderer) {
    TTF_Font* font = TTF_OpenFont("font/ShortBaby-Mg2w.ttf", 50);
    SDL_Color textColor = {255, 255, 255, 255};

    SDL_Surface* textSurface = TTF_RenderText_Blended(font, "Press anywhere to start", textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);

    return textTexture;
}
#endif // FONT
