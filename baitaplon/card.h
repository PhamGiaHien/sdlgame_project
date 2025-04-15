#ifndef CARD_H
#define CARD_H

#include <SDL.h>

struct Card {
    SDL_Rect rect;
    SDL_Texture* frontTexture;
    bool isFlipped;
    bool isMatched;
    int id;
};

void createCards(SDL_Renderer* renderer);
void drawCards(SDL_Renderer* renderer, SDL_Texture* backTexture);

#endif

