Zach Pedersen
CST-310
Prof Citro
15 January 2023

My entry for Project 1 - Sierpinski Triangle of CST-310

This assignment submission has 3 programs. They are the TestOpenGL, Main2D and Main3D. TestOpenGL is a test script for OpenGL, and the next 2 are 2D and 3D representations of the Sierpinski Triangle. 

To run these programs:

- Make sure you are running Linux on either a virtual machine or a local server
- Install GCC or G++ on your Linux machine. 
      (Run gcc --version or g++ --version)
- Make sure to install OpenGL on your machine:
        - sudo apt-get update
        - sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev

Once this is complete, you can run the programs by using these commands:

g++ TestOpenGl.cpp -o TestOpenGl -lglut -lGLU -lGL
g++ Main2D.cpp -o Main2D -lglut -lGLU -lGL
g++ Main3D.cpp -o Main3D -lglut -lGLU -lGL

./TestOpenGl
./Main2D
./Main3D
