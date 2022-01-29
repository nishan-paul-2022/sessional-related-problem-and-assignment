#include <windows.h>
#include <GL/glut.h>
#include<iostream>

using namespace std;

int a, b;
int center_x, center_y;


void algo_ellipse_(int x, int y) {
    glVertex2i(center_x + x, center_y + y);
    glVertex2i(center_x - x, center_y + y);
    glVertex2i(center_x + x, center_y - y);
    glVertex2i(center_x - x, center_y - y);
}


void algo_ellipse() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);

    glBegin(GL_POINTS);

    float x = 0;
    float y = b;
    float p = b*b - (a*a*b) + (a*a*0.25) ;

    float dx = 0;
    float dy = a*a*2*b;

    while(dx < dy) {
        algo_ellipse_(x, y);

        x++;
        dx += (b*b*2);

        if(p < 0)
            p = p + dx + (b*b);
        else {
            y--;
            dy -=  (a*a*2);
            p += dx - dy +(b*b);
        }
    }

    float p2 = (b*b*(x + 0.5)*(x + 0.5)) + (a*a*(y - 1)*(y - 1)) - (a*a*b*b);

    while(y > 0) {
        algo_ellipse_(x, y);
        y--;
        dy -= (a*a*2);

        if(p2 >= 0)
            p2 -= dy + (a*a);
        else {
            x++;
            dx += (2*b*b);
            p2 += dx - dy + (a*a);
        }
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
    printf("center-x, center-y, major-axis, minor-axis: ");
    scanf("%d %d %d %d", &center_x, &center_y, &a, &b);

	glutInit(&argc,argv);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("lab 5");
	init();
    glutDisplayFunc(algo_ellipse);
    glutMainLoop();

}
