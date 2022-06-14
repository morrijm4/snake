#include <SDL2/SDL_log.h>
#include <SDL2/SDL_error.h>

void assert(int errorCode);

void assert(int errorCode)
{
    if (errorCode != 0)
        printf("%s", SDL_GetError());
}