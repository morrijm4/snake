#include <stdlib.h>
#include <time.h>

#include "Game.h"
#include "Check.h"

unsigned int GAME_init(void *data)
{
    Game *game = (Game *)data;

    srand(time(NULL));
    game->direction = rand() % 4;
    game->score = 0;

    // (TODO) Initialize grid

    return 0;
}

unsigned int GAME_update(float deltatime)
{
    return 0;
}

unsigned int GAME_draw(Graphics *graphics, void *data)
{
    if (graphics->renderer == NULL)
    {
        printf("ERROR: Unable to create renderer -- %s\n", SDL_GetError());
        return 1;
    }

    GRAPHICS_drawBoundary(graphics);
    GRAPHICS_drawRedRect(graphics);

    return 0;
}

unsigned int GAME_destory(void *data)
{
    printf("DESTROY: Game\n");
    free(data);
    return 0;
}

unsigned int GAME_ctor(State *game)
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

    return 0;
}