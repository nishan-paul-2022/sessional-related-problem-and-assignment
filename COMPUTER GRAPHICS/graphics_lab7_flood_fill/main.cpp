#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>

using namespace std;

int width = 700, height = 300;
float backgroundcolor[3] = {0.2,0.4,0.0}, currentcolor[3] = {1.0,0.0,0.0}, floodfill[3] = {0.4,0.0,0.0};


void algo(int x,int y,float previous[3],float updated[3]) {
    float color[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);

    if(color[0]==previous[0] && color[1]==previous[1] && color[2]==previous[2]) {
        glBegin(GL_POINTS);
        glColor3fv(updated);
        glVertex2i(x, y);
        glEnd();
        glFlush();

        algo(x+1,y,previous,updated);
        algo(x-1,y,previous,updated);
        algo(x,y+1,previous,updated);
        algo(x,y-1,previous,updated);
     }
}


void onClick(int button, int state, int x, int y) {
     if(button==GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
         int xi = x;
         int yi = height-y;
         algo(xi,yi,currentcolor,floodfill);
     }
}


void rectangle(int x1, int y1, int x2, int y2) {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(x1, y1);
    glVertex2i(x1, y2);
    glVertex2i(x2, y2);
    glVertex2i(x2, y1);
    glEnd();
    glFlush();
}


void display() {
    glClearColor(0.2, 0.4,0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    rectangle(100,200,150,100);
    glFlush();
}


void init(void) {
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,(GLdouble)width,0.0,(GLdouble)height);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("lab 7");

    glutDisplayFunc([]() {
        glClearColor(0.2, 0.4,0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        rectangle(100,200,150,100);
        glFlush();
    });

    init();
    glutMouseFunc(onClick);
    glutMainLoop();

    return 0;
}
