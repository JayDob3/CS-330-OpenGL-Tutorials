/*
 * TriangleOGL.cpp
 *
 *  Created on: Nov 4, 2020
 *      Author: 1509742_snhu
 */

#include <GL/freeglut.h> // Include the freeglut header file
#include <GL/gl.h>
#include <GL/glut.h>


/* Implements Display Callback Handler*/
void displayGraphics() {
	/*Specify the red, green, blue, and alpha values used when color buffers are cleared. Color is set to Black with full Opacity*/
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT); // Uses the color buffer and sets the background color

	glBegin(GL_TRIANGLES); // Starting delimiter for Triangle primitive

		glColor3f(1.0f, 0.0f, 0.0f); // Sets the vertex color to Red using floating point values
		glVertex2f(-1.0f, 0.0f); // Sets the Red vertex Position on x and y using floating point values

		glColor3f(0.0f, 1.0f, 0.0f); // Sets the vertex color to Green using floating point values
		glVertex2f(0.0f, 1.0f); //Sets the Green vertex Position on x and y using floating point values

		glColor3f(0.0f, 0.0f, 1.0f); // Sets the vertex color to Blue using floating point values
		glVertex2f(1.0f, 0.0f); // Sets the Blue vertex Position on x and y using floating point values

	glEnd(); // Ending delimiter for Triangle primitive

	glFlush(); // Empties all buffers, and executes all issued commands to be accepted by the rendering engine.

}

/*Main function required for Immediate mode */
int main(int argc, char** argv) {
	glutInit(&argc, argv); //Initializes the freeglut library
	glutCreateWindow("OpenGL Triangle"); // Create a window and title
	glutInitWindowSize(1280, 720); // Specifies the window's width & height
	glutInitWindowPosition(0, 0); // Specifies the position of the window's top-left corner
	glutDisplayFunc(displayGraphics); // Sets the display to callback for the current window
	glutMainLoop(); // Enters the GLUT event processing loop.
	return 0; // Exits main function
}


