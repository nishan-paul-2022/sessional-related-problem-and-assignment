#include <stdio.h>
#include <windows.h>
#include <GL/glut.h>

using namespace std;

int X1, Y1, r;


void algo_2nd() {
	glBegin(GL_POINTS);

	int x = 0, y = r;
	float decision = 1 - r;

	while(y > x) {
		if(decision < 0) {
			x++;
			decision += 2*x+3;
		}
		else {
			y--;
			x++;
			decision += 2*(x-y)+5;
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
    glutCreateWindow("2nd Task");
    init();
    glutDisplayFunc(algo_2nd);
    glutMainLoop();
}

