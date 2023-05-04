#include "game.h"

void generate_random_cactus(GameObject *cactuses)
{
    float distance = 15.0;
    srand(time(NULL));
    for (int i = 0; i < 12; i += 2)
    {
        int r = (rand() % 3) + 1;
        if (r == 1)
            cactuses[i].x = 0.6;
        else if (r == 2)
            cactuses[i].x = 1.8;
        else if (r == 3)
            cactuses[i].x = 1.2;
        r = (rand() % 3) + 1;
        if (r == 1)
            cactuses[i + 1].x = 0.6;
        else if (r == 2)
            cactuses[i + 1].x = 1.8;
        else if (r == 3)
            cactuses[i + 1].x = 1.2;

        cactuses[i].y = distance;
        cactuses[i + 1].y = distance;
        distance += 15.0f;
    }
}
void generate_random_line_cactus(GameObject *cactus1, GameObject *cactus2)
{
    srand(time(NULL));
    for (int i = 0; i < 12; i += 2)
    {
        int r = (rand() % 3) + 1;
        if (r == 1)
            cactus1->x = 0.6;
        else if (r == 2)
            cactus1->x = 1.8;
        else if (r == 3)
            cactus1->x = 1.2;
        r = (rand() % 3) + 1;
        if (r == 1)
            cactus2->x = 0.6;
        else if (r == 2)
            cactus2->x = 1.8;
        else if (r == 3)
            cactus2->x = 1.2;
    }
}
void init_cactuses(GameObject *cactuses)
{
    Model model;
    load_model(&(model), "assets/models/cactus.obj");
    GLuint texture_id = load_texture("assets/textures/cactus.jpg");
    for (int i = 0; i < 12; i++)
    {
        cactuses[i].model = model;
        cactuses[i].texture_id = texture_id;
        cactuses[i].scale = 0.1;
        cactuses[i].rotation = 90.0;
    }
}
void init_material(Material *material)
{
    material->ambient.red = 0.0;
    material->ambient.green = 0.0;
    material->ambient.blue = 0.0;

    material->diffuse.red = 1.0;
    material->diffuse.green = 1.0;
    material->diffuse.blue = 1.0;

    material->specular.red = 0.0;
    material->specular.green = 0.0;
    material->specular.blue = 0.0;
    material->shininess = 0.0;
}