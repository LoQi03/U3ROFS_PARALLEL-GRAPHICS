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