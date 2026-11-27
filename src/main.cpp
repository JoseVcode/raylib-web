#include "raylib.h"
#include <string>

// Puedes usar clases y características modernas de C++ sin problema
class Pelota {
public:
    Vector2 posicion{ 400.0f, 225.0f };
    float radio = 25.0f;
    Color color = MAROON;

    void Dibujar() const {
        DrawCircleV(posicion, radio, color);
    }
};

int main() {
    // Variables nativas de C++
    constexpr int anchoPantalla = 800;
    constexpr int altoPantalla = 450;
    const std::string titulo = "Mi ventana en C++ con raylib";

    // 1. Inicializar ventana (usamos .c_str() porque raylib espera texto estilo C)
    InitWindow(anchoPantalla, altoPantalla, titulo.c_str());
    SetTargetFPS(60);

    Pelota miPelota;

    // 2. Bucle principal del juego
    while (!WindowShouldClose()) {
        // Actualizar lógica (mover la pelota con las flechas)
        if (IsKeyDown(KEY_RIGHT)) miPelota.posicion.x += 4.0f;
        if (IsKeyDown(KEY_LEFT))  miPelota.posicion.x -= 4.0f;

        // Dibujar en pantalla
        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            DrawText("Usa las flechas izquierda/derecha", 20, 20, 20, DARKGRAY);
            miPelota.Dibujar();
            
        EndDrawing();
    }

    // 3. Cerrar ventana y liberar recursos
    CloseWindow();
    return 0;
}