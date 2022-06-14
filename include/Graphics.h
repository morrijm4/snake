#ifndef ENGINE_GRAPHICS_H
#define ENGINE_GRAPHICS_H

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>

typedef struct
{
    int width;
    int height;
    char *windowTitle;
    SDL_Window *window;
    SDL_Renderer *renderer;
} Graphics;

int GRAPHICS_init(Graphics *graphics);
void GRAPHICS_free(Graphics *graphics);

// Game Graphics

void GRAPHICS_drawBountary(Graphics *graphics);
void GRAPHICS_drawRedRect(Graphics *graphics);

#endif