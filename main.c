#include "SDL2/SDL.h"

#include "Config.h"
#include "Engine.h"
#include "StateManager.h"
#include "MainMenu.h"
#include "Game.h"

int main()
{
  Engine engine = {0};
  ENGINE_init(&engine);

  State mainMenu = {0};
  if (MAIN_MENU_ctor(&mainMenu))
    return 1;

  STATEMANAGER_push(&engine.stateManager, &mainMenu);

  State game = {0};
  if (GAME_ctor(&game))
    return 1;

  STATEMANAGER_push(&engine.stateManager, &game);

  SDL_Event e;
  while (!engine.quit)
  {
    while (SDL_PollEvent(&e))
    {
      if (e.type == SDL_QUIT)
        engine.quit = 1;
    }

    GRAPHICS_clearScreen(&engine.graphics);
    STATEMANAGER_draw(&engine.stateManager, &engine.graphics);
    GRAPHICS_draw(&engine.graphics);
  }

  ENGINE_free(&engine);
  return 0;
}
