#include "scene.h"

#include <GL/gl.h>

void init_scene(Scene *scene)
{
}

void update_scene(Scene *scene)
{
}

void render_scene(const Scene *scene)
{

    draw_origin();
}

void draw_origin()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0)
            {
                glColor3f(1, 1, 1);
            }
            else
            {
                glColor3f(0, 0, 0);
            }

            glPushMatrix();
            glBegin(GL_QUADS);

            glTexCoord2f(0, 1);
            glVertex3f(i, j, 0);

            glTexCoord2f(1, 1);
            glVertex3f(i + 1, j, 0);

            glTexCoord2f(1, 0);
            glVertex3f(i + 1, j + 1, 0);

            glTexCoord2f(0, 0);
            glVertex3f(i, j + 1, 0);

            glEnd();
            glPopMatrix();
        }
    }
}
