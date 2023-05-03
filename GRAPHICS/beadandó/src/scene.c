#include "scene.h"
void init_scene(Scene *scene)
{
    scene->heart_texture_id = load_texture("assets/textures/heart.jpg");
    scene->description_texture_id = load_texture("assets/textures/descript.jpg");
    scene->game_over_texture_id = load_texture("assets/textures/death.jpg");
    // raptor
    load_model(&(scene->raptor.object.model), "assets/models/raptor.obj");
    scene->raptor.object.texture_id = load_texture("assets/textures/raptor.png");
    scene->raptor.object.x = 1.20;
    scene->raptor.object.y = -3.0;
    scene->raptor.object.z = 0.0;
    scene->raptor.object.rotation = 0.0;
    scene->raptor.hp = 12.0f;
    scene->raptor.object.scale = 0.5;
    scene->health = 4;

    // house
    load_model(&(scene->house.model), "assets/models/house.obj");
    scene->house.texture_id = load_texture("assets/textures/house.jpg");
    scene->house.y = 10.0f;
    scene->house.scale = 0.005;

    // sun
    load_model(&(scene->sun.model), "assets/models/geoid.obj");
    scene->sun.texture_id = load_texture("assets/textures/sun.png");
    scene->sun.rotation = 0.0;
    scene->sun.x = 2.0f;
    scene->sun.y = scene->raptor.object.y / 2 + 6;
    scene->sun.z = 4.0f;
    scene->sun.scale = 0.5;

    // desert
    scene->desert_texture_id = load_texture("assets/textures/desert.jpg");

    // cactus
    init_cactuses(scene->cactuses);
    generate_random_cactus(scene->cactuses);
    scene->last_cactus_distance = scene->cactuses[11].y;
    printf("last cactus distance: %f\n", scene->last_cactus_distance);
    // material
    init_material(&(scene->material));

    scene->settings.lock_camera = true;
    scene->settings.lightingLevel = 2.8f;
    scene->settings.is_paused = false;
    scene->settings.speed = 1.2;
    scene->settings.is_over = false;

    GLfloat fogColor[] = {0.2, 0.58, 0.92, 0.01};
    glEnable(GL_FOG);
    glFogf(GL_FOG_DENSITY, 0.40f);
    glFogfv(GL_FOG_COLOR, fogColor);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
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
    if (scene->settings.is_over)
    {
        scene->current_time = (double)SDL_GetTicks() / 1000;
        scene->last_time = scene->current_time;
        return;
    }
    set_lighting(scene->settings.lightingLevel, scene->sun.x, scene->sun.y, scene->sun.z);
    if (scene->settings.is_paused)
    {
        scene->current_time = (double)SDL_GetTicks() / 1000;
        scene->last_time = scene->current_time;
        return;
    }
    else
    {
        scene->current_time = (double)SDL_GetTicks() / 1000;
        scene->raptor.object.y += scene->settings.speed * (scene->current_time - scene->last_time);
        scene->sun.rotation = scene->current_time * 180 / 3.14;
        scene->sun.y = scene->raptor.object.y / 2 + 6;
        /* if (scene->raptor.object.y > 35.0)
        {
            scene->settings.speed *= 1.2;
            generate_random_cactus(scene->cactuses);
            scene->last_cactus_distance = scene->cactuses[11].y;
            scene->raptor.object.y = -1.0;
        }
        */
        for (size_t i = 0; i <= 20; i++)
        {
            if (scene->raptor.object.y > scene->cactuses[i].y / 5 - 0.05 && scene->raptor.object.y < scene->cactuses[i].y / 5 + 0.05)
            {
                if (scene->raptor.object.x == scene->cactuses[i].x)
                {
                    scene->raptor.hp -= 1.0;
                    printf("HP: %f\n", scene->raptor.hp);
                    if (scene->raptor.hp < 12.0)
                    {
                        scene->health = 3;
                    }
                    if (scene->raptor.hp < 8.0)
                    {
                        scene->health = 2;
                    }
                    if (scene->raptor.hp < 4.0)
                    {
                        scene->health = 1;
                    }
                    if (scene->raptor.hp < 0)
                    {
                        scene->health = 0;
                        scene->settings.is_over = true;
                    }
                }
            }
        }
        scene->last_time = scene->current_time;
    }
}

