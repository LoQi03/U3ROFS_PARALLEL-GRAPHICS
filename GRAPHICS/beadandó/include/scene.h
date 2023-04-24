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
    GLuint raptor_texture_id;

    // road
    GLuint road_texture_id;

    // desert
    GLuint desert_texture_id;

    // cactus
    Model cactus;
    GLuint cactus_texture_id;
    float cactus_distance_x[30];
    float cactus_distance_y[30];

    // house
    Model house;
    GLuint house_texture_id;

    // sun
    Model sun;
    GLuint sun_texture_id;
    float sun_x;
    float sun_y;
    float sun_z;
    float sun_rotation;
    
    // camera
    bool lock_camera;
    // help
    bool help;
    // time
    double current_time;
    double last_time;
    // speed
    float speed;
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
void draw_cactus(Scene *scene);
void draw_raptor(const Scene *scene);
void draw_house(const Scene *scene);
/**
 * Draw the help.
 */
void togle_help(Scene *scene);

/**
 * Camera lock.
 */
void togle_camera_lock(Scene *scene);
#endif /* SCENE_H */
