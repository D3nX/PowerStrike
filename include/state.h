#include "powerstrike.h"
#include <SFML/Graphics.h>

#ifndef __STATE_H_
#define __STATE_H_

typedef struct _PS_State {
    void (*load)(struct PS_State*);
    void (*update)(struct PS_State*, sfEvent);
    void (*draw)(struct PS_State*, sfRenderWindow*);
    void (*destroy)(struct PS_State*);
} PS_State;

#endif
