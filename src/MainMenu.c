#include "MainMenu.h"

unsigned int MAIN_MENU_init(void *mainMenu)
{
    MainMenu *mainMenuPtr = (MainMenu *)mainMenu;
    mainMenuPtr->title = TITLE;

    printf("INIT: Main Menu --> %s\n", mainMenuPtr->title);

    return 0;
}

unsigned int MAIN_MENU_destroy(void *data)
{
    printf("DESTROY: Main Menu\n");
    free(data);
    return 0;
}

unsigned int MAIN_MENU_update(float deltatime)
{
    printf("Main Menu update %f\n", deltatime);
    return 0;
}

unsigned int MAIN_MENU_draw(Graphics *graphics, void *mainMenu)
{
    MainMenu *mainMenuPtr = (MainMenu *)mainMenu;
    printf("Main Menu draw: %s\n", mainMenuPtr->title);
    GRAPHICS_drawRedRect(graphics);
    return 0;
}

int MAIN_MENU_ctor(State *mainMenu)
{
    mainMenu->init = MAIN_MENU_init;
    mainMenu->destroy = MAIN_MENU_destroy;
    mainMenu->draw = MAIN_MENU_draw;
    mainMenu->update = MAIN_MENU_update;

    mainMenu->data = malloc(sizeof(MainMenu));
    if (mainMenu->data == NULL)
    {
        printf("ERROR: Unable to allocate memory for Main Menu\n");
        return 1;
    }

    return 0;
}