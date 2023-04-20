#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include <obj/model.h>
#include <stdbool.h>

typedef struct Scene
{
    // raptor
    Model raptor;
    float raptor_x;
    float raptor_y;
    float raptor_z;
    float raptor_rotation;

    float cactus_distance_x[50];
    float cactus_distance_y[50];

    float light_y;
    GLuint raptor_texture_id;
    // road
    GLuint road_texture_id;
    // desert
    GLuint desert_texture_id;
    // cactus
    Model cactus;
    GLuint cactus_texture_id;
    // camera
    bool lock_camera;
    // material
    Material material;
} Scene;

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
void draw_cactus(const Scene *scene);
void draw_raptor(const Scene *scene);

#endif /* SCENE_H */
