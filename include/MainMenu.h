#include <stdio.h>

#include "Config.h"
#include "Graphics.h"
#include "StateManager.h"

typedef struct
{
    char *title;
} MainMenu;

unsigned int MAIN_MENU_init(void *mainMenu);
unsigned int MAIN_MENU_destroy(void *data);
unsigned int MAIN_MENU_update(float deltatime);
unsigned int MAIN_MENU_draw(Graphics *graphics, void *mainMenu);

int MAIN_MENU_ctor(State *mainMenu);