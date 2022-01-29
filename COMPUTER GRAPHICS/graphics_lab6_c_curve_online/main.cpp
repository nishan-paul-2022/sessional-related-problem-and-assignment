#include<bits/stdc++.h>
#include<windows.h>
#include<GL/glut.h>

using namespace std;

int n;


void _c_curve(int n, float x, float y, float len, float alpha) {
    if(n>0) {
        len = len/sqrt(2.0);
        _c_curve(n-1, x, y, len, alpha+45);
        x = x + (len*cos(alpha+45));
        y = y + (len*sin(alpha+45));
        _c_curve(n-1, x, y, len, alpha-45);
    }
    else {
        glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x+(len*cos(alpha)), y+(len*sin(alpha)));
        glEnd();
    }
}


void c_curve() {
    float x = 0, y = 0, len = 100, alpha = 90;
    _c_curve(n, x, y, len, alpha);
    glFlush();
}


void init(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}


int main(int argc, char** argv)
{
    cin >> n;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("lab 7");
	init();
    glutDisplayFunc(c_curve);
    glutMainLoop();

    return 0;
}
