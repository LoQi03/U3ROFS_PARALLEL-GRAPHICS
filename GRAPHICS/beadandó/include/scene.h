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
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

#endif /* SCENE_H */
