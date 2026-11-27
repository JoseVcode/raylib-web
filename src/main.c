#include "raylib.h"
#include "dog.h"

int main(void) {
    InitWindow(360, 620, "DogPet");
    SetTargetFPS(60);

    Color fondoLCD = { 155, 188, 15, 255 };
    Color pixelLCD = { 15, 56, 15, 255 };

    int escala = 5;
    int posX = (360 - (16 * escala)) / 2;
    int posY = (360 + (16 * escala)) / 2;

    Dog perro;
    initDog(&perro, posX, posY, escala, pixelLCD);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(fondoLCD);
            drawSprite(perro.sprite, perro.x, perro.y, perro.scale, perro.color);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}