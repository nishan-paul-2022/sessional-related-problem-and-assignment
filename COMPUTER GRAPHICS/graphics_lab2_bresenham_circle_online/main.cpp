#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <GL/glut.h>

using namespace std;

int X1, Y1, r;


void display() {
	glBegin(GL_POINTS);

	int x = 0, y = r;
	float decision = 3 - 2*r;

	while(y > x) {
		if(decision < 0) {
			x++;
			decision += 4*x+6;
		}
		else {
			y--;
			x++;
			decision += 4*(x-y)+10;
		}

		glVertex2i(x+X1, y+Y1);
		glVertex2i(x+X1, -y+Y1);
		glVertex2i(-x+X1, y+Y1);
		glVertex2i(-x+X1, -y+Y1);
		glVertex2i(y+X1, x+Y1);
		glVertex2i(-y+X1, x+Y1);
		glVertex2i(y+X1, -x+Y1);
		glVertex2i(-y+X1, -x+Y1);
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
	printf("coordinate and radius (x, y, r): ");
	scanf("%d %d %d", &X1, &Y1, &r);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(100,100);
    glutCreateWindow("");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
