#ifndef DEFS.H
#define DEFS.H

#include <SDL.h>
#include <SDL_mixer.h>
#include "card.h"
#include <vector>

enum GameState {
    STATE_MENU,
    STATE_PLAYING,
    STATE_WIN,
    STATE_GAMEOVER
};

const int SCREEN_WIDTH = 1350;
const int SCREEN_HEIGHT = 900;

extern SDL_Renderer* renderer;
extern SDL_Window* window;
extern Mix_Chunk* flipSound;
extern Mix_Chunk* matchSound;

extern std::vector<Card> cards;
extern Card* firstFlipped;
extern Card* secondFlipped;
extern Uint32 flipStartTime;
extern bool waitingToCheck;

extern Uint32 startTime;

#endif // DEFS
