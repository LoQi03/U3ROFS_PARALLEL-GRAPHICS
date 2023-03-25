#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include <obj/model.h>

typedef struct Scene
{
    Model raptor;
    float raptor_x;
    float raptor_y;
    float raptor_z;
    float raptor_rotation;
    GLuint raptor_texture_id;
    GLuint road_texture_id;
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
