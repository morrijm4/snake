#ifndef ENGINE_STATEMANAGER_H
#define ENGINE_STATEMANAGER_H

#include "Graphics.h"

typedef unsigned int (*fnPtr)();
typedef unsigned int (*fnPtrVoid)(void *data);
typedef unsigned int (*fnPtrFlt)(float);
typedef unsigned int (*fnPtrGraph)(Graphics *graphics);
typedef unsigned int (*fnPtrGraphVoid)(Graphics *graphics, void *data);
typedef unsigned int (*fnPtrGraphFlt)(Graphics *grpahics, float);

typedef struct
{
  fnPtrVoid init;
  fnPtrFlt update;
  fnPtrGraphVoid draw;
  fnPtrVoid destroy;
  void *data;
} State;

typedef struct
{
  State **stack;
  int capacity;
  int top;
} StateManager;

// Initialize State
int STATEMANAGER_init(StateManager *stateManager);
int STATEMANAGER_free(StateManager *stateManager);
int STATEMANAGER_scale(StateManager *stateManager);

int STATEMANAGER_push(StateManager *stateManager, State *state);
int STATEMANAGER_pop(StateManager *stateManager);
State *STATEMANAGER_top(StateManager *stateManager);

int STATEMANAGER_update(StateManager *stateManager, float deltatime);
int STATEMANAGER_draw(StateManager *stateManager, Graphics *graphics);

#endif
