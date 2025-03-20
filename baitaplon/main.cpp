#include <iostream>
#include <SDL.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

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
    SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
}
