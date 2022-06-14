#ifndef ENGINE_H
#define ENGINE_H

#include "Graphics.h"
#include "StateManager.h"

typedef struct
{
    char *title;
    int height;
    int width;
} EngineOptions;

typedef struct
{
    char quit;
    StateManager stateManager;
    Graphics graphics;
} Engine;

int ENGINE_init(Engine *engine, EngineOptions *options);
int ENGINE_free(Engine *engine);

#endif