#include <stdio.h>
#include <stdlib.h>
#include "../include/StateManager.h"

int STATEMANAGER_init(StateManager *stateManager)
{
  printf("INIT: State Manager\n");
  stateManager->capacity = 3;
  stateManager->top = -1;

  stateManager->stack = malloc(sizeof(State *) * stateManager->capacity);
  if (stateManager->stack == NULL)
  {
    printf("ERROR: Unable to allocate memory for the state manager\n");
    return 1;
  }
  return 0;
}

int STATEMANAGER_free(StateManager *stateManager)
{
  do
  {
    STATEMANAGER_pop(stateManager);
  } while (stateManager->top > -1);

  free(stateManager->stack);

  printf("DESTROY: State Manager\n");
  return 0;
}

int STATEMANAGER_scale(StateManager *stateManager)
{
  stateManager->capacity *= 2;
  stateManager->stack = realloc(stateManager->stack, sizeof(State *) * stateManager->capacity);

  printf("Allocate more memmory: %d\n", stateManager->capacity);
  return stateManager->capacity;
}

int STATEMANAGER_push(StateManager *stateManager, Graphics *graphics, State *state)
{
  if (stateManager->top + 1 == stateManager->capacity)
    STATEMANAGER_scale(stateManager);

  stateManager->stack[++stateManager->top] = state;

  if (state->init != NULL)
    state->init(graphics, state->data);

  printf("State pushed to the stack\n");
  return stateManager->top;
}

int STATEMANAGER_pop(StateManager *stateManager)
{
  if (stateManager->top < 0)
  {
    printf("ERROR: No state to pop -- empty stack");
    return stateManager->top;
  }

  State *top = STATEMANAGER_top(stateManager);

  if (top->destroy != NULL)
    top->destroy(top->data);

  stateManager->stack[stateManager->top--] = NULL;

  printf("State popped from the stack\n");
  return stateManager->top;
}

State *STATEMANAGER_top(StateManager *stateManager)
{
  return stateManager->stack[stateManager->top];
}

int STATEMANAGER_update(StateManager *stateManager, float deltatime)
{
  State *state = STATEMANAGER_top(stateManager);
  if (state->update != NULL)
    return state->update(deltatime);
  return 1;
}

int STATEMANAGER_draw(StateManager *stateManager, Graphics *graphics)
{
  State *state = STATEMANAGER_top(stateManager);

  if (state->draw != NULL)
    return state->draw(graphics, state->data);

  return 1;
}
