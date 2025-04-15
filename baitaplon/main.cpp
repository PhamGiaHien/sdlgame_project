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
#include "time.h"

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
Mix_Music* backgroundMusic = nullptr;
Mix_Chunk* flipSound = nullptr;
Mix_Chunk* matchSound = nullptr;
TTF_Font* font = nullptr;

int main(int argc, char* argv[]) {
    init_all();

    window = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Texture* menuImageTexture = init_picture(renderer); // BG ở menu
    SDL_Texture* menuTextTexture = init_font(renderer); //font start
    SDL_Texture* playTexture = play_bg(renderer); // BG ở play
    SDL_Texture* winTexture = win_bg(renderer); //BG ở win
    SDL_Texture* backTexture = card_imageback(renderer); // mặt sau của bài
    SDL_Texture* gameoverTexture = gameover_bg(renderer);
    createCards(renderer);

    backgroundMusic = Mix_LoadMUS("music/all.mp3");
    flipSound = Mix_LoadWAV("music/flip.wav");
    matchSound = Mix_LoadWAV("music/match.wav");
    Mix_PlayMusic(backgroundMusic, -1);
    Mix_VolumeMusic(50);

    font = TTF_OpenFont("font/ShortBaby-Mg2w.ttf", 50); //font tgian

    GameState currentState = STATE_MENU;
    bool running = true;
    bool isMusicPlaying = false;
    SDL_Event e;

    while (running) {
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
        }
        else if (e.type == SDL_MOUSEBUTTONDOWN) {
            if (currentState == STATE_MENU) {
                currentState = STATE_PLAYING;
                resetTimer();
            }
            else if (currentState == STATE_PLAYING) {
                int mouseX = e.button.x;
                int mouseY = e.button.y;
                handleMouseClick(mouseX, mouseY);
            }
            else if (currentState == STATE_GAMEOVER || currentState == STATE_WIN) {
                currentState = STATE_MENU;
                cards.clear();
                createCards(renderer);
                firstFlipped = nullptr;
                secondFlipped = nullptr;
                waitingToCheck = false;
                resetTimer();
            }
        }
    }


    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    if (currentState == STATE_MENU) {
        SDL_RenderCopy(renderer, menuImageTexture, NULL, NULL);
        SDL_Rect textRect = {425, 450, 0, 0};

        SDL_QueryTexture(menuTextTexture, NULL, NULL, &textRect.w, &textRect.h);
        SDL_RenderCopy(renderer, menuTextTexture, NULL, &textRect);
    }

    else if (currentState == STATE_PLAYING) {
        SDL_RenderCopy(renderer, playTexture, NULL, NULL);
        updateAndRenderTimer(renderer, font, currentState);
        drawCards(renderer, backTexture);
        updateCardMatchingLogic(SDL_GetTicks(), currentState, matchSound);
    }

    else if (currentState == STATE_WIN) {
        SDL_RenderCopy(renderer, winTexture, NULL, NULL);
    }

    else if (currentState == STATE_GAMEOVER) {
        SDL_RenderCopy(renderer, gameoverTexture, NULL, NULL);
    }

    SDL_RenderPresent(renderer);
}
    SDL_DestroyTexture(winTexture);
    SDL_DestroyTexture(menuImageTexture);
    SDL_DestroyTexture(menuTextTexture);
    SDL_DestroyTexture(playTexture);
    Mix_FreeMusic(backgroundMusic);
    quit_all();
}
