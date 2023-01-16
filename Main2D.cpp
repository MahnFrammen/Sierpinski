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

//2D Point Class
struct Point {
  GLfloat x, y; // The x and y coordinates of the point
  Point(GLfloat x = 0, GLfloat y = 0): x(x), y(y) {} 
  Point midpoint(Point p) {return Point((x + p.x) / 2.0, (y + p.y) / 2.0);}
};

//Draws a Sierpinski triangle with a fixed number of points.
void display() {

  glClear(GL_COLOR_BUFFER_BIT);

  static Point vertices[] = {Point(0, 0), Point(200, 500), Point(500, 0)};  //The vertices of the triangle

  //Compute and plot 100000 new points
  static Point p = vertices[0];
  glBegin(GL_POINTS);
  for (int k = 0; k < 100000; k++) { 
    p = p.midpoint(vertices[rand() % 3]); //Compute the midpoint
    glVertex2f(p.x, p.y); //Plot the new point
  }
  glEnd();  //Done plotting points
  glFlush();  //Finish rendering
}

//Performs application-specific initialization.
void init() { 

  //Set a deep purple background and draw in a greenish yellow.
  glClearColor(0.25, 0.0, 0.2, 1.0);  //Set the background color
  glColor3f(0.6, 1.0, 0.0); //Set the drawing color

  //Set up the viewing volume
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity();
  glOrtho(0.0, 500.0, 0.0, 500.0, 0.0, 1.0); 
}

//Initializes GLUT, the display mode, and main window
int main(int argc, char** argv) {
  glutInit(&argc, argv);  // Initialize GLUT
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(40, 40);
  glutCreateWindow("Sierpinski Triangle");
  glutDisplayFunc(display);
  init();
  glutMainLoop();
}