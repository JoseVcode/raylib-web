#include "sprite.h"

void drawSprite(const int sprite[16][16], int posX, int posY, int escala, Color color) {
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