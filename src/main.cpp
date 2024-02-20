#include <raylib.h>
#include <raymath.h>
#include "view.h"

int main()
{
    // Initial window viewport setup. Check View for scaling
    View Viewport;                          
    InitWindow(Viewport.Width, Viewport.Height, "A New Window");
    SetTargetFPS(120);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}