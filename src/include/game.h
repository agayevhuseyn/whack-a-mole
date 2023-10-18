#ifndef GAME_H
#define GAME_H
#include "mole.h"
#include "hammer.h"
#define WIDTH 720
#define HEIGHT 540
#define TITLE "WHACK-A-MOLE"
#define FPS 60
#define SIZE_MULTIPLIER 8
#define MOLE_SPACING_OUT 32
#define MOLE_ROSE_FRAME_INDEX 4
#define MOLE_HIT_FRAME_INDEX 5
#define MOLE_GETIN_FRAME_INDEX 11
#define MOLE_MAX_FRAME_INDEX 15

void start();
void update();
void late_update();
void finish();

#endif