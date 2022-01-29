#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>


void display(float x1, float y1, float x2, float y2) {
    float x = x1;
    float y = y1;
    float dx = x2-x1;
    float dy = y2-y1;
    float m = dy/dx;

    int limit = m<=1? abs(dx) : abs(dy);

    if(m<=1)
        dx = 1;
    else
        dy = 1;

    for(int i=0; i<limit; i++){
        x += dx;
        y += dy;
        glBegin(GL_POINTS);
        glVertex2f(x,y);
    }

    glEnd();
    glFlush();
}


void init(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("line using DDA algorithm");
    init();

    glutDisplayFunc([]() {
        display(100, 100, 400, 100);
        display(400, 100, 400, 400);
        display(100, 400, 400, 400);
        display(100, 100, 100, 400);
    });

    glutMainLoop();
    return 0;
}
