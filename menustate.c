#include "powerstrike.h"
#include "state.h"
#include "rendertexture.h"
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

static PS_State state;

// CSFML_WINDOW_API sfBool sfKeyboard_isKeyPressed(sfKeyCode key);

// Assets
static sfMusic* music = NULL;
static PS_RenderTex *background = NULL;
static PS_RenderTex *tex = NULL;
static const int speed = 5;

static void load(PS_State *self)
{
    printf("Initializing the menu state\n");

    // Loading musics
    music = sfMusic_createFromFile("assets/musics/Shining Force III Scenario 3 OST - The Lone Wolf.ogg");
    sfMusic_setLoop(music, sfTrue);
    if (!music) return;
    // Loading backgrounds
    background = load_rendertex("assets/backgrounds/sea_bg.png", NULL);
    sfVector2f vec = { 6, 6 };
    sfSprite_setScale(background->sprite, vec);
    // Map the texture
    tex = load_rendertex("assets/devil_soldier_scene.png", NULL);
    vec.x = 5;
    vec.y = 5;
    sfSprite_setScale(tex->sprite, vec);
    /* Play the music */
    sfMusic_play(music);
}

static void update(PS_State *self, sfEvent event)
{
    // printf("Updating the menu state\n");
    sfVector2f position = sfSprite_getPosition(tex->sprite);

    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		position.x+=speed;
		sfSprite_setPosition(tex->sprite, position);
	} else if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		position.x-=speed;
		sfSprite_setPosition(tex->sprite, position);
	}

	if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		position.y+=speed;
		sfSprite_setPosition(tex->sprite, position);
	} else if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		position.y-=speed;
		sfSprite_setPosition(tex->sprite, position);
	}
}

static void draw(PS_State *self, sfRenderWindow* renderWindow)
{
    // printf("Drawing the menu state\n");
    sfRenderWindow_drawSprite(renderWindow, background->sprite, NULL);
    sfRenderWindow_drawSprite(renderWindow, tex->sprite, NULL);
}

static void destroy(PS_State *self)
{
    printf("Destroying!\n");
    sfMusic_destroy(music);
}

PS_State *init_menu_state()
{
    state.load = &load;
    state.update = &update;
    state.draw = &draw;
    state.destroy = &destroy;
    return &state;
}
