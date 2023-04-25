#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>
#include <obj/transform.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <omp.h>

void init_scene(Scene *scene)
{
    // raptor
    load_model(&(scene->raptor), "assets/models/raptor.obj");
    scene->raptor_texture_id = load_texture("assets/textures/raptor.png");
    scene->raptor_x = 1.20;
    scene->raptor_y = -1.0;
    scene->raptor_z = 0.0;
    scene->raptor_rotation = 0.0;

    // house
    load_model(&(scene->house), "assets/models/house.obj");
    scene->house_texture_id = load_texture("assets/textures/house.jpg");

    // sun
    load_model(&(scene->sun), "assets/models/geoid.obj");
    scene->sun_texture_id = load_texture("assets/textures/sun.png");
    scene->sun_rotation = 0.0;
    scene->sun_x = 2.0f;
    scene->sun_y = scene->raptor_y / 2 + 2;
    scene->sun_z = 3.0f;

    // desert
    scene->desert_texture_id = load_texture("assets/textures/desert.jpg");

    // cactus
    load_model(&(scene->cactus), "assets/models/cactus.obj");
    scene->cactus_texture_id = load_texture("assets/textures/cactus.jpg");
    generate_random_cactus(scene);

    // material
    scene->material.ambient.red = 0.0;
    scene->material.ambient.green = 0.0;
    scene->material.ambient.blue = 0.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 0.0;
    scene->material.specular.green = 0.0;
    scene->material.specular.blue = 0.0;

    scene->material.shininess = 0.0;

    // camera
    scene->lock_camera = true;

    // help
    scene->help = false;

    // speed
    scene->speed = 1.2;

    glEnable(GL_FOG);
    glFogf(GL_FOG_DENSITY, 0.25f);
}

