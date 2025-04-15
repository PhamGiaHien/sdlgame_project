#ifndef TIME_H
#define TIME_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "defs.h"

const int COUNTDOWN_TIME = 25000;

void resetTimer();
bool updateAndRenderTimer(SDL_Renderer* renderer, TTF_Font* font, GameState& currentState);

#endif


