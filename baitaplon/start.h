#ifndef START.H
#define START.H

#include "defs.h"

SDL_Texture* init_picture(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load("image/startbg.jpg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}


#endif // START

