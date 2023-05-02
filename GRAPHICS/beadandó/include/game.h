#ifndef GAME_H
#define GAME_H

#include "texture.h"
#include <stdbool.h>
#include <obj/model.h>
#include <time.h>
#include "utils.h"

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
    bool is_over;
} GameSettings;

void generate_random_cactus(GameObject *cactuses);
void init_cactuses(GameObject *cactuses);
void init_material(Material *material);

#endif /* GAME_H */