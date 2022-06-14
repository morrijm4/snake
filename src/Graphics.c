#include "Graphics.h"

int GRAPHICS_init(Graphics *graphics)
{
    graphics->window = SDL_CreateWindow(
        TITLE,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
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

void GRAPHICS_free(Graphics *graphics)
{
    printf("DESTROY: Graphics\n");
    SDL_DestroyWindow(graphics->window);
    SDL_DestroyRenderer(graphics->renderer);
}

void GRAPHICS_draw(Graphics *graphics)
{
    SDL_RenderPresent(graphics->renderer);
    SDL_Delay(1000 / FPS);
}

void GRAPHICS_clearScreen(Graphics *graphics)
{
    check(SDL_SetRenderDrawColor(graphics->renderer, 0x00, 0x00, 0x00, 0x00));
    check(SDL_RenderClear(graphics->renderer));
}

void GRAPHICS_setColor(Graphics *graphcs, Uint64 color)
{
    check(SDL_SetRenderDrawColor(graphcs->renderer, (color & 0xFF000000) >> 24, (color & 0xFF0000) >> 16, (color & 0xFF00) >> 8, color & 0xFF));
}

void GRAPHICS_drawBoundary(Graphics *graphics)
{
    const SDL_Rect boundary = {
        PADDING,
        PADDING,
        BOUNDARY_WIDTH,
        BOUNDARY_HEIGHT};

    GRAPHICS_setColor(graphics, 0xFFFFFFFF);
    check(SDL_RenderDrawRect(graphics->renderer, &boundary));
}

void GRAPHICS_drawRedRect(Graphics *graphics)
{
    SDL_Rect fillRect = {WINDOW_WIDTH / 4, WINDOW_HEIGHT / 4, 20, 20};
    check(SDL_SetRenderDrawColor(graphics->renderer, 0xFF, 0x00, 0x00, 0xFF));
    check(SDL_RenderFillRect(graphics->renderer, &fillRect));
}