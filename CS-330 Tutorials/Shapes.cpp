/*
 * Shapes.cpp
 *
 *  Created on: Nov 4, 2020
 *      Author: 1509742_snhu
 */

#include <GL/freeglut.h> // Include the freeglut header file

/* Implements Display Callback Handler*/
void displayGraphics() {
	/* Specifies the red, green, blue, and alpha values used when the color buffers are cleared. Color is set to Black with full Opacity.*/
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT); // Uses the color buffer and sets the background color

	glBegin(GL_QUADS); // Starting delimiter for Quad
		glColor3f(1.0f, 0.0f, 0.0f); // Sets the vertex Color to Red using floating point values

		/*Sets 4 vertices to form Quad*/
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.5f, 0.0f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.0f, -0.5f);
	glEnd(); // Ending delimiter for Quad

	glBegin(GL_TRIANGLES); // Starting delimiter for Triange primitive
		glColor3f(0.0f, 0.0f, 1.0f); // Sets the vertex Colors to Blue using floating point values

		/*Sets 3 vertices to form the Triangle*/
		glVertex2f(-1.0f, 0.0f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.0f, 0.0f);
	glEnd(); // Ending delimiter for triangle primitive

glFlush(); // Empties all buffers, and executes all issued commands to be accepteed by the rendering engine.

}

/* Main function required for Immediate mode */
int main(int argc, char** argv) {
	glutInit(&argc, argv); //Initializes rge freeglut library
	glutCreateWindow("OpenGL Shapes"); // Crate a window and title
	glutInitWindowSize(1280, 720); // Specifies the window's width & height
	glutInitWindowPosition(0, 0); // Specifies the position of the window's top-left corner
	glutDisplayFunc(displayGraphics); // Sets the display callback for the current window
	glutMainLoop(); // Enters the GLUT event processing loop.
	return 0; // Exits main function
}


