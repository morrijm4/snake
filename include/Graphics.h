#ifndef ENGINE_GRAPHICS_H
#define ENGINE_GRAPHICS_H

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_log.h>

#include "Config.h"
#include "Check.h"

typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
} Graphics;

int GRAPHICS_init(Graphics *graphics);
void GRAPHICS_free(Graphics *graphics);
void GRAPHICS_draw(Graphics *graphics);
void GRAPHICS_clearScreen(Graphics *graphics);

// Game Graphics

void GRAPHICS_drawBountary(Graphics *graphics);
void GRAPHICS_drawRedRect(Graphics *graphics);

#endif