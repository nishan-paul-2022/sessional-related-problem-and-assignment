#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>

using namespace std;


Koch_curve(float x,float y, float len, float alpha, int n) {
    float b=3.1416/180;
    if (n > 0) {
        len = len/3;
        Koch_curve(x, y, len, alpha, n - 1);
        x = x + len*cos(alpha*b);
        y = y + len*sin(alpha*b);
        Koch_curve(x, y, len, alpha - 60, n - 1);
        x = x + len*cos((alpha - 60)*b);
        y = y + len*sin((alpha- 60)*b);
        Koch_curve(x, y, len, alpha + 60, n - 1);
        x = x + len*cos((alpha + 60)*b);
        y = y + len*sin((alpha + 60)*b);
        Koch_curve(x, y, len, alpha, n - 1);
    }
    else {
        glBegin(GL_LINES);
        glVertex2f(x,y);
        glVertex2f(x + len*cos(alpha*b), y + len*sin(alpha*b));
        glEnd();
    }
    glFlush();
}


void init(void) {
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("lab 8");
    init();

    glutDisplayFunc([]() {
        Koch_curve(-30,-30, 80, 0, 1);
        Koch_curve(50,-30, 80, 120, 1);
        Koch_curve(10,40, 80, 240, 1);
    });

    glutMainLoop();

    return 0;
}
