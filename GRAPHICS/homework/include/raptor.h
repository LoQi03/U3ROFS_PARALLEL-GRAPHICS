#ifndef RAPTOR_H
#define RAPTOR_H
#define RAPTOR_H
#include "texture.h"

#include <obj/model.h>
typedef struct Raptor
{
    Model *model;
    float x;
    float y;
    float z;
    float scale;
    GLuint texture_id;

} Raptor;

Raptor init_raptor(float pos_x, float pos_y, float pos_z, float scale);

#endif /* RAPTOR */