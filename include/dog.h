#ifndef DOG_H
#define DOG_H

#include "raylib.h"

typedef struct {
    int x;
    int y;
    int scale;
    Color color;
    const int (*sprite);
} Dog;

void initDog(Dog *d, int x, int y, int scale, Color color);

#endif