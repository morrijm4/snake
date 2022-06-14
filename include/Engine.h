#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>

#include "Graphics.h"
#include "StateManager.h"

typedef struct
{
    char quit;
    StateManager stateManager;
    Graphics graphics;
} Engine;

int ENGINE_init(Engine *engine);
int ENGINE_free(Engine *engine);

#endif