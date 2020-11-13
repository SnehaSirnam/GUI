

#include <QtGui/QtGui>
#include <QtOpenGL/QtOpenGL>
#include <math.h>
#include "globj.h"

GLobj::GLobj(QWidget *parent)
    : QGLWidget(parent)
{

}

GLobj::~GLobj()
{

}

//Initialize the GL settings
void GLobj::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

//Set up the viewport based on the screen dimentions
//Function is called implicitly by initializeGL and when screen is resized
void GLobj::resizeGL( int w, int h )
{
    //algorithm to keep scene "square" (preserve aspect ratio)
    //even if screen is streached
    if(w>h)
        glViewport((w-h)/2, 0, h, h);
    else
        glViewport(0, (h-w)/2, w, w);

    //setup the projection and switch to model view for transformations
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //implicit call to paintGL after resized
}
void GLobj::draw()
{
 glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
            glLoadIdentity();
//            glTranslatef(0.0f,0.0f,-1.0f); //move along z-axis
            glRotatef(20.0,0.0,1.0,0.0); //rotate 30 degress around y-axis
            glRotatef(10.0,1.0,0.0,0.0); //rotate 15 degress around x-axis

                 
     glBegin( GL_QUADS );                 /* Draw A Cube                      */
      glColor3f(   1.0f,  1.0f,  1.0f ); 
      glVertex3f(  0.1f,  0.1f, -0.1f ); 
      glVertex3f( -0.1f,  0.1f, -0.1f ); 
      glVertex3f( -0.1f,  0.1f,  0.1f ); 
      glVertex3f(  0.1f,  0.1f,  0.1f ); 


      glColor3f(   0.0f,  0.5f,  0.0f ); 
      glVertex3f(  0.1f,  0.1f,  0.1f ); 
      glVertex3f( -0.1f,  0.1f,  0.1f ); 
      glVertex3f( -0.1f, -0.1f,  0.1f ); 
      glVertex3f(  0.1f, -0.1f,  0.1f ); 


      glColor3f(   1.0f,  1.0f,  0.0f );
      glVertex3f( -0.1f,  0.1f,  0.1f ); 
      glVertex3f( -0.1f,  0.1f, -0.1f ); 
      glVertex3f( -0.1f, -0.1f, -0.1f ); 
      glVertex3f( -0.1f, -0.1f,  0.1f ); 
    glEnd( );                            

    }
void GLobj::ngon(int n)
{
float degree, vertx, verty, rotate, degToRad;
rotate = 360.0/n;//Vertex rotation increment
degree = rotate/2 + 180;//Current degree of vertex (starts rotated to make object upright)
degToRad = 180/3.14159; //Conversion factor from degrees to radians
glLineWidth(4.0);
glBegin(GL_POLYGON);
for(int i = 0; i < n; i++, degree += rotate) 
{
vertx = 0.1 * sin(degree/degToRad); //next vertex's x
verty = 0.1 * sin((90 - degree)/degToRad); //next
if(n==35)
glVertex3f(vertx+0.6, verty+0.5,-0.2); 
if(n==5)
glVertex3f(vertx-0.4, verty-0.3,-0.3); 
if(n==8)
glVertex3f(vertx-0.5, verty+0.1, -0.3); 
if(n==6)
glVertex3f(vertx-0.5, verty+0.5,-1.0); 
if(n==7)
glVertex3f(vertx-0.3, verty+0.2,-1.0); 
}
glEnd();
}

//Paints the GL scene
void GLobj::paintGL()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

 //circle
glColor3f (0.0, 1.0, 0.0);
ngon(35); 
//pentagon
glColor3f (0.0, 0.0, 1.0);
ngon(5); 
//Octagon
glColor3f (0.0, 1.0, 1.0);
ngon(8);
//Hexagon
glColor3f (1.0, 0.5, 0.31);
ngon(6);
//Septagon
glColor3f (1.0, 0.8, 0.31);
ngon(7);
//polygon with 4 sides
glColor3f (1.0, 0.0, 0.0);
 glBegin(GL_QUADS);
     glVertex3f(-0.2f, -0.3f, 0.4f);
     glVertex3f(0.2f, -0.3f, 0.4f);
     glVertex3f(0.2f,  -0.2f, 0.4f);
glVertex3f(-0.2f,  -0.1f, 0.4f);
    glEnd();
//Triangle
glColor3f (1.0, 0.0, 1.0);
glBegin(GL_TRIANGLES);
glVertex3f(0.1f, -0.1f, 0.4f);
     glVertex3f(0.3f, -0.1f, 0.4f);
     glVertex3f(0.3f,  0.1f, 0.4f);
glEnd();
//Line
glColor3f (1.0, 1.0, 1.0);
glLineWidth(4.0);
glBegin(GL_LINES);
    glVertex3f(0.8,-0.2,0);
    glVertex3f(0.8, 0,0.1);
glEnd();
//Point
 glColor3f(0.2f, 0.2f, 0.2f); 
glPointSize(4.0);
glBegin(GL_POINTS);
  glVertex3f(0.9, -0.2,0.2); 
  
glEnd();
draw();
    glFlush ();
}




