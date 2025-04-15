#include "card.h"
#include "image.h"
#include <vector>

std::vector<Card> cards;
Card* firstFlipped = nullptr;
Card* secondFlipped = nullptr;
Uint32 flipStartTime = 0;
bool waitingToCheck = false;

void createCards(SDL_Renderer* renderer) {
    SDL_Texture* cardTextures[] = {
        card_image1(renderer), card_image2(renderer), card_image3(renderer), card_image4(renderer), card_image5(renderer), card_image6(renderer),
        card_image1(renderer), card_image2(renderer), card_image3(renderer), card_image4(renderer), card_image5(renderer), card_image6(renderer)
    };

    int ids[] = {
        0, 1, 2, 3, 4, 5,
        0, 1, 2, 3, 4, 5
    };

    SDL_Point positions[] = {
        {100, 250}, {300, 250}, {500, 250}, {700, 250}, {900, 250}, {1100, 250},
        {100, 500}, {300, 500}, {500, 500}, {700, 500}, {900, 500}, {1100, 500}
    };

    cards.clear();

    for (int i = 0; i < 12; ++i) {
        Card card;
        card.rect = { positions[i].x, positions[i].y, 150, 200 };
        card.frontTexture = cardTextures[i];
        card.id = ids[i];
        card.isFlipped = false;
        card.isMatched = false;
        cards.push_back(card);
    }
}


void drawCards(SDL_Renderer* renderer, SDL_Texture* backTexture) {
    for (const auto& card : cards) {
        if (card.isMatched) {
            continue;
        }

        if (card.isFlipped) {
            SDL_RenderCopy(renderer, card.frontTexture, NULL, &card.rect);
        }

        else {
            SDL_RenderCopy(renderer, backTexture, NULL, &card.rect);
        }
    }
}


