#include <iostream>
#include <GL/freeglut.h>

#include "Warship.h"
#include "Container.h"

using namespace std;


float xOffset = 0;
float yOffset = 0;

/* glut callbacks */
void keyboard( unsigned char key, int x, int y );
void specialInput( int key, int x, int y );
void display();
void run();

int main( int argc, char** argv )
{
	cout<<"Hello world from snake game"<<endl;
	//Container container;
	glutInit( &argc, argv );
	glutInitWindowSize( 800, 600 );
	glutCreateWindow("GLUT Programi");
	glutKeyboardFunc( keyboard );
	glutSpecialFunc( specialInput );
	glutDisplayFunc( display );
	glutIdleFunc( run );
	glutMainLoop();
	return 1;
}

void specialInput( int key, int x, int y )
{
	if( 100 == key )
	{
		xOffset -= 5.0;
	}
	else if( 101 == key )
	{
		yOffset += 5.0;
	}
	else if( 102 == key )
	{
		xOffset += 5.0;
	}
	else if( 103 == key )
	{
		yOffset -= 5.0;
	}
}
void keyboard( unsigned char key, int x, int y )
{
	//cout<<"Key pressed : code "<<static_cast<int>(key)<<endl;
}

void display()
{
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluOrtho2D(0 , 800, 0, 600 );
	glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_POLYGON);
        glVertex2f(200.0 + xOffset, 100.0 + yOffset);
    	glVertex2f(175.0 + xOffset, 25.0 + yOffset);
    	glVertex2f(225.0 + xOffset, 25.0 + yOffset);
    	glVertex2f(200.0 + xOffset, 50.0 + yOffset);
    glEnd();
    glFlush();
}

void run()
{
	glutPostRedisplay();
}