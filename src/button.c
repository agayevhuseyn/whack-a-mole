#include "include/button.h"
#include "include/game.h"

Button* init_button(Vector2 size, Vector2 pos, Texture tex_0, Texture tex_1)
{
    Button* button = calloc(1, sizeof(Button));

    button->pos = pos;
    button->size.x = size.x * SIZE_MULTIPLIER;
    button->size.y = size.y * SIZE_MULTIPLIER;
    button->state = STILL;
    button->textures[0] = tex_0;
    button->textures[1] = tex_1;

    return button;
}

bool is_button_pressed(Button* button)
{
    if(GetMousePosition().x < button->pos.x ||
    GetMousePosition().x > button->pos.x + button->size.x ||
    GetMousePosition().y < button->pos.y ||
    GetMousePosition().y > button->pos.y + button->size.y
    )
    {
        if(button->state == HOLD) button->state = STILL;
        return false;
    }
    if(IsMouseButtonPressed(0) && button->state == STILL)
    {
        button->state = HOLD;
    }
    else if(IsMouseButtonReleased(0) && button->state == HOLD)
    {
        button->state = STILL;
        return true;
    }
    return false;
}

void draw_button(Button* button)
{
    DrawTextureEx(button->textures[button->state], button->pos, 0, SIZE_MULTIPLIER, WHITE);
}