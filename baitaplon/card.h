#ifndef CARD_H
#define CARD_H

#include <SDL.h>
#include <vector>

struct Card {
    SDL_Rect rect;
    SDL_Texture* frontTexture;
    bool isFlipped;
    bool isMatched;
};

extern std::vector<Card> cards;
extern Card* firstFlipped;
extern Card* secondFlipped;
extern Uint32 flipStartTime;
extern bool waitingToCheck;

void createCards(SDL_Renderer* renderer);
void drawCards(SDL_Renderer* renderer, SDL_Texture* backTexture);

#endif
