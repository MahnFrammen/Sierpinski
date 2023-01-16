//Zach Pedersen
//This is my work
//CST-310
//Prof Citro

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cstdlib>

//3D point class
struct Point {
  GLfloat x, y, z;  // The x, y, and z coordinates of the point
  Point(GLfloat x, GLfloat y, GLfloat z): x(x), y(y), z(z) {} 
  Point midpoint(Point p) {return Point((x+p.x)/2, (y+p.y)/2, (z+p.z)/2);}  
};

//Handles reshape requests
void reshape(GLint w, GLint h) {  
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);  //Set up a projection
  glLoadIdentity(); 
  gluPerspective(100.0, GLfloat(w)/GLfloat(h), 10.0, 1500.0); 
}

//Handles display requests
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clear the screen
}


void generateMorePoints() {
  //Defining 4 vertices
  static Point vertices[4] = {  //The vertices of the tetrahedron
    Point(-250, -225, -200),  
    Point(-150, -225, -700),  
    Point(250, -225, -275), 
    Point(0, 450, -500) 
  };
  static Point lastPoint = vertices[0];

  //Code to draw next 500 points
  glBegin(GL_POINTS); 
  for (int i = 0; i <= 500; i++) {  
    lastPoint = lastPoint.midpoint(vertices[rand() % 4]); //Pick a random vertex
    GLfloat intensity = (700 + lastPoint.z) / 500.0;  //Compute the intensity
    glColor3f(intensity, intensity, 0.25);  //Set the color
    glVertex3f(lastPoint.x, lastPoint.y, lastPoint.z);
  }
  glEnd();  
  glFlush();  
}

//Performs application-specific initialization.
void init() {
  glEnable(GL_DEPTH_TEST);  //Enable depth buffering
}

//Initializes GLUT, the display mode, and main window
int main(int argc, char** argv) { 
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Sierpinski Tetrahedron");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(generateMorePoints);
  init();
  glutMainLoop();
}