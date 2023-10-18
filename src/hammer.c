#include "include/hammer.h"
#include "include/game.h"

Hammer* init_hammer(Vector2 size, float anim_duration ,Texture2D* textures)
{
    Hammer* hammer = calloc(1, sizeof(Hammer));

    hammer->state = UP;
    hammer->pos = (Vector2){ 0, 0 };
    hammer->size.x = size.x * SIZE_MULTIPLIER;
    hammer->size.y = size.y * SIZE_MULTIPLIER;
    hammer->hammer_tex[0] = textures[0];
    hammer->hammer_tex[1] = textures[1];
    hammer->anim_duration = anim_duration;
    hammer->time_passed = 0;

    return hammer;
}
void update_hammer(Hammer* hammer)
{
    hammer->pos.x = GetMouseX() - hammer->size.x/2 - 16;
    hammer->pos.y = GetMouseY() - hammer->size.y/2 + 16;

    if(IsMouseButtonReleased(0)) hammer->state = DOWN;
    if(hammer->state == UP) return;
    
    if(hammer->time_passed < hammer->anim_duration)
    {
        hammer->time_passed += GetFrameTime();
    }
    else
    {
        hammer->state = UP;
        hammer->time_passed = 0.0f;
    }
}
void draw_hammer(Hammer* hammer)
{
    DrawTextureEx(hammer->hammer_tex[hammer->state], hammer->pos, 0, SIZE_MULTIPLIER, WHITE);
}