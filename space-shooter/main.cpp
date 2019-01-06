#include <iostream>
#include <GL\glut.h>
#include "SpaceShooterContainer.h"

/* glut callbacks */
void keyboard( unsigned char key, int x, int y );
void specialInput( int key, int x, int y );
void display();
void run();

SpaceShooterContainer gameContainer;

int main( int argc, char** argv )
{
	std::cout<<"Hello world from space shooter game"<<std::endl;
	//Container container;
	glutInit( &argc, argv );
	glutInitWindowSize( 500, 800 );
	glutCreateWindow("Space Shooter");
	glutKeyboardFunc( keyboard );
	glutSpecialFunc( specialInput );
	glutDisplayFunc( display );
	glutIdleFunc( run );
	glutMainLoop();
	return 1;
}


void specialInput( int key, int x, int y )
{
	//std::cout<<"specialInput callback"<<static_cast<int>(key)<<" "<<x<<" "<<y<<std::endl;
	gameContainer.handleUserInput( key , 0 );
}
void keyboard( unsigned char key, int x, int y )
{
	//std::cout<<"Keyboard callback"<<static_cast<int>(key)<<" "<<x<<" "<<y<<std::endl;
	gameContainer.handleUserInput( key , 0 );
}

void display()
{
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluOrtho2D(0 , 500, 0, 800 );
	glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_POLYGON);
    gameContainer.draw();
    glEnd();
   

    glFlush();
}

void run()
{
	glutPostRedisplay();
	gameContainer.update();
}