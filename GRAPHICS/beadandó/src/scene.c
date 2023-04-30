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
    load_model(&(scene->raptor.model), "assets/models/raptor.obj");
    scene->raptor.texture_id = load_texture("assets/textures/raptor.png");
    scene->raptor.x = 1.20;
    scene->raptor.y = -2.0;
    scene->raptor.z = 0.0;
    scene->raptor.rotation = 0.0;

    for (int i = 0; i < 3; i++)
    {
        load_model(&(scene->houses[i].model), "assets/models/house.obj");
        scene->houses[i].texture_id = load_texture("assets/textures/house.jpg");
        scene->houses[i].scale = 0.005;
    }
    // sun
    load_model(&(scene->sun.model), "assets/models/geoid.obj");
    scene->sun.texture_id = load_texture("assets/textures/sun.png");
    scene->sun.rotation = 0.0;
    scene->sun.x = 2.0f;
    scene->sun.y = scene->raptor.y / 2 + 6;
    scene->sun.z = 4.0f;

    // desert
    scene->desert_texture_id = load_texture("assets/textures/desert.jpg");
    for (int i = 0; i < 30; i++)
    {
        load_model(&(scene->cactuses[i].model), "assets/models/cactus.obj");
        scene->cactuses[i].texture_id = load_texture("assets/textures/cactus.jpg");
    }
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

    scene->settings.lock_camera = true;
    scene->settings.lightingLevel = 1.0f;
    scene->settings.is_paused = false;
    scene->settings.speed = 1.2;
    glEnable(GL_FOG);
    glFogf(GL_FOG_DENSITY, 0.35f);
}

void set_lighting(float lightingLevel, float x, float y, float z)
{
    float ambient_light[] = {lightingLevel, lightingLevel, lightingLevel, 1.0f};
    float diffuse_light[] = {lightingLevel, lightingLevel, lightingLevel, 1.0f};
    float specular_light[] = {lightingLevel, lightingLevel, lightingLevel, 1.0f};
    float position[] = {x + 2, y - 1, z, 1.0f};

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
    if (scene->settings.is_paused)
    {
        return;
    }
    scene->current_time = (double)SDL_GetTicks() / 1000;
    scene->raptor.y += scene->settings.speed * (scene->current_time - scene->last_time);
    scene->sun.rotation = scene->current_time * 180 / 3.14;
    scene->sun.y = scene->raptor.y / 2 + 6;
    if (scene->raptor.y > 35.0)
    {
        scene->settings.speed *= 1.2;
        generate_random_cactus(scene);
        scene->raptor.y = -1.0;
    }
    for (size_t i = 0; i <= 20; i++)
    {
        if (scene->raptor.y > scene->cactuses[i].y / 5 - 0.5 && scene->raptor.y < scene->cactuses[i].y / 5 + 0.5)
        {
            if (scene->raptor.x == scene->cactuses[i].x)
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
            scene->cactuses[i].x = 0.6;
        else if (r == 2)
            scene->cactuses[i].x = 1.8;
        else if (r == 3)
            scene->cactuses[i].x = 1.2;

        r = (rand() % 3) + 1;
        if (r == 1)
            scene->cactuses[i + 1].x = 0.6;
        else if (r == 2)
            scene->cactuses[i + 1].x = 1.8;
        else if (r == 3)
            scene->cactuses[i + 1].x = 1.2;

        scene->cactuses[i].y = distance;
        scene->cactuses[i + 1].y = distance;
        distance += 15.0f;
    }
}
void render_scene(const Scene *scene)
{
    if (scene->settings.is_paused)
    {
        glDisable(GL_LIGHTING);
        help(scene->raptor.texture_id);
    }
    else
    {
        glEnable(GL_LIGHTING);
        set_lighting(scene->settings.lightingLevel, scene->sun.x, scene->sun.y, scene->sun.z);
        update_scene(scene);
        set_material(&(scene->material));

        draw_raptor(scene);
        draw_desert(scene);
        draw_house(scene);

        draw_cactus(scene);
        draw_sun(scene);
    }
}
void set_left_dino(Scene *scene)
{
    scene->raptor.x = 0.6;
}
void set_right_dino(Scene *scene)
{
    scene->raptor.x = 1.80;
}
void set_center_dino(Scene *scene)
{
    scene->raptor.x = 1.20;
}
void togle_camera_lock(Scene *scene)
{
    if (scene->settings.lock_camera)
        scene->settings.lock_camera = false;
    else
        scene->settings.lock_camera = true;
    printf("camera lock: %d\n", scene->settings.lock_camera);
}
void togle_help(Scene *scene)
{
    if (scene->settings.is_paused)
        scene->settings.is_paused = false;
    else
        scene->settings.is_paused = true;
    printf("help: %d\n", scene->settings.is_paused);
}
bool is_camera_locked(const Scene *scene)
{
    return scene->settings.lock_camera;
}
float *get_camera_position(const Scene *scene)
{
    static float camera_position[3];
    camera_position[0] = 1.2 * 0.4;
    camera_position[1] = scene->raptor.y * 0.5 - 1.5;
    camera_position[2] = scene->raptor.z + 0.8;
    return camera_position;
}
void draw_sun(Scene *scene)
{
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->sun.texture_id);
    glTranslatef(scene->sun.x, scene->sun.y, scene->sun.z);
    glScalef(0.5, 0.5, 0.5);
    glRotatef(scene->sun.rotation, 0, 0, 1);
    draw_model(&(scene->sun.model));
    glPopMatrix();
}
void draw_cactus(Scene *scene)
{
    srand(time(NULL));
    for (int i = 0; i <= 20; i++)
    {
        if (scene->cactuses[i].y / 5 > scene->raptor.y - 12.0f && scene->cactuses[i].y / 5 < scene->raptor.y + 12.0f)
        {
            float y = scene->cactuses[i].y * -1;
            float pos_x = 0;
            if (scene->cactuses[i].x == 0.6f)
            {
                pos_x = 2.0;
            }
            else if (scene->cactuses[i].x == 1.2f)
            {
                pos_x = 4.9f;
            }
            else if (scene->cactuses[i].x == 1.8f)
            {
                pos_x = 7.4f;
            }
            glPushMatrix();
            glBindTexture(GL_TEXTURE_2D, scene->cactuses[i].texture_id);
            glScalef(0.1, 0.1, 0.1);
            glRotatef(90, 1, 0, 0);
            glTranslatef(pos_x, 0, y);
            draw_model(&(scene->cactuses[i].model));
            glPopMatrix();
        }
    }
}
void draw_house(const Scene *scene)
{
    float y = 800.0f;
    for (int i = 0; i < 3; i++)
    {
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->houses[i].texture_id);
        glRotatef(90, 1, 0, 0);
        glRotatef(180, 0, 1, 0);
        glScalef(scene->houses[i].scale, scene->houses[i].scale, scene->houses[i].scale);
        glTranslatef(250.0f, 25.0f, y);
        draw_model(&(scene->houses[i].model));
        glPopMatrix();
        y += 1000.0f;
    }
}
void draw_raptor(const Scene *scene)
{
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->raptor.texture_id);
    glScalef(0.5, 0.5, 0.5);
    glTranslatef(scene->raptor.x, scene->raptor.y, scene->raptor.z);
    draw_model(&(scene->raptor.model));
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
    for (int i = -2; i < 30; i++)
    {
        if (i > scene->raptor.y / 2 - 6.0f && i < scene->raptor.y / 2 + 6.0f)
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
    }
    glPopMatrix();
    glEnd();
}