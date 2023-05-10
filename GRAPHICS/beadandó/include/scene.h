#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include "game.h"
#include "dino.h"
#include <obj/model.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <obj/load.h>
#include <obj/draw.h>
#include <obj/transform.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Scene
{
    Dino raptor;
    GameObject sun;
    GameObject cactuses[20];
    GameObject house;
    GameSettings settings;
    GLuint heart_texture_id;
    GLuint description_texture_id;
    GLuint game_over_texture_id;
    GLuint desert_texture_id;
    GLuint display_list;
    float last_cactus_distance;
    int health;
    double current_time;
    double last_time;
    double elapsed_time;
    float fogColor[4];
    float fogColorChangedTime;
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
void draw_house(Scene *scene);
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
