#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <vector>
#include "defs.h"
#include "init.h"
#include "font.h"
#include "image.h"
#include "card.h"
#include "logic.h"

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

enum GameState {
    STATE_MENU,
    STATE_PLAYING
};

int main(int argc, char* argv[]) {
    init_all();

    window = SDL_CreateWindow(WINDOW_TYPE, SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Texture* menuImageTexture = init_picture(renderer);
    SDL_Texture* menuTextTexture = init_font(renderer);
    SDL_Texture* playTexture = play_bg(renderer);

    SDL_Texture* backTexture = card_imageback(renderer);
    createCards(renderer);

    GameState currentState = STATE_MENU;
    bool running = true;
    SDL_Event e;


    while (running) {
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
        }
        else if (e.type == SDL_MOUSEBUTTONDOWN) {
            if (currentState == STATE_MENU) {
                currentState = STATE_PLAYING;
            }
            else if (currentState == STATE_PLAYING) {
                int mouseX = e.button.x;
                int mouseY = e.button.y;
                handleMouseClick(mouseX, mouseY);
            }
        }
    }

    if (waitingToCheck && SDL_GetTicks() - flipStartTime >= 1000) {
        if (firstFlipped && secondFlipped) {
            if (firstFlipped->frontTexture == secondFlipped->frontTexture) {
                firstFlipped->isMatched = true;
                secondFlipped->isMatched = true;

                firstFlipped->isFlipped = true;
                secondFlipped->isFlipped = true;
            }

            else {
                firstFlipped->isFlipped = false;
                secondFlipped->isFlipped = false;
            }
        }
        firstFlipped = nullptr;
        secondFlipped = nullptr;
        waitingToCheck = false;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    if (currentState == STATE_MENU) {
        SDL_RenderCopy(renderer, menuImageTexture, NULL, NULL);
        SDL_Rect textRect = {450, 400, 0, 0};
        SDL_QueryTexture(menuTextTexture, NULL, NULL, &textRect.w, &textRect.h);
        SDL_RenderCopy(renderer, menuTextTexture, NULL, &textRect);
    }
    else if (currentState == STATE_PLAYING) {
        SDL_RenderCopy(renderer, playTexture, NULL, NULL);
        drawCards(renderer, backTexture);
    }

    SDL_RenderPresent(renderer);
}

    SDL_DestroyTexture(menuImageTexture);
    SDL_DestroyTexture(menuTextTexture);
    SDL_DestroyTexture(playTexture);
    quit_all();
}
