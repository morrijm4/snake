#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "StateManager.h"

typedef struct
{
    int boundaryWidth;
    int boundaryHeight;
    int padding;
} GameOptions;

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
    int boundaryHeight;
    int boundaryWidth;
    int padding;
    Direction direction;
    SDL_Point **grid;
} Game;

unsigned int GAME_init(Graphics *graphics, void *game);
unsigned int GAME_update(float deltatime);
unsigned int GAME_draw(Graphics *graphics, void *game);
unsigned int GAME_destory(void *game);
unsigned int GAME_ctor(State *game, GameOptions *gameOptions);

#endif