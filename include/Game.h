#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

#include "Config.h"
#include "StateManager.h"

typedef enum
{
    NORTH,
    SOUTH,
    EAST,
    WEST,
} Direction;

typedef struct
{
    int score;
    Direction direction;
    SDL_Point **grid;
} Game;

unsigned int GAME_init(void *data);
unsigned int GAME_update(float deltatime);
unsigned int GAME_draw(Graphics *graphics, void *data);
unsigned int GAME_destory(void *data);
unsigned int GAME_ctor(State *game);

#endif