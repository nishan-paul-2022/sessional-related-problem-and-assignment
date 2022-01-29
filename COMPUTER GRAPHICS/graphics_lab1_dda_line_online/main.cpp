#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<GL/glut.h>


int x1, y1, x2, y2;


void display(void) {
    int dx = x2-x1;
    int dy = y2-y1;
    float m = dy/dx;
    float b = y1-m*x1;

    int x = dx>0==0? x1:x2;
    int y = dx>0==0? y1:y2;
    int limit = dx>0==0? x2:x1;

    glBegin(GL_POINTS);
    glVertex2i(x,y);

    for(int k=0; k<limit; k++) {
        x++;
        y = m*x + b;
        glVertex2i(int(x),int(y));
    }

    glEnd();
    glFlush();
}


void init(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
}


int main(int argc, char** argv)
{
    printf("Enter x1, y1: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter x2, y2: ");
    scanf("%d %d", &x2, &y2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(100,100);
    glutCreateWindow("");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
