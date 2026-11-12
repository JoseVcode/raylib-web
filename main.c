#include "raylib.h"

int main(void) {
    InitWindow(360, 640, "Juego Celular");
    SetTargetFPS(60);
    Vector2 pos = { 180, 320 };

    while (!WindowShouldClose()) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) pos = GetMousePosition();
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Toca la pantalla!", 80, 40, 20, DARKGRAY);
            DrawCircleV(pos, 35, RED);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
