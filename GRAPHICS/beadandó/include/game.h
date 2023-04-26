#ifndef GAME_H
#define GAME_H

#include "texture.h"
#include <stdbool.h>
#include <obj/model.h>

typedef struct GameObject
{
    Model model;
    GLuint texture_id;
    float x;
    float y;
    float z;
    float rotation;
    float scale;
} GameObject;
typedef struct GameSettings
{
    float lightingLevel;
    float speed;
    bool lock_camera;
    bool is_paused;
} GameSettings;
#endif /* GAME_H */