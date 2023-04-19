#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>
#include <obj/transform.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double current_time = 0.0;
double last_time = 0.0;
float cactus[50];
void init_scene(Scene *scene)
{
    // raptor
    load_model(&(scene->raptor), "assets/models/raptor.obj");
    scene->raptor_texture_id = load_texture("assets/textures/raptor.png");
    scene->raptor_x = 1.20;
    scene->raptor_y = 1.0;
    scene->raptor_z = 0.0;
    scene->raptor_rotation = 0.0;

    // road
    scene->road_texture_id = load_texture("assets/textures/road.png");

    // desert
    scene->desert_texture_id = load_texture("assets/textures/desert.jpg");

    // cactus
    load_model(&(scene->cactus), "assets/models/cactus.obj");
    scene->cactus_texture_id = load_texture("assets/textures/cactus.png");

    srand(time(NULL));
    for (int i = 0; i < 50; i++)
    {
        cactus[i] = ((float)rand() / (float)(RAND_MAX)) * 3.0f;
    }

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

    // light
    scene->light_y = 0.0f;

    // camera
    scene->lock_camera = true;
}

void set_lighting(float light_y)
{
    float ambient_light[] = {1.0f, 1.0f, 1.0f, 1.0f};
    float diffuse_light[] = {1.0f, 1.0f, 1.0, 1.0f};
    float specular_light[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float position[] = {0.0f, 50.0f, 10.0f, 1.0f};

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
    current_time = (double)SDL_GetTicks() / 1000;
    scene->raptor_y += 1.0 * (current_time - last_time);
    scene->light_y = scene->raptor_y + 1.0;
    last_time = current_time;
}
void render_scene(const Scene *scene)
{
    update_scene(scene);
    set_lighting(scene->light_y);
    set_material(&(scene->material));

    // draw raptor
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->raptor_texture_id);
    glScalef(0.5, 0.5, 0.5);
    draw_model(&(scene->raptor), scene->raptor_x, scene->raptor_y, scene->raptor_z);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // draw field
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, scene->road_texture_id);
    glBegin(GL_QUADS);
    for (int i = 0; i < 100; i++)
    {
        glEnable(GL_TEXTURE_2D);
        glTexCoord2f(0, 1);
        glVertex3f(0, i, 0);

        glTexCoord2f(1, 1);
        glVertex3f(1, i, 0);

        glTexCoord2f(1, 0);
        glVertex3f(1, i + 1, 0);

        glTexCoord2f(0, 0);
        glVertex3f(0, i + 1, 0);
        glDisable(GL_TEXTURE_2D);
    }
    glEnd();
    // draw desert
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, scene->desert_texture_id);
    glBegin(GL_QUADS);
    for (int i = 0; i < 100; i++)
    {
        for (int j = -5; j <= 5; j++)
        {
            glEnable(GL_TEXTURE_2D);
            glTexCoord2f(0, 1);
            glVertex3f(j, i, 0);

            glTexCoord2f(1, 1);
            glVertex3f(j + 1, i, 0);

            glTexCoord2f(1, 0);
            glVertex3f(j + 1, i + 1, 0);

            glTexCoord2f(0, 0);
            glVertex3f(j, i + 1, 0);
            glDisable(GL_TEXTURE_2D);
        }
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
    // draw cactus
    glBindTexture(GL_TEXTURE_2D, GL_DIFFUSE);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glScalef(0.2, 0.2, 0.2);
    glRotatef(90, 1, 0, 0);
    draw_model(&(scene->cactus), 0.5f, 1.0f, -0.5f);
    glColor3f(0.0, 1.0, 0.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
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
void togle_camera(Scene *scene)
{
    if (scene->lock_camera)
        scene->lock_camera = false;
    else
        scene->lock_camera = true;
    printf("camera lock: %d\n", scene->lock_camera);
}
bool is_camera_locked(const Scene *scene)
{
    return scene->lock_camera;
}
float *get_camera_position(const Scene *scene)
{
    static float camera_position[3];
    camera_position[0] = 1.2 * 0.4;
    camera_position[1] = scene->raptor_y * 0.5 - 1;
    camera_position[2] = scene->raptor_z + 0.8;
    return camera_position;
}
void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
