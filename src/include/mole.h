#ifndef MOLE_H
#define MOLE_H
#include "raylib.h"
#include <stdlib.h>


typedef enum MOLE_STATE
{
    UNDER,
    RISING,
    ABOVE,
    HIT,
    GETIN
} MOLE_STATE;

typedef struct Mole
{
    Vector2 pos;
    Vector2 size;
    MOLE_STATE state;
    Texture2D* textures;
    float frame_dur;
    unsigned int current_frame;
    float idle_time;
    float elapsed_idle_time;
    float elapsed_frame_time;
    float reveal_time;
} Mole;

Mole* init_mole(Vector2 pos, Vector2 size, Texture2D* textures, float frame_dur);

void update_mole(Mole* mole);

void draw_mole(Mole* mole);

bool is_hit(Mole* mole);

#endif