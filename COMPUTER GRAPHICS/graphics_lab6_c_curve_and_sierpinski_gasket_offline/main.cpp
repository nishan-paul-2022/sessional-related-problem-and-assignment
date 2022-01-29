#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
#define PI 3.141592654


float width=500, height=500;


void gasket(float x1,float y1,float x2,float y2,float x3,float y3, int n) {
     float x12,y12,x13,y13,x23,y23;
     if(n>0) {
         x12=(x1+x2)/2;
         y12=(y1+y2)/2;
         x13=(x1+x3)/2;
         y13=(y1+y3)/2;
         x23=(x2+x3)/2;
         y23=(y2+y3)/2;
         gasket(x1,y1,x12,y12,x13,y13,n-1);
         gasket(x12,y12,x2,y2,x23,y23,n-1);
         gasket(x13,y13,x23,y23,x3,y3,n-1);
     }
     else {
         glBegin(GL_TRIANGLES);
         glVertex2f(x1,y1);
         glVertex2f(x2,y2);
         glVertex2f(x3,y3);
         glEnd();
     }
     glFlush();
}


void c_curve(float x, float y, float len, float alpha, int n) {
     if(n>0) {
         float offset = (60*PI)/180;
         c_curve(x,y,len,alpha+offset,n-1);
         x=x+len*cos(alpha+offset);
         y=y+len*sin(alpha+offset);
         c_curve(x,y,len,alpha-offset,n-1);
     }
     else {
         glBegin(GL_LINES);
         glVertex2d(x,y);
         glVertex2d(x+(len*cos(alpha)),y+(len*sin(alpha)));
         glEnd();
     }
     glFlush();
}


void display(void) {
     float x, y, len, x1, y1, x2, y2, x3, y3, radian, degree = 0;;
     x = -25;
     y = 25;
     len = 50;
     x1=x;
     y1=y;

     radian = (degree*PI)/180;
     c_curve(x,y,len,radian,1);
     x = x+(len*cos(radian));
     y = y+(len*sin(radian));
     x2=x;
     y2=y;
     degree = 180+108;

     radian = (degree*PI)/180;
     c_curve(x,y,len,radian,1);
     x = x+(len*cos(radian));
     y = y+(len*sin(radian));
     degree = 216;

     radian = (degree*PI)/180;
     c_curve(x,y,len,radian,1);
     x = x+(len*cos(radian));
     y = y+(len*sin(radian));
     x3 = x;
     y3 = y;
     degree = 144;

     radian = (degree*PI)/180;
     c_curve(x,y,len,radian,1);
     x = x+(len*cos(radian));
     y = y+(len*sin(radian));
     degree = degree-72;

     radian = (degree*PI)/180;
     c_curve(x,y,len,radian,1);

     gasket(x1, y1, x2, y2, x3, y3, 1);
}


void init(void) {
     glClear(GL_COLOR_BUFFER_BIT);
     glClearColor(0,0,0,0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-100,100,-100,100);
}


int main(int argc, char** argv)
{
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(width,height);
     glutInitWindowPosition(100,100);
     glutCreateWindow("lab 7");
     init();
     glEnable(GL_POINT_SMOOTH);
     glutDisplayFunc(display);
     glutMainLoop();
     return 0;
}
