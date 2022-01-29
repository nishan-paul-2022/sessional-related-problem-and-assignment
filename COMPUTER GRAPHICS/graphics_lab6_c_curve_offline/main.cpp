#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
#define PI 3.141592654


void c_curve_(float x, float y, float len, float alpha, int n) {
     if(n>0) {
         float offset = (60*PI)/180;
         c_curve_(x,y,len,alpha+offset,n-1);
         x=x+len*cos(alpha+offset);
         y=y+len*sin(alpha+offset);
         c_curve_(x,y,len,alpha-offset,n-1);
     }
     else {
         glBegin(GL_LINES);
         glVertex2d(x,y);
         glVertex2d(x+(len*cos(alpha)),y+(len*sin(alpha)));
         glEnd();
     }
     glFlush();
}


void c_curve(void) {
     float x, y, len, x1, y1, x2, y2, x3, y3, radian, degree = 0;;
     x = 100;
     y = 150;
     len = 50;
     x1=x;
     y1=y;

     radian = (degree*PI)/180;
     c_curve_(x,y,len,radian,1);
     x = x+(len*cos(radian));
     y = y+(len*sin(radian));
     x2=x;
     y2=y;
     degree = 180+108;

     radian = (degree*PI)/180;
     c_curve_(x,y,len,radian,1);
     x = x+(len*cos(radian));
     y = y+(len*sin(radian));
     degree = 216;

     radian = (degree*PI)/180;
     c_curve_(x,y,len,radian,1);
     x = x+(len*cos(radian));
     y = y+(len*sin(radian));
     x3 = x;
     y3 = y;
     degree = 144;

     radian = (degree*PI)/180;
     c_curve_(x,y,len,radian,1);
     x = x+(len*cos(radian));
     y = y+(len*sin(radian));
     degree = degree-72;

     radian = (degree*PI)/180;
     c_curve_(x,y,len,radian,1);
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
     glutInitWindowSize(1000,1000);
     glutInitWindowPosition(100,100);
     glutCreateWindow("lab 6");
     init();
     glEnable(GL_POINT_SMOOTH);
     glutDisplayFunc(c_curve);
     glutMainLoop();
     return 0;
}
