#include "include/state.h"
#include <stdio.h>
#include <SFML/Graphics.h>

static PS_State state;

static void load(PS_State *self)
{
    printf("Initializing the game state\n");
}

static void update(PS_State *self)
{
    printf("Updating the game state\n");
}

static void draw(PS_State *self, sfRenderWindow* renderWindow)
{
    printf("Drawing the game state\n");
}

static void destroy(PS_State *self)
{
    printf("Destroying!\n");
}

PS_State *init_game_state()
{
    state.load = &load;
    state.update = &update;
    state.draw = &draw;
    state.destroy = &destroy;
    return &state;
}