/*
 * Cube.cpp
 *
 *  Created on: Nov 4, 2020
 *      Author: 1509742_snhu
 */

#include <GL/glut.h> // Include the freeglut header file

/* Depth and tessellation settings */
void applyDepthSettings() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to Black and Opaque
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

/* Implements Display Callback Handler*/
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW); // Activates the Model-View matrix

	glLoadIdentity(); // Reset the model-view matrix
	glTranslatef(-0.0f, 0.0f, -8.0f); // Move model to the center of the world with a z depth of -7
	glRotatef(45.0f, 0.4f, -1.0f, -0.1f); // Rotate the model on x, y, and z
	// glRotatef(150.0f, 0.0f, 1.0f, 0.0f); // Rotate model to see the left and back face of the cube
	// glRotatef(150.0f, 0.0f, 1.0f, -0.4f); // Rotate model to see the bottom face of the cube

	/* Creates the Cube*/
	glBegin(GL_QUADS);

		// Set Front face color (Red) and vertex coordinates
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);

		// Set Right face color (Green) and vertex coordinates
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);

		// Set Top face color (Blue) and vertex coordinates
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);

		// Set Left face color (Yellow) and vertex coordinates
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);

		// Set Black face color (Dull Green) and vertex coordinates
		glColor3f(0.0f, 0.5f, 0.4f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);

		// Set Bottom face color (Grey) and vertex coordinates
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);

	glEnd(); // Ending delimiter for Cube primitive

	glutSwapBuffers(); // Swap front and back from buffers (similar to glFlush)

}

void reshape(GLsizei width, GLsizei height) {
	if (height == 0) height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewpoint
	glMatrixMode(GL_PROJECTION); // Create a Projection Matrix
	glLoadIdentity(); // Reset Projection Matrix

	// Set perspective projection, fov, aspect, zNear and zFar clipping
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

/* Main function required for Immediate mode */
int main(int argc, char** argv) {
	glutInit(&argc, argv); // Initializes the freeglut library
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(640, 480); // Specifies the windoow's width & height
	glutInitWindowPosition(0, 0); // Specifies the position of the window's top-left corner
	glutCreateWindow("3D Cube"); // Create a window and title
	glutDisplayFunc(display); // Sets the display callback for the screen re-paint event
	glutReshapeFunc(reshape); // Sets the display callback for the window re-size event
	applyDepthSettings(); // Apply depth settings
	glutMainLoop(); // Enter the infinite event-processing loop
	return 0; // Exits main function
}
