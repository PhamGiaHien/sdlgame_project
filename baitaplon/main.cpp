#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "defs.h"
#include "init.h"
#include "font.h"
#include "start.h"
#include "image.h"

using namespace std;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

enum GameState {
    STATE_MENU,
    STATE_PLAYING
};

int main(int argc, char* argv[]) {
    init_all();

    SDL_Window* window = SDL_CreateWindow(WINDOW_TYPE, SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Texture* menuImageTexture = init_picture(renderer);
    SDL_Texture* menuTextTexture = init_font(renderer);
    SDL_Texture* playTexture = play_bg(renderer);
    SDL_Texture* card1Texture = card_image1(renderer);
    SDL_Texture* card2Texture = card_image2(renderer);
    SDL_Texture* card3Texture = card_image3(renderer);
    SDL_Texture* card4Texture = card_image4(renderer);
    SDL_Texture* card5Texture = card_image5(renderer);
    SDL_Texture* card6Texture = card_image6(renderer);
    SDL_Texture* cardbackTexture = card_imageback(renderer);

    GameState currentState = STATE_MENU;
    bool running = true;
    SDL_Event e;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (currentState == STATE_MENU) {
                    currentState = STATE_PLAYING;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // đen
        SDL_RenderClear(renderer);


        if (currentState == STATE_MENU) {
            SDL_RenderCopy(renderer, menuImageTexture, NULL, NULL);

            SDL_Rect textRect = {450, 400, 0, 0};
            SDL_QueryTexture(menuTextTexture, NULL, NULL, &textRect.w, &textRect.h);
            SDL_RenderCopy(renderer, menuTextTexture, NULL, &textRect);
        }

        else if (currentState == STATE_PLAYING) {
            SDL_RenderCopy(renderer, playTexture, NULL, NULL);

            SDL_Rect backcard = {100, 250, 150, 200};
            SDL_RenderCopy(renderer, cardbackTexture, NULL, &backcard);

            SDL_Rect card1Rect = {100, 250, 150, 200};
            SDL_RenderCopy(renderer, card1Texture, NULL, &card1Rect);

            SDL_Rect card2Rect = {300, 250, 150, 200};
            SDL_RenderCopy(renderer, card2Texture, NULL, &card2Rect);

            SDL_Rect card3Rect = {500, 250, 150, 200};
            SDL_RenderCopy(renderer, card3Texture, NULL, &card3Rect);

            SDL_Rect card4Rect = {700, 250, 150, 200};
            SDL_RenderCopy(renderer, card4Texture, NULL, &card4Rect);

            SDL_Rect card5Rect = {900, 250, 150, 200};
            SDL_RenderCopy(renderer, card5Texture, NULL, &card5Rect);

            SDL_Rect card6Rect = {1100, 250, 150, 200};
            SDL_RenderCopy(renderer, card6Texture, NULL, &card6Rect);

            //rect 2

            SDL_Rect card5Rect2 = {100, 500, 150, 200};
            SDL_RenderCopy(renderer, card5Texture, NULL, &card5Rect2);

            SDL_Rect card1Rect2 = {900, 500, 150, 200};
            SDL_RenderCopy(renderer, card1Texture, NULL, &card1Rect2);

            SDL_Rect card6Rect2 = {700, 500, 150, 200};
            SDL_RenderCopy(renderer, card6Texture, NULL, &card6Rect2);

            SDL_Rect card2Rect2 = {500, 500, 150, 200};
            SDL_RenderCopy(renderer, card2Texture, NULL, &card2Rect2);

            SDL_Rect card3Rect2 = {1100, 500, 150, 200};
            SDL_RenderCopy(renderer, card3Texture, NULL, &card3Rect2);

            SDL_Rect card4Rect2 = {300, 500, 150, 200};
            SDL_RenderCopy(renderer, card4Texture, NULL, &card4Rect2);
        }
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(menuImageTexture);
    SDL_DestroyTexture(menuTextTexture);
    SDL_DestroyTexture(playTexture);
    quit_all();
}
