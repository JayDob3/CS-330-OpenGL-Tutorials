 Emp/*
 * Transform.cpp
 *
 *  Created on: Nov 4, 2020
 *      Author: 1509742_snhu
 */

#include <GL/freeglut.h> // Include the freeglut header file

/* Implements Display Callback Handler*/
void displayGraphics() {
	/* Specifies the red, green, blue, and alpha values used when the color buffers are cleared. Color is set to Black with full Opacity*/
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT); // Uses the color buffer and sets the background color

	glMatrixMode(GL_MODELVIEW); // Required for transforming (translating, rotating, and scaling) graphic objects
	glLoadIdentity(); // Replaces rge current matrix with the identity matrix. i.e resets or refreshes the matrix for the next frame when the window is resized
	glTranslatef(-0.5f, 0.0f, 0.0f); // Translate all graphic objects -0.5 in the x axis
	glRotatef(180.0f, 0.0f, 0.0f, 1.0f); // Rotates all graphic objects 180 degrees in the z axis

	glBegin(GL_TRIANGLES); // Starting delimiter for Triangle primitivee
		glColor3f(1.0f, 0.0f, 0.0f); // Sets rge vertex Color to Red using floating point values
		glVertex2f(-0.5f, 0.0f); // Sets the Red vertex Positionn on x and y using floating point values

		glColor3f(0.0f, 0.5f, 0.0f); // Sets the vertex Color to Green uaing floating point values
		glVertex2f(0.0f, 0.5f); // Sets the Green vertex POsition on x and y using floating point values

		glColor3f(0.0f, 0.0f, 0.5f); // Sets the vertex Color to Blue using floating point values
		glVertex2f(0.5f, 0.0f); // Sets the Blue vertex Position on x and y floating point values
	glEnd(); // Ending delimiter for Triangle primitive

	glFlush(); // Emptiees all buffers, and eexecute all issued commands to be accepted by the rendering engine.

}

/* Main function required for Immediate mode */
int main(int argc, char** argv) {
	glutInit(&argc, argv); // Initializes the freeglut library
	glutCreateWindow("OpenGL Transform"); // Create a window and title
	glutInitWindowSize(1280, 720); // Specifies the window's width & height
	glutInitWindowPosition(0, 0); // Specifies the position os the window's top-left corner
	glutDisplayFunc(displayGraphics); // Sets the display callback for the current window
	glutMainLoop(); // Enters the GLUT event processing loop.
	return 0; // Exits main function
}


