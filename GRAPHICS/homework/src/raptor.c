#include "raptor.h"
Raptor init_raptor(float pos_x, float pos_y, float pos_z, float scale)
{
    Raptor raptor;
    load_model(raptor.model, "assets/models/raptor.obj");
    raptor.texture_id = load_texture("assets/textures/raptor.png");
    raptor.x = pos_x;
    raptor.y = pos_y;
    raptor.z = pos_z;
    raptor.scale = scale;

    return raptor;
}