void render_scene(const Scene *scene)
{
    if (scene->settings.is_over)
    {
        glDisable(GL_LIGHTING);
        game_over(scene->game_over_texture_id);
    }
    else
    {
        if (scene->settings.is_paused)
        {
            glDisable(GL_LIGHTING);
            help(scene->description_texture_id);
        }
        else
        {
            update_scene(scene);
            set_material(&(scene->material));
            draw_raptor(scene);
            draw_desert(scene);
            draw_house(scene);
            draw_cactus(scene);
            draw_sun(scene);
            draw_hearts(scene->heart_texture_id, scene->health);
        }
    }
}
void set_left_dino(Scene *scene)
{
    scene->raptor.object.x = 0.6;
}
void set_right_dino(Scene *scene)
{
    scene->raptor.object.x = 1.80;
}
void set_center_dino(Scene *scene)
{
    scene->raptor.object.x = 1.20;
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
    camera_position[1] = scene->raptor.object.y * 0.5 - 1.5;
    camera_position[2] = scene->raptor.object.z + 0.8;
    return camera_position;
}
void draw_sun(Scene *scene)
{
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->sun.texture_id);
    glTranslatef(scene->sun.x, scene->sun.y, scene->sun.z);
    glScalef(scene->sun.scale, scene->sun.scale, scene->sun.scale);
    glRotatef(scene->sun.rotation, 0, 0, 1);
    draw_model(&(scene->sun.model));
    glPopMatrix();
}
void draw_raptor(const Scene *scene)
{
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->raptor.object.texture_id);
    glScalef(scene->raptor.object.scale, scene->raptor.object.scale, scene->raptor.object.scale);
    glTranslatef(scene->raptor.object.x, scene->raptor.object.y, scene->raptor.object.z);
    draw_model(&(scene->raptor.object.model));
    glPopMatrix();
}
void draw_cactus(Scene *scene)
{
    for (int i = 0; i < 12; i++)
    {
        if (scene->cactuses[i].y / 5 + 3.0f < scene->raptor.object.y)
        {
            scene->cactuses[i].y = scene->last_cactus_distance + 15.0f;
            scene->cactuses[i + 1].y = scene->last_cactus_distance + 15.0f;
            scene->last_cactus_distance = scene->cactuses[i].y;
            generate_random_line_cactus(scene->cactuses[i], scene->cactuses[i + 1]);
        }
        float y = scene->cactuses[i].y * -1;
        float pos_x = 0;
        if (scene->cactuses[i].x == 0.6f)
        {
            pos_x = 2.0f;
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
        glScalef(scene->cactuses[i].scale, scene->cactuses[i].scale, scene->cactuses[i].scale);
        glRotatef(scene->cactuses[i].rotation, 1, 0, 0);
        glTranslatef(pos_x, 0, y);
        draw_model(&(scene->cactuses[i].model));
        glPopMatrix();
    }
}
void draw_house(Scene *scene)
{
    if (scene->house.y + 3.0f < scene->raptor.object.y / 2)
    {
        scene->settings.speed += 0.2;
        scene->house.y = scene->house.y + 20.0f;
    }
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->house.texture_id);
    glTranslatef(-2.0f, scene->house.y, 0.1f);
    glRotatef(90, 1, 0, 0);
    glRotatef(180, 0, 1, 0);
    glScalef(scene->house.scale, scene->house.scale, scene->house.scale);
    draw_model(&(scene->house.model));
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
    glVertex3d(-2.5, 1.5, -3);
    glTexCoord2f(1, 0);
    glVertex3d(2.5, 1.5, -3);
    glTexCoord2f(1, 1);
    glVertex3d(2.5, -1.5, -3);
    glTexCoord2f(0, 1);
    glVertex3d(-2.5, -1.5, -3);
    glEnd();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_FOG);
}
void game_over(GLuint texture)
{
    glDisable(GL_FOG);
    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3d(-2.5, 1.5, -3);
    glTexCoord2f(1, 0);
    glVertex3d(2.5, 1.5, -3);
    glTexCoord2f(1, 1);
    glVertex3d(2.5, -1.5, -3);
    glTexCoord2f(0, 1);
    glVertex3d(-2.5, -1.5, -3);
    glEnd();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_FOG);
}
void draw_desert(const Scene *scene)
{
    glBindTexture(GL_TEXTURE_2D, scene->desert_texture_id);
    glBegin(GL_QUADS);
    glPushMatrix();
    int start = scene->raptor.object.y / 2 - 3;
    int end = scene->raptor.object.y / 2 + 9;
    for (int i = start; i < end; i++)
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
void draw_hearts(GLuint texture, int health)
{
    glDisable(GL_LIGHTING);
    glDisable(GL_FOG);
    glEnable(GL_COLOR_MATERIAL);
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBindTexture(GL_TEXTURE_2D, texture);

    for (int i = 0; i < health; i++)
    {
        glBegin(GL_QUADS);

        glTexCoord2f(0, 0);
        glVertex3d(0.2 / 2 + i / 2.0f, (1.375 / 2.0f) + 0.9f, -3);
        glTexCoord2f(1, 0);
        glVertex3d(1.2 / 2 + i / 2.0f, (1.375 / 2.0f) + 0.9f, -3);
        glTexCoord2f(1, 1);
        glVertex3d(1.2 / 2 + i / 2.0f, (0.625 / 2.0f) + 0.9f, -3);
        glTexCoord2f(0, 1);
        glVertex3d(0.2 / 2 + i / 2.0f, (0.625 / 2.0f) + 0.9f, -3);
        glEnd();
    }

    glDisable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_FOG);
}