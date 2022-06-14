#include "../include/Game.h"
#include "Constants.h"

#include <stdlib.h>
#include <time.h>

unsigned int GAME_init(Graphics *graphics, void *game)
{
    Game *gamePtr = (Game *)game;

    srand(time(NULL));
    gamePtr->direction = rand() % 4;
    gamePtr->score = 0;

    const SDL_Rect boundary = {
        gamePtr->padding,
        gamePtr->padding,
        BOUNDARY_WIDTH,
        BOUNDARY_HEIGHT};

    if (SDL_SetRenderDrawColor(graphics->renderer, 0xFF, 0xFF, 0xFF, 0xFF))
    {
        printf("%s", SDL_GetError());
        return 1;
    }
    if (SDL_RenderDrawRect(graphics->renderer, &boundary))
    {
        printf("ERROR: failed init game state -- %s", SDL_GetError());
        return 1;
    }
    SDL_RenderPresent(graphics->renderer);

    return 0;
}

unsigned int GAME_update(float deltatime)
{
    return 0;
}

unsigned int GAME_draw(Graphics *graphics, void *game)
{
    // Game *gamePtr = (Game *)game;
    GRAPHICS_drawRedRect(graphics);
    return 0;
}

unsigned int GAME_destory(void *game)
{
    return 0;
}

unsigned int GAME_ctor(State *game, GameOptions *gameOptions)
{
    game->init = GAME_init;
    game->update = GAME_update;
    game->draw = GAME_draw;
    game->destroy = GAME_destory;

    game->data = malloc(sizeof(Game));
    if (game->data == NULL)
    {
        printf("ERROR: Unable to allocate memory for game\n");
        return 1;
    }

    Game *gamePtr = (Game *)game->data;
    gamePtr->boundaryHeight = gameOptions->boundaryHeight;
    gamePtr->boundaryWidth = gameOptions->boundaryWidth;
    gamePtr->padding = gameOptions->padding;

    return 0;
}