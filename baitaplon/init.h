#ifndef INIT.H
#define INIT.H

#include <iostream>
#include "defs.h"
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
using namespace std;

bool init_all() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        cerr << "SDL Init failed: " << SDL_GetError() << endl;
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        cerr << "IMG Init failed: " << IMG_GetError() << endl;
        return false;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        cerr << "Mix_OpenAudio failed: " << Mix_GetError() << endl;
        return false;
    }

    if (TTF_Init() == -1) {
        cerr << "TTF_Init failed: " << TTF_GetError() << endl;
        return false;
    }
    return true;
}

void quit_all() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    Mix_CloseAudio();
    Mix_FreeChunk(flipSound);
    Mix_FreeChunk(matchSound);
    IMG_Quit();
    SDL_Quit();
}

#endif // INIT

