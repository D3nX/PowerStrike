#include <SFML/Graphics.h>
#include "powerstrike.h"
#include "rendertexture.h"

PS_RenderTex *load_rendertex(char const *path, const sfIntRect *area)
{
    PS_RenderTex *tex = malloc(sizeof(PS_RenderTex));
    tex->texture = sfTexture_createFromFile(path, area);
    tex->sprite = sfSprite_create();
    sfSprite_setTexture(tex->sprite, tex->texture, sfTrue);

    return tex;
}