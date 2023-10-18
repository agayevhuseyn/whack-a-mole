#include "raylib.h"
#include "include/game.h"

int main()
{
    InitWindow(WIDTH, HEIGHT, TITLE);

    SetTargetFPS(FPS);

    SetExitKey(KEY_NULL);

    start();

    while(!WindowShouldClose())
    {
        update();

        BeginDrawing();

        ClearBackground((Color){ 54, 34, 11, 255});

        late_update();

        EndDrawing();
    }

    CloseWindow();

    finish();

    return 0;
}