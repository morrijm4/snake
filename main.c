#include "SDL2/SDL.h"

#include "Constants.h"
#include "Engine.h"
#include "StateManager.h"
#include "MainMenu.h"
#include "Game.h"

int main()
{
  EngineOptions options;
  options.title = "Snake";
  options.height = WINDOW_HEIGHT;
  options.width = WINDOW_WIDTH;

  Engine engine;
  ENGINE_init(&engine, &options);

  State mainMenu;
  if (MAIN_MENU_ctor(&mainMenu))
    return 1;

  STATEMANAGER_push(&engine.stateManager, &engine.graphics, &mainMenu);

  GameOptions gameOptions;
  gameOptions.boundaryHeight = BOUNDARY_HEIGHT;
  gameOptions.boundaryWidth = BOUNDARY_WIDTH;
  gameOptions.padding = PADDING;

  State game;
  if (GAME_ctor(&game, &gameOptions))
    return 1;

  STATEMANAGER_push(&engine.stateManager, &engine.graphics, &game);
  STATEMANAGER_draw(&engine.stateManager, &engine.graphics);

  SDL_Event e;
  while (!engine.quit)
  {
    while (SDL_PollEvent(&e))
    {
      if (e.type == SDL_QUIT)
        engine.quit = 1;
    }
  }

  ENGINE_free(&engine);
  return 0;
}
