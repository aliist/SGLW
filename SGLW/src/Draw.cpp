#include "Draw.h"

void Draw(HDC Contest)
{
    glClearColor(0.75f, 0.33f, 0.26f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);//start drawing a line loop
    glVertex3f(-1.0f, 0.0f, 0.0f);//left of window
    glVertex3f(0.0f, -1.0f, 0.0f);//bottom of window
    glVertex3f(1.0f, 0.0f, 0.0f);//right of window
    glVertex3f(0.0f, 1.0f, 0.0f);//top of window
    glEnd();//end drawing of line loop
    SwapBuffers(Contest);
};