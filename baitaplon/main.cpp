#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "defs.h"

using namespace std;

void wait_until_exit(){
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
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(WINDOW_TYPE, SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);


    bool running = true;
    SDL_Event e;

    while (running){
        while (SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){
                running = false;
            }
        }
        SDL_Texture* texture = IMG_LoadTexture (renderer, "jungle.jpg");
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}
