#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;
const char* WINDOW_TYPE = "Game";

using namespace std;

void wait_until_press_exit(){
    SDL_Event e;
    bool running = true;

    while (running){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT || e.type == SDL_KEYDOWN){
                running = false;
            }
        }
    }
}

int main(int argc, char* argv[]){
    SDL_Window* window = SDL_CreateWindow(WINDOW_TYPE, SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    bool running = true;
    SDL_Event e;

    while (running){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                running = false;
            }
        }
        SDL_Texture *texture = IMG_LoadTexture(renderer, "Start.jpg");
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}