void set_lighting()
{
    float ambient_light[] = {1.0f, 1.0f, 1.0f, 1.0f};
    float diffuse_light[] = {1.0f, 1.0f, 1.0, 1.0f};
    float specular_light[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float position[] = {0.0f, 100.0f, 10.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material *material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue};

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue};

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue};

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene *scene)
{
    scene->current_time = (double)SDL_GetTicks() / 1000;
    scene->raptor_y += scene->speed * (scene->current_time - scene->last_time);
    scene->sun_rotation = scene->current_time * 180 / 3.14;
    scene->sun_y = scene->raptor_y / 2 + 2;
    if (scene->raptor_y > 35.0)
    {
        scene->speed *= 1.2;
        generate_random_cactus(scene);
        scene->raptor_y = -1.0;
    }
    for (size_t i = 0; i <= 20; i++)
    {
        if (scene->raptor_y > scene->cactus_distance_y[i] / 5 - 0.5 && scene->raptor_y < scene->cactus_distance_y[i] / 5 + 0.5)
        {
            if (scene->raptor_x == scene->cactus_distance_x[i])
            {
                printf("Game Over\n");
                // exit(0);
            }
        }
    }

    scene->last_time = scene->current_time;
}
void generate_random_cactus(Scene *scene)
{
    float distance = 15.0;
    srand(time(NULL));
    for (int i = 0; i <= 20; i += 2)
    {
        int r = (rand() % 3) + 1;
        if (r == 1)
            scene->cactus_distance_x[i] = 0.6;
        else if (r == 2)
            scene->cactus_distance_x[i] = 1.8;
        else if (r == 3)
            scene->cactus_distance_x[i] = 1.2;

        r = (rand() % 3) + 1;
        if (r == 1)
            scene->cactus_distance_x[i + 1] = 0.6;
        else if (r == 2)
            scene->cactus_distance_x[i + 1] = 1.8;
        else if (r == 3)
            scene->cactus_distance_x[i + 1] = 1.2;

        scene->cactus_distance_y[i] = distance;
        scene->cactus_distance_y[i + 1] = distance;
        distance += 15.0f;
    }
}
void render_scene(const Scene *scene)
{
    if (scene->help)
    {
        help(scene->raptor_texture_id);
    }
    else
    {
        update_scene(scene);
        set_lighting();
        set_material(&(scene->material));
        draw_raptor(scene);
        draw_desert(scene);
        draw_house(scene);
        draw_cactus(scene);

        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->sun_texture_id);
        draw_model(&(scene->sun), scene->sun_x, scene->sun_y, scene->sun_z);
        glPopMatrix();
    }
}
void set_left_dino(Scene *scene)
{
    scene->raptor_x = 0.6;
}
void set_right_dino(Scene *scene)
{
    scene->raptor_x = 1.80;
}
void set_center_dino(Scene *scene)
{
    scene->raptor_x = 1.20;
}
void togle_camera_lock(Scene *scene)
{
    if (scene->lock_camera)
        scene->lock_camera = false;
    else
        scene->lock_camera = true;
    printf("camera lock: %d\n", scene->lock_camera);
}
void togle_help(Scene *scene)
{
    if (scene->help)
        scene->help = false;
    else
        scene->help = true;
    printf("help: %d\n", scene->help);
}
bool is_camera_locked(const Scene *scene)
{
    return scene->lock_camera;
}
float *get_camera_position(const Scene *scene)
{
    static float camera_position[3];
    camera_position[0] = 1.2 * 0.4;
    camera_position[1] = scene->raptor_y * 0.5 - 1.5;
    camera_position[2] = scene->raptor_z + 0.8;
    return camera_position;
}
void draw_cactus(Scene *scene)
{
    srand(time(NULL));
    for (int i = 0; i <= 20; i++)
    {
        if (scene->cactus_distance_y[i] / 5 > scene->raptor_y - 9.0f && scene->cactus_distance_y[i] / 5 < scene->raptor_y + 9.0f)
        {
            float y = scene->cactus_distance_y[i] * -1;
            float pos_x = 0;
            if (scene->cactus_distance_x[i] == 0.6f)
            {
                pos_x = 2.0;
            }
            else if (scene->cactus_distance_x[i] == 1.2f)
            {
                pos_x = 4.9f;
            }
            else if (scene->cactus_distance_x[i] == 1.8f)
            {
                pos_x = 7.4f;
            }
            glPushMatrix();
            glBindTexture(GL_TEXTURE_2D, scene->cactus_texture_id);
            glScalef(0.1, 0.1, 0.1);
            glRotatef(90, 1, 0, 0);
            draw_model(&(scene->cactus), pos_x, 0.0f, y);
            glPopMatrix();
        }
    }
}
void draw_house(const Scene *scene)
{
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->house_texture_id);
    glRotatef(90, 1, 0, 0);
    glRotatef(180, 0, 1, 0);
    glScalef(0.005, 0.005, 0.005);
    draw_model(&(scene->house), 250.0f, 25.0f, 800.0f);
    glPopMatrix();
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->house_texture_id);
    glRotatef(90, 1, 0, 0);
    glRotatef(180, 0, 1, 0);
    glScalef(0.005, 0.005, 0.005);
    draw_model(&(scene->house), 250.0f, 25.0f, 3500.0f);
    glPopMatrix();
}
void draw_raptor(const Scene *scene)
{
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->raptor_texture_id);
    glScalef(0.5, 0.5, 0.5);
    draw_model(&(scene->raptor), scene->raptor_x, scene->raptor_y, scene->raptor_z);
    glPopMatrix();
}
void help(GLuint texture)
{
    glDisable(GL_FOG);
    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3d(-2, 1.5, -3);
    glTexCoord2f(1, 0);
    glVertex3d(2, 1.5, -3);
    glTexCoord2f(1, 1);
    glVertex3d(2, -1.5, -3);
    glTexCoord2f(0, 1);
    glVertex3d(-2, -1.5, -3);
    glEnd();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_FOG);
}
void draw_desert(const Scene *scene)
{
    glBindTexture(GL_TEXTURE_2D, scene->desert_texture_id);
    glBegin(GL_QUADS);
    glPushMatrix();
    for (int i = -2; i < 25; i++)
    {
        for (int j = -5; j <= 5; j++)
        {
            glTexCoord2f(0, 1);
            glVertex3f(j, i, 0);

            glTexCoord2f(1, 1);
            glVertex3f(j + 1, i, 0);

            glTexCoord2f(1, 0);
            glVertex3f(j + 1, i + 1, 0);

            glTexCoord2f(0, 0);
            glVertex3f(j, i + 1, 0);
        }
    }
    glPopMatrix();
    glEnd();
}