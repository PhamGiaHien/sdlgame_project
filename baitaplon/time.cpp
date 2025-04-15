#include "time.h"
#include "defs.h"

Uint32 startTime = 0;

void resetTimer() {
    startTime = SDL_GetTicks();
}

bool updateAndRenderTimer(SDL_Renderer* renderer, TTF_Font* font, GameState& currentState) {
    Uint32 currentTime = SDL_GetTicks();
    int remainingTime = (COUNTDOWN_TIME - (currentTime - startTime)) / 1000;

    if (remainingTime <= 0) {
        currentState = STATE_GAMEOVER;
        return false;
    }

    SDL_Color textColor = {255, 255, 255, 255};
    std::string timeText = "Time: " + std::to_string(remainingTime);

    SDL_Surface* timeSurface = TTF_RenderText_Blended(font, timeText.c_str(), textColor);
    SDL_Texture* timeTexture = SDL_CreateTextureFromSurface(renderer, timeSurface);

    SDL_Rect timeRect = {1150, 20, 0, 0};
    SDL_QueryTexture(timeTexture, NULL, NULL, &timeRect.w, &timeRect.h);
    SDL_RenderCopy(renderer, timeTexture, NULL, &timeRect);

    SDL_FreeSurface(timeSurface);
    SDL_DestroyTexture(timeTexture);

    return true;
}

