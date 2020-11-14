/*
 * Polygon.cpp
 *
 *  Created on: Nov 4, 2020
 *      Author: 1509742_snhu
 */

#include <GL/freeglut.h> // Include the freeglut header file

/* Implements Display Callback Handler*/
void displayGraphics() {

	/*Specify the red, green, blue, and alpha values used when color buffers are cleared. Color is set to Black with full Opacity*/
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT); // Uses the color buffer and sets the background color

	glBegin(GL_POLYGON); // Starting delimiter for Quad primitive

		glColor3f(0.0f, 1.0f, 0.5f); // Sets the vertex color to Red using floating point values

		/* Sets 5 vertices to form the Polygon*/
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.0f, 1.0f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(-0.5f, -0.5f);

	glEnd(); // Ending delimiter for Polygon primitive

	glFlush(); // Empties all buffers, and executes all issued commands to be accepted by the rendering engine.

}

/*Main function required for Immediate mode */
int main(int argc, char** argv) {
	glutInit(&argc, argv); //Initializes the freeglut library
	glutCreateWindow("OpenGL Polygon"); // Create a window and title
	glutInitWindowSize(1280, 720); // Specifies the window's width & height
	glutInitWindowPosition(0, 0); // Specifies the position of the window's top-left corner
	glutDisplayFunc(displayGraphics); // Sets the display to callback for the current window
	glutMainLoop(); // Enters the GLUT event processing loop.
	return 0; // Exits main function
}


