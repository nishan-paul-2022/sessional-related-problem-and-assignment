#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
#define PI 3.1416

using namespace std;


void pp(double x, double y, double valuecos, double valuesin) {
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x + valuecos, y + valuesin);
    glEnd();
}


void algo(float x, float y,float len,float alpha, int n) {
    if (n > 0) {
        len = len/3;

        algo(x, y, len, alpha, n - 1);

        x = x + len*cos(alpha*(PI/180));
        y = y + len*sin(alpha*(PI/180));
        algo(x, y, len, alpha - 60, n - 1);

        x = x + len*cos((alpha - 60)*(PI/180));
        y = y + len*sin((alpha - 60)*(PI/180));
        algo(x, y, len, alpha + 60, n - 1);

        x = x + len*cos((alpha + 60)*(PI/180));
        y = y + len*sin((alpha + 60)*(PI/180));
        algo(x, y, len, alpha, n - 1);
    }
    else
        pp(x, y, len*cos(alpha*(PI/180)), len*sin(alpha*(PI/180)));

    glFlush();
}


void init(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("lab 7");
    init();

    glutDisplayFunc([]() {
        algo(0, 0, 60, 180, 2);
    });

    glutMainLoop();

    return 0;
}
