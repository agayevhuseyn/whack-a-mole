#ifndef BUTTON_H
#define BUTTON_H
#include "raylib.h"
#include <stdlib.h>

typedef struct Button
{
    enum
    {
        STILL,
        HOLD
    } state;
    Vector2 pos;
    Vector2 size;
    Texture2D textures[2];

} Button;

Button* init_button(Vector2 size, Vector2 pos, Texture tex_0, Texture tex_1);
bool is_button_pressed(Button* button);
void draw_button(Button* button);

#endif