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

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

enum GameState {
    STATE_MENU,
    STATE_PLAYING
};

struct Card {
    SDL_Rect rect;               // vị trí và kích thước
    SDL_Texture* frontTexture;   // mặt trước
    bool isFlipped;              // đã lật hay chưa
    bool isMatched = false;
};

std::vector<Card> cards;
Card* firstFlipped = nullptr;
Card* secondFlipped = nullptr;
Uint32 flipStartTime = 0;
bool waitingToCheck = false;

void createCards(SDL_Renderer* renderer) {
    SDL_Texture* cardTextures[] = {
        card_image1(renderer), card_image2(renderer), card_image3(renderer),
        card_image4(renderer), card_image5(renderer), card_image6(renderer),
        card_image5(renderer), card_image4(renderer), card_image2(renderer),
        card_image6(renderer), card_image3(renderer), card_image1(renderer)
    };

    SDL_Point positions[] = {
        {100, 250}, {300, 250}, {500, 250}, {700, 250}, {900, 250}, {1100, 250},
        {100, 500}, {300, 500}, {500, 500}, {700, 500}, {900, 500}, {1100, 500}
    };

    for (int i = 0; i < 12; ++i) {
        Card card;
        card.rect = { positions[i].x, positions[i].y, 150, 200 };
        card.frontTexture = cardTextures[i];
        card.isFlipped = false;
        cards.push_back(card);
    }
}

void drawCards(SDL_Renderer* renderer, SDL_Texture* backTexture) {
    for (const auto& card : cards) {
        if (card.isMatched || card.isFlipped) {
            SDL_RenderCopy(renderer, card.frontTexture, NULL, &card.rect);
        } else {
            SDL_RenderCopy(renderer, backTexture, NULL, &card.rect);
        }
    }
}


void handleMouseClick(int x, int y) {
    if (waitingToCheck) return; // đang chờ xử lý cặp bài

    for (auto& card : cards) {
        if (!card.isFlipped && !card.isMatched &&
            x >= card.rect.x && x <= card.rect.x + card.rect.w &&
            y >= card.rect.y && y <= card.rect.y + card.rect.h) {

            card.isFlipped = true;

            if (firstFlipped == nullptr) {
                firstFlipped = &card;
            } else if (secondFlipped == nullptr) {
                secondFlipped = &card;
                flipStartTime = SDL_GetTicks();      // ✅ ghi thời gian lật
                waitingToCheck = true;               // ✅ bắt đầu chờ xử lý
            }

            break;
        }
    }
}


int main(int argc, char* argv[]) {
    init_all();

    window = SDL_CreateWindow(WINDOW_TYPE, SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Texture* menuImageTexture = init_picture(renderer);
    SDL_Texture* playTexture = play_bg(renderer);
    SDL_Texture* menuTextTexture = init_font(renderer);

    SDL_Texture* backTexture = card_imageback(renderer);
    createCards(renderer);

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
            } else if (currentState == STATE_PLAYING) {
                int mouseX = e.button.x;
                int mouseY = e.button.y;
                handleMouseClick(mouseX, mouseY);
            }
        }
    }

    // ✅ Xử lý sau khi lật 2 lá bài và chờ 1 giây (đưa ra ngoài SDL_PollEvent)
    if (waitingToCheck && SDL_GetTicks() - flipStartTime >= 1000) {
        if (firstFlipped && secondFlipped) {
            if (firstFlipped->frontTexture == secondFlipped->frontTexture) {
                firstFlipped->isMatched = true;
                secondFlipped->isMatched = true;

                firstFlipped->isFlipped = true;
                secondFlipped->isFlipped = true;
            } else {
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
    } else if (currentState == STATE_PLAYING) {
        SDL_RenderCopy(renderer, playTexture, NULL, NULL);
        drawCards(renderer, backTexture); // ✅ vẽ bài, sẽ tự bỏ qua nếu isMatched = true
    }

    SDL_RenderPresent(renderer);
}

    SDL_DestroyTexture(menuImageTexture);
    SDL_DestroyTexture(menuTextTexture);
    SDL_DestroyTexture(playTexture);
    quit_all();
}
