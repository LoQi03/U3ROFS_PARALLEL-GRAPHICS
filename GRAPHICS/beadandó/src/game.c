#include "game.h"

void generate_random_cactus(GameObject *cactuses)
{
    float distance = 15.0;
    srand(time(NULL));
    for (int i = 0; i <= 20; i += 2)
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
void init_cactuses(GameObject *cactuses)
{
    for (int i = 0; i < 30; i++)
    {
        load_model(&(cactuses[i].model), "assets/models/cactus.obj");
        cactuses[i].texture_id = load_texture("assets/textures/cactus.jpg");
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