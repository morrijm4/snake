#include "../include/Engine.h"

int ENGINE_init(Engine *engine)
{
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    if (GRAPHICS_init(&engine->graphics))
    {
        SDL_Quit();
        return 1;
    }

    if (STATEMANAGER_init(&engine->stateManager))
    {
        GRAPHICS_free(&engine->graphics);
        SDL_Quit();
        return 1;
    }

    engine->quit = 0;
    return 0;
}

int ENGINE_free(Engine *engine)
{
    STATEMANAGER_free(&engine->stateManager);
    GRAPHICS_free(&engine->graphics);
    SDL_Quit();
    return 0;
}