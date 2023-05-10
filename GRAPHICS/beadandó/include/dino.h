#ifndef DINO_H
#define DINO_H
#include "game.h"

typedef struct dino
{
    GameObject object;
    float target_x;
    float hp;
} Dino;

#endif /* GAME_H */