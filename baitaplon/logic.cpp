#include "logic.h"
#include "defs.h"
#include "time.h"

void handleMouseClick(int x, int y) {
    if (waitingToCheck) return;

    for (auto& card : cards) {
        if (!card.isFlipped && !card.isMatched &&
            x >= card.rect.x && x <= card.rect.x + card.rect.w &&
            y >= card.rect.y && y <= card.rect.y + card.rect.h) {

            card.isFlipped = true;
            Mix_PlayChannel(-1, flipSound, 0);

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

void updateCardMatchingLogic(Uint32 currentTime, GameState& currentState, Mix_Chunk* matchSound) {
    if (waitingToCheck && currentTime - flipStartTime >= 1000) {
        if (firstFlipped && secondFlipped) {
            if (firstFlipped->id == secondFlipped->id) {
                Mix_PlayChannel(-1, matchSound, 0);
                firstFlipped->isMatched = true;
                secondFlipped->isMatched = true;
            } else {
                firstFlipped->isFlipped = false;
                secondFlipped->isFlipped = false;
            }

            firstFlipped = nullptr;
            secondFlipped = nullptr;
            waitingToCheck = false;

            bool allMatched = true;
            for (const auto& card : cards) {
                if (!card.isMatched) {
                    allMatched = false;
                    break;
                }
            }
            if (allMatched) {
                currentState = STATE_WIN;
            }
        }
    }
}

