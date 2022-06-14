#include "Check.h"

void check(int errorCode)
{
    if (errorCode != 0)
        printf("ERROR: %s\n", SDL_GetError());
}