#include "include/game.h"
#include <stdio.h>

Mole** moles;
Hammer* hammer;
Texture2D* mole_textures;
Texture2D* hammer_textures;
unsigned short score = 0;

Font font;

void start()
{
    HideCursor();
    
    font = LoadFontEx("assets/fonts/PixelifySans-Medium.ttf", 48, NULL, 95);

    moles = calloc(6, sizeof(Mole*));

    hammer_textures = calloc(2, sizeof(Texture2D));
    hammer_textures[0] = LoadTexture("assets/hammer_0.png");
    hammer_textures[1] = LoadTexture("assets/hammer_1.png");

    hammer = init_hammer((Vector2){ 14, 15 }, 0.4f, hammer_textures);

    mole_textures = calloc(16, sizeof(Texture2D));

    mole_textures[0] = LoadTexture("assets/mole_0.png");
    mole_textures[1] = LoadTexture("assets/mole_1.png");
    mole_textures[2] = LoadTexture("assets/mole_2.png");
    mole_textures[3] = LoadTexture("assets/mole_3.png");
    mole_textures[4] = LoadTexture("assets/mole_4.png");
    mole_textures[5] = LoadTexture("assets/mole_5.png");
    mole_textures[6] = LoadTexture("assets/mole_6.png");
    mole_textures[7] = LoadTexture("assets/mole_7.png");
    mole_textures[8] = LoadTexture("assets/mole_8.png");
    mole_textures[9] = LoadTexture("assets/mole_9.png");
    mole_textures[10] = LoadTexture("assets/mole_10.png");
    mole_textures[11] = LoadTexture("assets/mole_11.png");
    mole_textures[12] = LoadTexture("assets/mole_12.png");
    mole_textures[13] = LoadTexture("assets/mole_13.png");
    mole_textures[14] = LoadTexture("assets/mole_14.png");
    mole_textures[15] = LoadTexture("assets/mole_15.png");


    int x = 136;

    for(int i = 0; i < 6; i++)
    {
        moles[i] = init_mole((Vector2){ x, 110 + ((i>2) * 128 + MOLE_SPACING_OUT)}, (Vector2){ 16, 16}, mole_textures, 0.15f);

        x += 128 + MOLE_SPACING_OUT; // 136, 296, 456
        if(i == 2) x = 136;
    }
}

void update()
{
    char score_text[32];
    sprintf(score_text, "Mole counter: %d", score);

    for(int i = 0; i < 6; i++)
    {
        update_mole(moles[i]);
        if(is_hit(moles[i]) && hammer->state == UP)
        {
            hammer->state = DOWN;
            moles[i]->state = HIT;
            moles[i]->current_frame = MOLE_HIT_FRAME_INDEX;
            moles[i]->elapsed_frame_time = 0;
            moles[i]->elapsed_idle_time = 0;
            score++;
        }
    }
    update_hammer(hammer);
    DrawTextEx(font, score_text, (Vector2){ 20, 20 }, 48, 0, RAYWHITE);
}

void late_update()
{
    for(int i = 0; i < 6; i++)
    {
        draw_mole(moles[i]);
    }
    draw_hammer(hammer);
}

void finish()
{
    free(hammer);
    free(hammer_textures);
    free(moles);
    free(mole_textures);
}