#include <stdio.h>
#include <windows.h>
#include <gl/glut.h>

using namespace std;

int x1, y1, x2, y2;


void algo_1st() {
    glBegin(GL_POINTS);
    glVertex2i(x1, y1);

	int dx = abs(x2-x1);
	int dy = abs(y2-y1);

	int incx = x2<x1? -1 : 1;
	int incy = y2<y1? -1 : 1;

	int x = x1;
	int y = y1;

    int e = dx>dy? 2*dy-dx : 2*dx-dy;
    int ifst = dx>dy? 2*(dy-dx) : 2*(dx-dy);
    int isec = dx>dy? 2*dy : 2*dx;

    int limit = dx>dy? dx:dy;

    for(int i=0; i<limit; i++) {
        if (e >= 0) {
            if(dx > dy) y += incy;
            if(dx <= dy) x += incx;
            e += ifst;
        }
        else
            e += isec;

        if(dx > dy) x += incx;
        if(dx <= dy) y += incy;

        glVertex2i(x, y);
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


int main(int argc, char **argv)
{
	printf("start (x1, y1): ");
	scanf("%d %d", &x1, &y1);

	printf("end (x2, y2): ");
	scanf("%d %d", &x2, &y2);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(100,100);
	glutCreateWindow("1st Task");
	init();
	glutDisplayFunc(algo_1st);
	glutMainLoop();
}
