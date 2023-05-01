#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include "game.h"
#include "dino.h"
#include <obj/model.h>
#include <stdbool.h>

typedef struct Scene
{
    Dino raptor;
    GameObject sun;
    GameObject cactuses[30];
    GameObject houses[3];
    GameSettings settings;
    GLuint desert_texture_id;
    double current_time;
    double last_time;
    Material material;
} Scene;

void set_lighting(float lightingLevel, float x, float y, float z);
/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene *scene);

/**
 * Update the scene.
 */
void update_scene(Scene *scene);

/**
 * Render the scene objects.
 */
void render_scene(const Scene *scene);

/**
 * Draw objects.
 */
void draw_road(const Scene *scene);
void draw_desert(const Scene *scene);
void draw_cactus(Scene *scene);
void draw_raptor(const Scene *scene);
void draw_house(const Scene *scene);
void draw_sun(Scene *scene);
/**
 * Draw the help.
 */
void togle_help(Scene *scene);

/**
 * Camera lock.
 */
void togle_camera_lock(Scene *scene);
#endif /* SCENE_H */
