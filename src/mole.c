#include "include/mole.h"
#include "include/game.h"
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

Mole* init_mole(Vector2 pos, Vector2 size, Texture2D* textures, float frame_dur)
{
    srand(rand()); // randomize seed
    Mole* mole = calloc(1, sizeof(Mole));

    mole->textures = textures;
    
    mole->pos = pos;
    mole->size.x = size.x * SIZE_MULTIPLIER;
    mole->size.y = size.y * SIZE_MULTIPLIER;
    mole->frame_dur = frame_dur;
    mole->state = UNDER;
    mole->reveal_time = (float)(rand() % 8) / 10 + 1;
    mole->current_frame = 0;
    mole->elapsed_frame_time = 0;
    mole->elapsed_idle_time = 0;
    mole->idle_time = (float)(rand() % 3) / 10 + 1;

    return mole;
}


void update_mole(Mole* mole)
{
    switch(mole->state)
    {
        case UNDER:
        {
            mole->elapsed_frame_time += GetFrameTime();
            if(mole->elapsed_frame_time >= mole->reveal_time)
            {
                mole->state = RISING;
                mole->elapsed_frame_time = 0;
            }
            break;
        }
        case RISING:
        {
            if(mole->current_frame < MOLE_ROSE_FRAME_INDEX)
            {
                mole->elapsed_frame_time += GetFrameTime();
                if(mole->elapsed_frame_time >= mole->frame_dur)
                {
                    mole->current_frame += 1;
                    mole->elapsed_frame_time = 0;
                }
            }
            else
            {
                mole->elapsed_frame_time = 0;
                mole->state = ABOVE;
            }
            break;
        }
        case ABOVE:
        {
            if(mole->elapsed_idle_time < mole->idle_time)
            {
                mole->elapsed_idle_time += GetFrameTime();
            }
            else
            {
                mole->state = GETIN;
                mole->current_frame = 11;
                mole->elapsed_idle_time = 0;
            }
            break;
        }
        case GETIN:
        {
            if(mole->current_frame < MOLE_MAX_FRAME_INDEX)
            {
                mole->elapsed_frame_time += GetFrameTime();
                if(mole->elapsed_frame_time >= mole->frame_dur)
                {
                    mole->current_frame += 1;
                    mole->elapsed_frame_time = 0;
                }
            }
            else
            {
                mole->elapsed_frame_time = 0;
                mole->state = UNDER;
                mole->current_frame = 0;
                mole->reveal_time = (float)(rand() % 41) / 10 + 1;
                mole->idle_time = (float)(rand() % 11) / 10 + 1;
            }
            break;
        }
        case HIT:
        {
            if(mole->current_frame < MOLE_GETIN_FRAME_INDEX)
            {
                mole->elapsed_frame_time += GetFrameTime();
                if(mole->elapsed_frame_time >= mole->frame_dur)
                {
                    mole->current_frame++;
                    mole->elapsed_frame_time = 0;
                }
            }
            else
            {
                mole->elapsed_frame_time = 0;
                mole->state = GETIN;
            }
            break;
        }
    }
}

void draw_mole(Mole* mole)
{
    DrawTextureEx(mole->textures[mole->current_frame], mole->pos, 0, SIZE_MULTIPLIER, WHITE);
}

bool is_hit(Mole* mole)
{
    if(mole->state != ABOVE) return false;

    if(GetMousePosition().x < mole->pos.x ||
    GetMousePosition().x > mole->pos.x + mole->size.x ||
    GetMousePosition().y < mole->pos.y ||
    GetMousePosition().y > mole->pos.y + mole->size.y
    ) return false;

    if(IsMouseButtonReleased(0))
    {
        return true;
    }
    return false;
}