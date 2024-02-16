#include <raylib.h>
#include <raymath.h>

int main()
{
    InitWindow(400, 224, "A New Window");

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
    
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}