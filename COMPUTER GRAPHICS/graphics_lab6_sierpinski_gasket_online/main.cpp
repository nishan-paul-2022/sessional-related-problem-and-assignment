#include<bits/stdc++.h>
#include<windows.h>
#include<GL/glut.h>

using namespace std;

int n;
float a, b, c, d, e, f;


void pp(float x, float y, float x1, float y1, float x2, float y2) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}


int algo_gasket(int n, float x1, float y1, float x2, float y2, float x3, float y3) {
    if(n>0){
        float x12,y12,x23,y23,x31,y31;
        x12=(x1+x2)/2;y12=(y1+y2)/2;
        x23=(x2+x3)/2;y23=(y2+y3)/2;
        x31=(x3+x1)/2;y31=(y3+y1)/2;

        algo_gasket(n-1, x1, y1, x12, y12, x31, y31);
        algo_gasket(n-1, x12, y12, x2, y2, x23, y23);
        algo_gasket(n-1, x31, y31, x23, y23, x3, y3);
    }
    else
        pp(x1, y1, x2, y2, x3, y3);
}


void init(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}


int main (int argc, char **argv)
{
//    cin >> a >> b >> c >> d >> e >> f;
    cin >> n;
    a = 50, b = 100;
    c = 100, d = 100;
    e = 50, f = 25;

	glutInit(&argc,argv);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("lab 7");
	init();

    glutDisplayFunc([]() {
        algo_gasket(n, a, b, c, d, e, f);
        glFlush();
    });

    glutMainLoop();
}
