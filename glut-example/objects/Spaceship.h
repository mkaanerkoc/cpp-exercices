#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <GL/freeglut.h>

class Spaceship{
	public:
		Spaceship()
		{

		}
		Spaceship( int xParam, int yParam )
		{

		}
		draw()
		{
			glVertex2f(0.0, 0.0);
        	glVertex2f(0.5, 0.0);
        	glVertex2f(0.5, 0.5);
        	glVertex2f(0.5, 0.5);

		}
	private:
		int x;
		int y;

};


#endif