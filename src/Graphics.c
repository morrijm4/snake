#include "Graphics.h"
#include "../utils/assert.c"

int GRAPHICS_init(Graphics *graphics)
{
    graphics->window = SDL_CreateWindow(
        graphics->windowTitle,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        graphics->width,
        graphics->height,
        SDL_WINDOW_SHOWN);

    if (graphics->window == NULL)
    {
        SDL_Log("Unable to create window: %s\n", SDL_GetError());
        return 1;
    }

    graphics->renderer = SDL_CreateRenderer(graphics->window, 0, SDL_RENDERER_SOFTWARE);
    if (graphics->renderer == NULL)
    {
        SDL_Log("ERROR creating the renderer %s\n", SDL_GetError());
        return 1;
    }

    printf("INIT: Graphics\n");
    return 0;
}

void GRAPHICS_drawRedRect(Graphics *graphics)
{
    SDL_Rect fillRect = {graphics->width / 4, graphics->height / 4, 20, 20};
    assert(SDL_SetRenderDrawColor(graphics->renderer, 0xFF, 0x00, 0x00, 0xFF));
    assert(SDL_RenderFillRect(graphics->renderer, &fillRect));
    SDL_RenderPresent(graphics->renderer);
}

void GRAPHICS_free(Graphics *graphics)
{
    printf("DESTROY: Graphics\n");
    SDL_DestroyWindow(graphics->window);
    SDL_DestroyRenderer(graphics->renderer);
}