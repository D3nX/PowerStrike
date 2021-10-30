#include "powerstrike.h"
#include "state.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE -1

int main()
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window;
    sfTexture* texture;
    // sfSprite* sprite;
    sfFont* font;
    sfText* text;
    sfEvent event;
    /* Create the main window */
    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    if (!window)
        return EXIT_FAILURE;

    sfRenderWindow_setFramerateLimit(window, 60);
    /* Load a sprite to display */
    /*texture = sfTexture_createFromFile("devil_soldier_scene.png", NULL);
    if (!texture)
        return EXIT_FAILURE;
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);

    sfVector2f scale = {5.f, 5.f};
    sfSprite_setScale(sprite, scale);*/
    /* Create a graphical text to display */
    font = sfFont_createFromFile("SuperLegendBoy.ttf");
    if (!font)
        return EXIT_FAILURE;
    text = sfText_create();
    sfText_setString(text, "Hello SFML");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    /* Load a music to play */
    /* Start the game loop */

    PS_State *state = init_menu_state();
    state->load(&state);

    while (sfRenderWindow_isOpen(window))
    {
        /* Process events */
        while (sfRenderWindow_pollEvent(window, &event))
        {
            /* Close window : exit */
            if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
        }
        /* Clear the screen */
        sfRenderWindow_clear(window, sfBlack);

        // Update the game state
		state->update(&state, event);
        state->draw(&state, window);

        /* Draw the sprite */
        /*sfRenderWindow_drawSprite(window, sprite, NULL);
        // Draw the text
        sfRenderWindow_drawText(window, text, NULL);*/





        /* Update the window */
        sfRenderWindow_display(window);
    }

    state->destroy(&state);
    /* Cleanup resources */
    // sfMusic_destroy(music);
    sfText_destroy(text);
    sfFont_destroy(font);
    // sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}
