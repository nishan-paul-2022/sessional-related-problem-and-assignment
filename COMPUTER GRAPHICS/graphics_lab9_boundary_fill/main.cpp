#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>

using namespace std;


void BoundaryFill(int x, int y, float* fill_color, float* boundary_color) {
    float color[3];
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color);

    if((color[0] != boundary_color[0] || color[1] != boundary_color[1] || color[2] != boundary_color[2] ) &&
       (color[0] != fill_color[0] || color[1] != fill_color[1] || color[2] != fill_color[2])) {

        glColor3f(fill_color[0], fill_color[1], fill_color[2]);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        BoundaryFill(x + 1, y, fill_color, boundary_color);
        BoundaryFill(x - 1, y, fill_color, boundary_color);
        BoundaryFill(x, y + 1, fill_color, boundary_color);
        BoundaryFill(x, y - 1, fill_color, boundary_color);
    }
}


void polygon() {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(85, 200);
    glVertex2i(215, 280);
    glVertex2i(310, 200);
    glVertex2i(250, 100);
    glVertex2i(200, 150);
    glVertex2i(150, 100);
    glEnd();
    glFlush();
}


void init(void) {
    glClearColor (0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow ("lab 9");
    init();

    glutDisplayFunc([]() {
        polygon();
        float boundary[] = {1.0, 0.0, 0.0};
        float fillcolor[] = {1.0, 0, 0};
        BoundaryFill(200, 200, fillcolor, boundary);
    });

    glutMainLoop();
    return 0;
}
