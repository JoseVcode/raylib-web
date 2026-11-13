#include "raylib.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#pragma GCC diagnostic pop

typedef struct {
    int valor;
    int cantidad;
    Color color;
    Rectangle rect;
} Billete;

int main(void) {
    InitWindow(360, 600, "Corte de Caja");
    SetTargetFPS(60);

    Billete billetes[6] = {
        { 20, 0, BLUE,      { 20,  80, 150, 80 } },
        { 50, 0, RED,       { 190,  80, 150, 80 } },
        { 100, 0, SKYBLUE,  { 20,  170, 150, 80 } },
        { 200, 0, LIME,     { 190, 170, 150, 80 } },
        { 500, 0, ORANGE,   { 20, 260, 150, 80 } },
        { 1000, 0, PURPLE,  { 190, 260, 150, 80 } }
    };

    bool modalAbierto = false;
    int billeteSeleccionado = -1;
    int cantidadTemporal = 0;
    bool editarCajaTexto = false;

    while (!WindowShouldClose()) {
        int totalGeneral = 0;
        for (int i = 0; i < 6; i++) {
            totalGeneral += billetes[i].valor * billetes[i].cantidad;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Ingresar Billetes", 80, 30, 20, DARKGRAY);

        for (int i = 0; i < 6; i++) {
            DrawRectangleRec(billetes[i].rect, billetes[i].color);
            DrawRectangleLinesEx(billetes[i].rect, 2, DARKGRAY);
            
            DrawText(TextFormat("$%d", billetes[i].valor), billetes[i].rect.x + 15, billetes[i].rect.y + 15, 24, BLACK);
            DrawText(TextFormat("Cant: %d", billetes[i].cantidad), billetes[i].rect.x + 15, billetes[i].rect.y + 50, 18, DARKGRAY);

            if (!modalAbierto && CheckCollisionPointRec(GetMousePosition(), billetes[i].rect)) {
                DrawRectangleLinesEx(billetes[i].rect, 4, RED);
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    billeteSeleccionado = i;
                    cantidadTemporal = billetes[i].cantidad;
                    modalAbierto = true;
                    editarCajaTexto = true;
                }
            }
        }

        DrawText(TextFormat("TOTAL EN CAJA: $%d", totalGeneral), 20, 370, 20, DARKGREEN);

        if (modalAbierto) {
            DrawRectangle(0, 0, 800, 600, Fade(BLACK, 0.5f));

            Rectangle ventanaModal = { 250, 180, 300, 200 };
            if (GuiWindowBox(ventanaModal, TextFormat("Billete de $%d", billetes[billeteSeleccionado].valor))) {
                modalAbierto = false;
            }

            GuiLabel((Rectangle){ 270, 220, 260, 20 }, "Ingresa la cantidad de billetes:");

            if (GuiValueBox((Rectangle){ 270, 250, 260, 35 }, NULL, &cantidadTemporal, 0, 9999, editarCajaTexto)) {
                editarCajaTexto = !editarCajaTexto;
            }

            if (GuiButton((Rectangle){ 270, 310, 120, 40 }, "Guardar")) {
                billetes[billeteSeleccionado].cantidad = cantidadTemporal;
                modalAbierto = false;
            }

            if (GuiButton((Rectangle){ 410, 310, 120, 40 }, "Cancelar")) {
                modalAbierto = false;
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}