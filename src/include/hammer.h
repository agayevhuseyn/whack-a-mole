#ifndef HAMMER_H
#define HAMMER_H
#include "raylib.h"
#include <stdlib.h>

typedef struct Hammer
{
    enum
    {
        UP,
        DOWN
    } state;
    Vector2 pos;
    Vector2 size;
    Texture2D hammer_tex[2];
    float anim_duration;
    float time_passed;
} Hammer;

Hammer* init_hammer(Vector2 size, float anim_duration, Texture2D* textures);
void update_hammer(Hammer* hammer);
void draw_hammer(Hammer* hammer);


#endif