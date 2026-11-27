#include "raylib.h"

const int mascota[16][16] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0},
    {0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0},
    {0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

void DibujarSprite(const int sprite[16][16], int posX, int posY, int escala, Color color) {
    for (int fila = 0; fila < 16; fila++) {
        for (int col = 0; col < 16; col++) {
            if (sprite[fila][col] == 1) {
                DrawRectangle(
                    posX + (col * escala), 
                    posY + (fila * escala), 
                    escala, 
                    escala, 
                    color
                );
            }
        }
    }
}

int main(void) {
    InitWindow(360, 620, "x_X");
    SetTargetFPS(60);

    Color fondoLCD = { 155, 188, 15, 255 };
    Color pixelLCD = { 15, 56, 15, 255 };

    int escala = 5;
    int posX = (360 - (16 * escala)) / 2;
    int posY = (360 + (16 * escala)) / 2;

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(fondoLCD);
            DibujarSprite(mascota, posX, posY, escala, pixelLCD);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}