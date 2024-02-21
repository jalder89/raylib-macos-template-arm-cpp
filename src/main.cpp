#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include "view.h"

int main()
{
    // Initial window viewport setup. Check View for scaling
    View Viewport;                          
    InitWindow(Viewport.Width, Viewport.Height, "A New Window");

    float deltaTime = 0.f;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        deltaTime = GetFrameTime();

        if(IsKeyDown(KEY_A))
        {
            if(deltaTime > 0.002)
            {
                std::cout << "Frame Time Spike: " << deltaTime << std::endl;
            } else 
            {
                std::cout << "Frame Time: " << deltaTime << std::endl;
            }
        }

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}