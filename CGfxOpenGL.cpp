#include "CGfxOpenGL.h"

CGfxOpenGL::CGfxOpenGL() {

}

CGfxOpenGL::~CGfxOpenGL() {

}

bool CGfxOpenGL::Initialize() {
	// Clear to black background
	glClearColor(0.0, 0.0, 0.0, 0.0);
	angle = 0.0f;
	return true;
}

bool CGfxOpenGL::Shutdown() {
	return true;
}

void CGfxOpenGL::SetupProjection(int width, int height) {
	if(height == 0)
		height = -1; // Avoid division by 0

	// Resetting the viewport to the specifed dimensions
	glViewport(0,0,width,height); 

	// Set projection matrix to current matrix
	glMatrixMode(GL_PROJECTION); 
	
	// Reset projection matrix
	glLoadIdentity(); 
	
	// Calculate aspect ratio of window
	gluPerspective(52.0f, (GLfloat)width/(GLfloat)height,1.0f,1000.0f);

	// Set modelview matrix
	glMatrixMode(GL_MODELVIEW);

	// Reset modelview matrix
	glLoadIdentity();

	windowWidth = width;
	windowHeight = height;
}

void CGfxOpenGL::Prepare(float dt) {
	angle += 0.1f;
}

void CreateNewCube(float xOrigin, float yOrigin, float zOrigin) {

}


void CGfxOpenGL::Render() {

	// Clear screen and buffer bit
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	// Move back 5 units and rotate about all 3 axes
	glTranslatef(0.0,0.0,-5.0f);
	glRotatef(angle,1.0f,0.0f,0.0f);
	glRotatef(angle,0.0f,1.0f,0.0f);
	glRotatef(angle,0.0f,0.0f,1.0f);

	// Red color
	glColor3f(1.0f,0.0f,0.0f);

	// Face xy when z = 0
	glBegin(GL_QUADS);
		glVertex3f(1.0f,0.0f,0.0f);		
		glVertex3f(1.0f,1.0f,0.0f);
		glVertex3f(0.0f,1.0f,0.0f);
		glVertex3f(0.0f,0.0f,0.0f);

	glEnd();

	// Green color
	glColor3f(0.0f,1.0f,0.0f);

	// Face xy when z=1
	glBegin(GL_QUADS);
		glVertex3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0f,1.0f,1.0f);
		glVertex3f(1.0f,1.0f,1.0f);
		glVertex3f(1.0f,0.0f,1.0f);		
	glEnd();

	// Blue color
	glColor3f(0.0f,0.0f,1.0f);

	// Face when y = 1
	glBegin(GL_QUADS);
		glVertex3f(1.0f,0.0f,1.0f);
		glVertex3f(1.0f,0.0f,0.0f);
		glVertex3f(1.0f,1.0f,0.0f);		
		glVertex3f(1.0f,1.0f,1.0f);
	glEnd();

	// Brown color
	glColor3f(0.7f,0.2f,0.0f);

	// Face parallel to y
	glBegin(GL_QUADS);
		glVertex3f(1.0f,0.0f,1.0f);
		glVertex3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0f,0.0f,0.0f);		
		glVertex3f(1.0f,0.0f,0.0f);
	glEnd();

	// White color
	glColor3f(1.0f,1.0f,1.0f);

	// Face when y = 1
	glBegin(GL_QUADS);
		glVertex3f(0.0f,1.0f,0.0f);		
		glVertex3f(1.0f,1.0f,0.0f);		
		glVertex3f(1.0f,1.0f,1.0f);		
		glVertex3f(0.0f,1.0f,1.0f);			
	glEnd();
	
	// Orange color
	glColor3f(1.0f,0.5f,0.0f);

	// Face when y = 0
	glBegin(GL_QUADS);
		glVertex3f(1.0f,0.0f,0.0f);		
		glVertex3f(0.0f,0.0f,0.0f);		
		glVertex3f(0.0f,0.0f,1.0f);		
		glVertex3f(1.0f,0.0f,1.0f);			
	glEnd();

	// Face xy when z = 0
	glBegin(GL_QUADS);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,1.0f,0.0f);
		glVertex3f(1.0f,1.0f,0.0f);
		glVertex3f(1.0f,0.0f,0.0f);		
	glEnd();

	// Green color
	glColor3f(0.0f,1.0f,0.0f);

	// Face xy when z=1
	glBegin(GL_QUADS);
		glVertex3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0f,1.0f,1.0f);
		glVertex3f(1.0f,1.0f,1.0f);
		glVertex3f(1.0f,0.0f,1.0f);		
	glEnd();

	// Blue color
	glColor3f(0.0f,0.0f,1.0f);

	// Face when y = 1
	glBegin(GL_QUADS);
		glVertex3f(1.0f,0.0f,1.0f);
		glVertex3f(1.0f,0.0f,0.0f);
		glVertex3f(1.0f,1.0f,0.0f);		
		glVertex3f(1.0f,1.0f,1.0f);
	glEnd();

	// Brown color
	glColor3f(0.7f,0.2f,0.0f);

	// Face parallel to y
	glBegin(GL_QUADS);
		glVertex3f(1.0f,0.0f,1.0f);
		glVertex3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0f,0.0f,0.0f);		
		glVertex3f(1.0f,0.0f,0.0f);
	glEnd();

	// White color
	glColor3f(1.0f,1.0f,1.0f);

	// Face when y = 1
	glBegin(GL_QUADS);
		glVertex3f(0.0f,1.0f,0.0f);		
		glVertex3f(1.0f,1.0f,0.0f);		
		glVertex3f(1.0f,1.0f,1.0f);		
		glVertex3f(0.0f,1.0f,1.0f);			
	glEnd();
	
	// Orange color
	glColor3f(1.0f,0.5f,0.0f);

	// Face when y = 0
	glBegin(GL_QUADS);
		glVertex3f(1.0f,0.0f,0.0f);		
		glVertex3f(0.0f,0.0f,0.0f);		
		glVertex3f(0.0f,0.0f,1.0f);		
		glVertex3f(1.0f,0.0f,1.0f);			
	glEnd();
}
