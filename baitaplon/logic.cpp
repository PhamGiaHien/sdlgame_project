#include "logic.h"

void handleMouseClick(int x, int y) {
    if (waitingToCheck) return;

    for (auto& card : cards) {
        if (!card.isFlipped && !card.isMatched &&
            x >= card.rect.x && x <= card.rect.x + card.rect.w &&
            y >= card.rect.y && y <= card.rect.y + card.rect.h) {

            card.isFlipped = true;

            if (firstFlipped == nullptr) {
                firstFlipped = &card;
            } else if (secondFlipped == nullptr) {
                secondFlipped = &card;
                flipStartTime = SDL_GetTicks();
                waitingToCheck = true;
            }

            break;
        }
    }
}
