#ifndef LOGIC_H
#define LOGIC_H

#include <SDL.h>
#include <SDL_mixer.h>
#include "defs.h"
#include "card.h"

void handleMouseClick(int x, int y);
void updateCardMatchingLogic(Uint32 currentTime, GameState& currentState, Mix_Chunk* matchSound);

#endif
